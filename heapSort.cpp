#pragma comment(linker, "/STACK:10000000")
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
void heapify(int A[], int n, int i) {
    int x = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] > A[x])
        x = l;

    if (r < n && A[r] > A[x])
        x = r;

    if (x != i) {
        swap(A[i], A[x]);

        heapify(A, n, x);
    }
}

void heapSort(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);

        heapify(A, i, 0);
    }
}

int main() {
    int array[500000];
    ifstream file;
    file.open("backsortedData.txt", ios::in);

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

    heapSort(array, N);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << " s" << "\n";

    return 0;
}