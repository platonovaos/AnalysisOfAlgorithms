#include "strFunc.h"

string inputString(const string msg)
{
    cout << msg;

    string inputStr = "";
    cin >> inputStr;
    cout << endl;

    return inputStr;
}

void outputResult(const int res)
{
    if (res != -1) {
        cout << "Index: " << res << endl;
    } else {
        cout << "Position not found\n";
    }

    cout << endl;
}
