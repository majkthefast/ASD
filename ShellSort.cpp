#pragma comment(linker, "/STACK:10000000")
#include  <iostream> 
#include <fstream>
#include <ctime>
using namespace std;

int shellSort(int A[], int N)
{
    for (int gap = N / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < N; i += 1)
        {
            int temp = A[i];

            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                A[j] = A[j - gap];

            A[j] = temp;
        }
    }
    return 0;
}

int main()
{
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

    shellSort(array, N);

    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    cout << "Czas: " << elapsed << " s" << "\n";

    return 0;
}
