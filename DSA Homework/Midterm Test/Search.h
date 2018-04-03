#include <iostream>
#include <cstdlib>
#include <ctime>

int LinearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (x == a[i]) return i;
    return -1;
}

int BinarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (x == a[mid]) return mid;
        x > a[mid] ? left = mid + 1 : left = mid - 1;
    }
    return -1;
}