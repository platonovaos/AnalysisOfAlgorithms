#include "timeMeasure.h"
#include <string.h>
#include <iostream>
using namespace std;

const int timeCode = 5;
const int exitCode = 6;

void menu();
void inputMenu(string &str1, string &str2);
bool isEmptyString(string str1, string str2);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choose = 0;
    while (true) {
        cout << "Choose the option:\n";
        cout << "\tLevenshtein with matrix.................1\n";
        cout << "\tLevenshtein recursive without matrix....2\n";
        cout << "\tLevenshtein recursive with matrix.......3\n";
        cout << "\tDamerau Levenshtein with matrix.........4\n\n";
        cout << "\tTime measurements.......................5\n\n";
        cout << "\tExit....................................6\n";

        cin >> choose;

        if (choose == exitCode) {
            break;
        }

        if (choose == timeCode) {
            timeMeasurment();
            break;
        }

        string str1 = "", str2 = "";
        inputMenu(str1, str2);
        if (isEmptyString(str1, str2)) {
            choose = -1;
        }

        int res = 0;
        switch (choose) {
        case -1:
            res = abs(static_cast<int>(str2.length() - str1.length()));
            break;
        case 1:
            res = LevensteinMatr(str1, str2);
            break;
        case 2:
            res = LevensteinRec(str1, str2);
            break;
        case 3:
            res = LevensteinRecMatr(str1, str2);
            break;
        case 4:
            res = DemLevMatr(str1, str2);
            break;
        }

        cout << "Distance: " << res << endl << endl;
    }
}

void inputMenu(string &str1, string &str2)
{
    cin.ignore(32767, '\n');
    cout << "Input first string: ";
    getline(cin, str1);
    cout << "Input second string: ";
    getline(cin, str2);
}

bool isEmptyString(string str1, string str2)
{
    if (str1 == "" || str2 == "") {
        return true;
    }
    return false;
}
