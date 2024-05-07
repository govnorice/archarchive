#include "Logic.hpp"

vector<string> Logic::parseHTML(const string& htmlContent) {
    vector<string> hrefVector;

    size_t start = htmlContent.find("<pre>");
    size_t end = htmlContent.find("</pre>");
    if (start == string::npos || end == string::npos) {
        throw invalid_argument("Preformatted block not found");
    }

    start += string("<pre>").length();
    while (start < end) {
        start = htmlContent.find("<a href=\"", start);
        if (start == string::npos)
            break;
        start += string("<a href=\"").length();

        size_t href_end = htmlContent.find('\"', start);
        if (href_end == string::npos)
            break;

        string href = htmlContent.substr(start, href_end - start);
        hrefVector.push_back(href); // добавляем найденное значение в вектор

        start = href_end + 1;
    }

    return hrefVector;
}

void Logic::rollback(const string& day, const string& month, const string& year) {
    time_t currentTime = time(nullptr);

    FileManager::copyFile("/etc/pacman.d/mirrorlist", "/etc/pacman.d/mirrorlist_backup_" + to_string(currentTime));
    FileManager::writeFile("/etc/pacman.d/mirrorlist", "Server = https://archive.archlinux.org/repos/" + year + "/" +
            month + "/" + day + "/$repo/os/$arch");

    cout << "Starting a full system rollback..." << endl;

    system("sudo pacman -Syyuu");

    FileManager::copyFile("/etc/pacman.d/mirrorlist_backup_" + to_string(currentTime), "/etc/pacman.d/mirrorlist");
}

void Logic::printVec(const vector<string>& vec, const string& ct) {
    for (const string& str : vec) {
        cout << str << endl;
    }
    cout << ct;
}

vector<string> Logic::search_repos() {
    string s1, s2, s3;
    NetworkClient nc;

    nc.doGet("https://archive.archlinux.org/repos/");

    try {
        Logic::printVec(parseHTML(nc.responseBody()), "Enter year: ");
        cin >> s1;
        if (!all_of(s1.begin(), s1.end(), ::isdigit)) {
            throw invalid_argument("Input is not a valid year (should contain only digits)");
        }

        nc.doGet("https://archive.archlinux.org/repos/" + s1);

        Logic::printVec(parseHTML(nc.responseBody()), "Enter month: ");
        cin >> s2;
        if (!all_of(s2.begin(), s2.end(), ::isdigit)) {
            throw invalid_argument("Input is not a valid month (should contain only digits)");
        }

        nc.doGet("https://archive.archlinux.org/repos/" + s1 + "/" + s2);

        Logic::printVec(parseHTML(nc.responseBody()), "Enter day: ");
        cin >> s3;
        if (!all_of(s3.begin(), s3.end(), ::isdigit)) {
            throw invalid_argument("Input is not a valid day (should contain only digits)");
        }

        return { s1, s2, s3 };
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return {};
}