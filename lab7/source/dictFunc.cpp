#include "dictFunc.h"

string inputString()
{
    cout << "String to search in the dictionary: ";

    string inputStr = "";
    cin >> inputStr;
    cout << endl;

    return inputStr;
}

Dictionary fillDictionary()
{
    string line = "";
    ifstream in(dictFileName);

    struct Dictionary dict;
    for (int i = 0; i < dict.Size; i++) {
        if (in.is_open()) {
            getline(in, line);
            dict.Words[i] = line;
        }
    }

    in.close();

    return dict;
}

void outputResult(int res, string word)
{
    if (res != -1) {
        cout << "Index: " << res << endl;
        cout << "Word: " << word << endl;
    } else {
        cout << "Word not found\n";
    }
    cout << endl;
}
