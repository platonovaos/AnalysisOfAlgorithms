#include "formMatr.h"
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
    cout << "Choose the option:\n" << endl;
    cout << "Multiply matrix.......1" << endl;
    cout << "Measure time..........2\n" << endl;

    cin >> fChoose;

    if (fChoose == 1) {

        Matrix matrA(0, 0), matrB(0, 0);
        formMatr(matrA, matrB);
        cout << endl;

        int choose = 0;
        while (true) {
            cout << "Choose the option:\n";
            cout << "\tVinograd multiplication.............1\n";
            cout << "\tVinograd parallel vectors...........2\n";
            cout << "\tVinograd parallel cycle.............3\n";
            cout << "\tExit................................4\n";

            cin >> choose;

            if (choose == exitCode) {
                break;
            }

            Matrix resMatr;
            switch (choose) {
            case 1:
                resMatr = vinogradMul(matrA, matrB);
                break;
            case 2:
                resMatr = parallelVectors(matrA, matrB, 3);
                break;
            case 3:
                resMatr = parallelCycle(matrA, matrB, 3);
                break;
            }

            resMatr.output("\nResult matrix");
            resMatr.freem();
        }
        matrA.freem();
        matrB.freem();
    }

    if (fChoose == 2) {
        timeMeasurments();
    }
}
