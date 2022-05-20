#pragma comment(linker, "/STACK:10000000")
#include <iostream>
#include <stdio.h>
#include <ostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return (i + 1);
}

void QuickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
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

    QuickSort(array, 0, (N - 1));

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << " s" << "\n";

 

    return 0;
}