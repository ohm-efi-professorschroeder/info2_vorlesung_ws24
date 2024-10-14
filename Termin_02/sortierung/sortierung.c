#include "sortierung.h"

static void tausche(int *zahl1, int *zahl2)
{
    int tmp = *zahl1;
    *zahl1 = *zahl2;
    *zahl2 = tmp;
}

void selectionSort(int array[], int anzahl)
{
    for(int i = 0; i < anzahl - 1; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < anzahl; j++)
        {
            if(array[j] < array[minIdx])
                minIdx = j;
        }
        tausche(&array[i], &array[minIdx]);
    }
}

void merge(int *start, int* mid, int* end)
{
    int *leftStart = start;
    int *leftEnd = mid;
    int *rightStart = mid+1;
    int *rightEnd = end;

    int count = end - start + 1;
    int sorted[count];
    int sortedCount = 0;

    while(leftStart <= leftEnd && rightStart <= rightEnd) {
        if(*leftStart < *rightStart) {
            sorted[sortedCount++] = *leftStart;
            leftStart++;
        }
        else {
            sorted[sortedCount++] = *rightStart;
            rightStart++;
        }
    }
    while(leftStart <= leftEnd) {
        sorted[sortedCount++] = *leftStart;
        leftStart++;
    }
    while(rightStart <= rightEnd) {
        sorted[sortedCount++] = *rightStart;
        rightStart++;
    }

    for(int i = 0; i < count; i++)
        start[i] = sorted[i];
}

void mergeSortRek(int *start, int *end) {
    if(start >= end)
        return;

    int *mid = start + (end - start) / 2;

    mergeSortRek(start, mid);
    mergeSortRek(mid+1, end);
    merge(start, mid, end);
}

void mergeSort(int array[], int anzahl) {
    mergeSortRek(array, array + anzahl - 1);
}