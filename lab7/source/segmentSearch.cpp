#include "segmentSearch.h"

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

int segmentSearch(const Dictionary dict, const string searchStr)
{
    const int numSegments = alphabet.size();
    Segment segmentArray[numSegments];
    defineSegments(segmentArray, numSegments, dict);

    int res = -1;

    for (int i = 0; i < numSegments; i++) {
        if (searchStr[0] == segmentArray[i].Key) {
            res = findInSegment(segmentArray[i], searchStr);
            break;
        }
    }

    freeSegemnts(segmentArray, numSegments);

    return res;
}

void defineSegments(Segment segmentArray[], const int numSegments, const Dictionary dict)
{
    fillKey(segmentArray, numSegments);
    for (int i = 0; i < numSegments; i++) {
        fillSize(segmentArray[i], dict);
        fillSegment(segmentArray[i], dict);
    }
    sortSegments(segmentArray, numSegments);
}

void fillKey(Segment segmentArray[], int numSegments)
{
    for (int i = 0; i < numSegments; i++) {
        segmentArray[i].Key = alphabet[i];
    }
}

void fillSize(Segment& segment, const Dictionary dict)
{
    int sizeSeg = 0;
    for (int i = 0; i < dict.Size; i++) {
        if (segment.Key == (dict.Words[i])[0]) {
            sizeSeg++;
        }
    }
    segment.Size = sizeSeg;
}

void fillSegment(Segment& segment, const Dictionary dict)
{
    string* words = new string[segment.Size];
    int* idx = new int[segment.Size];

    int j = 0;
    for (int i = 0; i < dict.Size; i++) {
        if (segment.Key == (dict.Words[i])[0]) {
            words[j] = dict.Words[i];
            idx[j] = i;
            j++;
        }
    }

    segment.Words = words;
    segment.OriginalIdx = idx;
}

void sortSegments(Segment segmentArray[], const int numSegments)
{
    for (int i = 0; i < numSegments - 1; i++) {
        for (int j = 1; j < numSegments - i; j++) {
            if (segmentArray[j].Size > segmentArray[j - 1].Size) {
                swap(segmentArray[j], segmentArray[j - 1]);
            }
        }
    }
}

int findInSegment(const Segment segment, const string searchStr)
{
    int left = 0, middle = 0, right = segment.Size;
    int res = -1;

    while (left < right) {
        middle = (left + right) / 2;

        string dStr = segment.Words[middle];

        if (searchStr < dStr) {
            right = middle;
        } else {
            if (searchStr == dStr) {
                res = segment.OriginalIdx[middle];
                break;
            } else {
                if (searchStr > dStr) {
                    left = middle + 1;
                }
            }
        }
    }

    return res;
}

void freeSegemnts(Segment segmentArray[], const int numSegments)
{
    for (int i = 0; i < numSegments; i++) {
        delete[] (segmentArray[i]).Words;
        delete[] (segmentArray[i]).OriginalIdx;
    }
}
