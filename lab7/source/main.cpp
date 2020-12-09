#include "timeMeasurments.h"

const int exitCode = 4;

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int fChoose = 0;
    cout << "Choose the option:" << endl << endl;
    cout << "Dictionary search......1" << endl;
    cout << "Measure time...........2" << endl << endl;

    Dictionary dict = fillDictionary();

    cin >> fChoose;
    if (fChoose == 1) {

        string searchStr = inputString();

        int choose = 0;

        while (true) {
            cout << "Choose the option:\n";
            cout << "\tBrute force.............1\n";
            cout << "\tBinary search...........2\n";
            cout << "\tSegment search..........3\n";
            cout << "\tExit....................4\n";

            cin >> choose;

            if (choose == exitCode) {
                break;
            }

            int res = -1;
            switch (choose) {
                case 1:
                    res = bruteForce(dict, searchStr);
                    break;
                case 2:
                    res = binarySearch(dict, searchStr);
                    break;
                case 3:
                    res = segmentSearch(dict, searchStr);
                    break;
            }

            if (res != -1) {
                outputResult(res, dict.Words[res]);
            } else {
                outputResult();
            }
        }
    }

    if (fChoose == 2) {
        timeMeasurments(dict);
    }
}
