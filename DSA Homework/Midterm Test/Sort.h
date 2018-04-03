#include <iostream>
#include <cstdlib>
#include <ctime>

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] > a[j - 1])
				swap(a[j], a[j - 1]);
}

void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > key; j--)
			a[j + 1] = a[j];
		a[j + 1] = key;
	}
}

void BinaryInsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int key = a[i];
		int left = 0, right = i - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] < key) left = mid + 1;
			else right = mid - 1;
		}

		int j;
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[j + 1] = key;
	}
}

void ShakerSort(int a[], int n) {
	int left = 0, right = n - 1;
	int mark;

	while (left < right) {
		for (int i = left; i < right; i++)
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				mark = i;
			}
		right = mark;

		for (int i = right; i > left; i--)
			if (a[i] < a[i - 1]) {
				swap(a[i], a[i - 1]);
				mark = i;
			}
		left = mark;
	}
}

void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int index = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[index])
				index = j;
		swap(a[i], a[index]);
	}
}

void QuickSort(int a[], int left, int right) {
	int low = left, high = right;
	do {
		int pivot = a[(low + high) / 2];
		while (a[low]  < pivot) low++;
		while (a[high] > pivot) high--;
		if (low <= high) swap(a[low++], a[high--]);
	} while (low < high);

	if (low < right) QuickSort(a, low, right);
	if (high > left) QuickSort(a, left, high);
}

void Merge(int a[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = new int[n1];
	int *R = new int[n2];

	for (int i = left, k = 0; k < n1; i++, k++)    L[k] = a[i];
	for (int i = mid + 1, k = 0; k < n2; i++, k++) R[k] = a[i];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] < R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];
	}

	while (i < n1) a[k++] = L[i++];
	while (j < n2) a[k++] = R[j++];
	delete[]L, R;
}

void MergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

void Heapify(int a[], int n, int idx) {
	while (idx < n / 2) {
		int tmp = 2 * idx + 1;
		if (tmp + 1 < n && a[tmp] < a[tmp + 1])
			tmp++;
		if (a[idx] < a[tmp])
			swap(a[idx], a[tmp]);
		idx = tmp;
	}
}

void BuildHeap(int a[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
}

void HeapSort(int a[], int n) {
	BuildHeap(a, n);
	int length = n;

	while (length > 1) {
		swap(a[0], a[--length]);
		Heapify(a, length, 0);
	}
}

void ShellSort(int a[], int n, int h[], int k) {
	for (int step = 0; step < k; step++) {
		int len = h[step];
		for (int i = len; i < n; i++) {
			int key = a[i];
			int j;
			for (j = i - len; j >= 0 && a[j] > key; j -= len)
				a[j + len] = a[j];
			a[j + len] = key;
		}
	}
}