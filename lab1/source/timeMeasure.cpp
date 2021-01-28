#include "timeMeasure.h"
#include "random"
#include "time.h"

const int numRepeats = 100;

string getRandomStr(int len);

void timeMeasurment()
{
    cout << "________________Time_____________" << endl << endl;
    cout << "Len |  L-M  | L-RM | DL-M | L-Rec" << endl;
    cout << "---------------------------------" << endl;
    createStringAndMeasure(2);
    LevRecTime(2);
    cout << "---------------------------------" << endl;

    createStringAndMeasure(5);
    LevRecTime(5);
    cout << "---------------------------------" << endl;

    createStringAndMeasure(10);
    LevRecTime(10);
    cout << "---------------------------------" << endl;

    createStringAndMeasure(50);
    cout << "\n---------------------------------" << endl;
    createStringAndMeasure(100);
    cout << "\n---------------------------------" << endl;
    createStringAndMeasure(200);
    cout << "\n---------------------------------" << endl;
    createStringAndMeasure(300);
    cout << "\n---------------------------------" << endl;
    createStringAndMeasure(400);
    cout << "\n---------------------------------" << endl;
    createStringAndMeasure(500);
    cout << endl << endl;
}

string getRandomStr(int len)
{
    string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<> dist(0, alphabet.size()-1);
    string ret = "";

    for (int i = 0; i < len; i++){
        int random_index = dist(engine); //get index between 0 and possible_characters.size()-1
        ret += alphabet[random_index];
    }
    return ret;
}

void createStringAndMeasure(int len)
{
    string str1 = getRandomStr(len);
    string str2 = getRandomStr(len);
    LenTime(len, str1, str2);
}

void LenTime(int len, string str1, string str2)
{
    cout << setw(3) << len << " |";
    LevMatrTime(str1, str2);
    LevRecTime(str1, str2);
    DemLevMatrTime(str1, str2);
}

void LevMatrTime(string str1, string str2)
{
    clock_t begin = 0, end = 0;
    begin = clock();
    for (int i = 0; i < numRepeats; i++) {
        LevensteinMatr(str1, str2, false);
    }
    end = clock();
    cout << setw(6) << (end - begin) / numRepeats << " |";
}

void LevRecTime(string str1, string str2)
{
    clock_t begin = 0; clock_t end = 0;
    begin = clock();
    for (int i = 0; i < numRepeats; i++) {
        LevensteinRecMatr(str1, str2, false);
    }
    end = clock();
    cout << setw(5) << (end - begin) / numRepeats << " |";
}

void DemLevMatrTime(string str1, string str2)
{
    clock_t begin = 0; clock_t end = 0;
    begin = clock();
    for (int i = 0; i < numRepeats; i++) {
        DemLevMatr(str1, str2, false);
    }
    end = clock();
    cout << setw(5) << (end - begin) / numRepeats << " |";
}

void LevRecTime(int len)
{
    string str1 = getRandomStr(len);
    string str2 = getRandomStr(len);
    clock_t begin = 0, end = 0;
    begin = clock();
    LevensteinRec(str1, str2);
    end = clock();
    cout << setw(5) << (end - begin) / numRepeats << endl;
}
