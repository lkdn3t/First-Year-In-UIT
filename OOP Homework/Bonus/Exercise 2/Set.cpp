#include "Set.h"
#include <iostream>
#include <algorithm>
using namespace std;

//Khởi tạo tập hợp gồm n phần tử từ tập hợp đã có a
void Set::setElements(int n, int *a) {
	size = n;
	ele = new int[size];
	for (int i = 0; i < n; ++i) ele[i] = a[i];
}

//Khởi tạo tập hợp từ số phần tử đã nhập vào
void Set::setElements() {
	int n;
	int *a;

	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i) cin >> a[i];

	setElements(n, a);
	delete[]a;
}

//In số phần tử và các phần tử trong tập hợp
void Set::printSet() {
	for (int i = 0; i < size; ++i)
		cout << ele[i] << " ";
	cout << "\n";
};

//Sắp xếp tập hợp
void Set::sortSet() {
	sort(ele, ele + size);
}

//Tìm tập giao của hai tập hợp (tập giao không chứa các phần tử trùng nhau)
Set	Set::Intersect(Set a) {
	Set ans;
	int n = 0;
	int *t = new int[min(size, a.size)];

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < a.size; ++j)
			if (ele[i] == a.ele[j]) {
				bool flag = true;
				for (int k = 0; k < n; ++k)
					if (t[k] == ele[i]) {
						flag = false;
						break;
					}
				if (flag) t[n++] = ele[i];
				break;
			}

	//Nếu không có phần giao
	if (n == 0) {
		n = 1;
		t[0] = 0;
	}

	ans.setElements(n, t);
	ans.sortSet();

	delete[]t;
	return ans;
};

//Tìm tập hợp của hai tập hợp (tập hợp không chứa các phần tử trùng nhau)
Set Set::Union(Set a) {
	Set ans;
	int n = 0;
	int *t = new int[size + a.size];

	for (int i = 0; i < size; ++i) {
		bool flag = true;
		for (int j = 0; j < n; ++j)
			if (ele[i] == t[j]) {
				flag = false;
				break;
			}
		if (flag) t[n++] = ele[i];
	}

	for (int i = 0; i < a.size; ++i) {
		bool flag = true;
		for (int j = 0; j < n; ++j)
			if (a.ele[i] == t[j]) {
				flag = false;
				break;
			}
		if (flag) t[n++] = a.ele[i];
	}

	//Nếu không có phần hợp
	if (n == 0) {
		n = 1;
		t[0] = 0;
	}

	ans.setElements(n, t);
	ans.sortSet();

	delete[]t;
	return ans;
}