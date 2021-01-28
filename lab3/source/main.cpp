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
    cout << "Sort matrix...........1" << endl;
    cout << "Mesure time...........2" << endl << endl;

    cin >> fChoose;
    if (fChoose == 1) {

        Array arr(0);
        formArray(arr);
        cout << endl;

        int choose = 0;
        while (true) {
            cout << "Choose the option:\n";
            cout << "\tBubble sort.............1\n";
            cout << "\tInsertion sort..........2\n";
            cout << "\tShell sort..............3\n";
            cout << "\tExit....................4\n";

            cin >> choose;

            if (choose == exitCode) {
                break;
            }

            Array arrCopy = copyArray(arr);

            switch (choose) {
            case 1:
                bubbleSort(arrCopy);
                break;
            case 2:
                insertionSort(arrCopy);
                break;
            case 3:
                shellSort(arrCopy);
                break;
            }

            arrCopy.output("\nSorted matrix");
            arrCopy.freem();
        }
        arr.freem();
    }

    if (fChoose == 2) {
        timeMeasurments();
    }
}
