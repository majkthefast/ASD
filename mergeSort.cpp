#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void merge(int array[], int const left, int const mid, int const right) {
    auto const subA = mid - left + 1;
    auto const subB = right - mid;

    auto* A = new int[subA],
        * B = new int[subB];

    for (auto i = 0; i < subA; i++)
        A[i] = array[left + i];
    for (auto j = 0; j < subB; j++)
        B[j] = array[mid + 1 + j];

    auto iA = 0,
        iB = 0;
    int iC = left;

    while (iA < subA && iB < subB) {
        if (A[iA] <= B[iB]) {
            array[iC] = A[iA];
            iA++;
        }
        else {
            array[iC] = B[iB];
            iB++;
        }
        iC++;
    }

    while (iA < subA) {
        array[iC] = A[iA];
        iA++;
        iC++;
    }

    while (iB < subB) {
        array[iC] = B[iB];
        iB++;
        iC++;
    }
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


int main() {
    int array[500000];
    ifstream file;
    file.open("unsortedData.txt", ios::in);

    if (!file.good()) {
        return 0;
    }
    else {
        for (int i = 0; i < 500000; i++)
            file >> array[i];
    }

    file.close();

    int N = sizeof(array) / sizeof(array[0]);

    clock_t start = clock();

    mergeSort(array, 0, (N - 1));

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << " s" << "\n";

    return 0;
}