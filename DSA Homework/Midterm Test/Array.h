#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void RandomArray(int *&a, int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    a = new int[n];

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;
}

void PutArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}