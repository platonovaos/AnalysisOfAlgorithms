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
    cout << "Substring search.......1" << endl;
    cout << "Measure time...........2" << endl << endl;

    cin >> fChoose;
    if (fChoose == 1) {

        /*const string fullStr = "This is a full string";
        const string partStr = "full";
        */

        const string fullStr = inputString("Input full string: ");
        const string partStr = inputString("Input substring: ");

        int choose = 0;

        while (true) {
            cout << "Choose the option:\n";
            cout << "\tStandart search................1\n";
            cout << "\tKnuth-Moris-Pratt search.......2\n";
            cout << "\tBoyer-Moore search.............3\n";
            cout << "\tExit...........................4\n";

            cin >> choose;

            if (choose == exitCode) {
                break;
            }

            int res = -1;
            switch (choose) {
                case 1:
                    res = standartSearch(fullStr, partStr);
                    break;
                case 2:
                    res = kmpSearch(fullStr, partStr);
                    break;
                case 3:
                    res = bmSearch(fullStr, partStr);
                    break;
            }

            outputResult(res);
        }
    }

    if (fChoose == 2) {
        timeMeasurments();
    }
}
