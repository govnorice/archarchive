#include "FileManager.h"

void FileManager::copyFile(const string& source_, const string& dest_) {
    ifstream source(source_, ios::binary);
    ofstream dest(dest_, ios::binary);

    if (!source.is_open()) {
        cerr << "Failed to open the file" << endl;
        return;
    }
    if (!dest.is_open()) {
        cerr << "Failed to open the file" << endl;
        return;
    }

    dest << source.rdbuf();

    source.close();
    dest.close();

    cout << "The file has been copied successfully" << endl;
}

void FileManager::writeFile(const string &filename_, const string &content_) {
    ofstream file(filename_);

    if (!file.is_open()) {
        cerr << "Failed to open the file" << endl;
        return;
    }

    file << content_;

    file.close();

    cout << "The file has been write successfully" << endl;
}
