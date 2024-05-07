#ifndef ARCHARCHIVE_FILEMANAGER_H
#define ARCHARCHIVE_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager {
public:
    static void copyFile(const string& source_, const string& dest_);
    static void writeFile(const string& file_, const string& content_);
};


#endif //ARCHARCHIVE_FILEMANAGER_H
