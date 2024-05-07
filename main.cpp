#include <iostream>
#include <string>

// Modules
#include "modules/Logic.hpp"

using namespace std;

Logic logic;

int main (int argc, char *argv[]) {
    cout << "[ Select a date for rollback (only numbers are allowed) ]\n" << endl;
    vector<string> date = logic.search_repos();
    logic.rollback(date[2], date[1], date[0]);
    return 0;
}