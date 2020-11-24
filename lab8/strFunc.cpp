#include "strFunc.h"

void outputResult(const int res)
{
    if (res != -1) {
        cout << "Index: " << res << endl;
    } else {
        cout << "Word not found\n";
    }

    cout << endl;
}
