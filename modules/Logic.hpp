#ifndef ARCHARCHIVE_LOGIC_HPP
#define ARCHARCHIVE_LOGIC_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <cctype>
#include <stdexcept>
#include <algorithm>

#include "./NetworkClient.h"
#include "./FileManager.h"

using namespace std;

class Logic {
private:
    vector<string> parseHTML(const string& htmlContent);
    void printVec(const vector <string>& vec, const string& ct);
public:
    void rollback(const string& day, const string& month, const string& year);
    vector<string> search_repos();
};


#endif //ARCHARCHIVE_LOGIC_HPP
