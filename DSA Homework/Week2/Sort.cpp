#include "Sort.h"

//Bài 1: Sắp xếp mảng phân số giảm dần bằng BubbleSort
//--------------------------------------------------------
//Hàm so sánh phân số
int SoSanhPS(PhanSo p1, PhanSo p2) {
	double g1 = (double)p1.tu / p1.mau;
	double g2 = (double)p2.tu / p2.mau;
	return g1 == g2 ? 0 : g1 > g2 ? 1 : -1;
}

//Đọc file input gồm mảng phân số
void NhapMangPS(const char *FileName, PhanSo *&ps, int &n) {
	//Mở file và đọc input
	ifstream ifile;
	ifile.open(FileName);
	if (!ifile) {
		cout << "Khong the mo tap tin " << FileName << "!\n";
		return;
	}

	//Đọc số phần tử và mảng phân số
	ifile >> n;
	ps = new PhanSo[n];
	for (int i = 0; i < n; ++i)
		ifile >> ps[i].tu >> ps[i].mau;
	ifile.close();
}

//Xuất file output mảng phân số đã sắp xếp
void XuatMangPS(const char* FileName, PhanSo* ps, int n) {
	//Mở file và xuất mảng phân ssố
	ofstream ofile;
	ofile.open(FileName);
	if (!ofile) {
		cout << "Khong the mo tap tin " << FileName << "!\n";
		return;
	}

	//Xuất mảng phân số đã sắp xếp
	for (int i = 0; i < n; ++i)
		ofile << ps[i].tu << " " << ps[i].mau << "\n";
	ofile.close();
}

//Dùng BubbleSort để sắp xếp mảng phân số giảm dần
void BubbleSort(PhanSo *ps, int n) {
	for (int i = 0; i < n - 1; ++i)
		for (int j = n - 1; j > i; --j)
			if (SoSanhPS(ps[j], ps[j - 1]) == 1)
				swap(ps[j], ps[j - 1]);
}


//Bài 2: Sắp xếp mảng chuỗi tăng dần bằng QuickSort
//--------------------------------------------------------
void NhapMangChuoi(const char* FileName, string*& str, int& n) {
	//Mở tệp để đọc input mảng chuỗi
	ifstream ifile;
	ifile.open(FileName);
	if (!ifile) {
		cout << "Khong the mo tap tin " << FileName << "!\n";
		return;
	}

	//Đọc input mảng chuỗi
	ifile >> n;
	ifile.ignore();
	str = new string[n];
	for (int i = 0; i < n; ++i)
		getline(ifile, str[i]);
	ifile.close();
}

//Xuất mảng chuỗi đã sắp xếp
void XuatMangChuoi(const char* FileName, string* str, int n) {
	//Mở file và xuất mảng chuỗi
	ofstream ofile;
	ofile.open(FileName);
	if (!ofile) {
		cout << "Khong the mo tap tin " << FileName << "!\n";
		return;
	}

	//Xuất mảng các chuỗi
	for (int i = 0; i < n; ++i)
		ofile << str[i] << "\n";
	ofile.close();
}

//Sắp xếp mảng chuỗi tăng dần bằng QuickSort
void QuickSort(string* str, int left, int right) {
	string pivot = str[(left + right) / 2];
	int i = left, j = right;

	while (i < j) {
		while (str[i].compare(pivot) == -1) ++i;
		while (str[j].compare(pivot) == 1)  --j;

		if (i <= j) {
			swap(str[i], str[j]);
			++i; --j;
		}
	}

	if (i < right) QuickSort(str, i, right);
	if (j > left)  QuickSort(str, left, j);
}

//Bài 3: Sắp xếp mảng số nguyên tăng dần bằng MergeSort
//--------------------------------------------------------
//Đọc số lượng phần tử cần tạo ngẫu nhiên và ghi lại vào tệp mảng ngẫu nhiên n phần tử
void NhapMangInt(const char* FileName, int*& arr, int&n) {
	//Mở tệp để đọc input mảng chuỗi
	ifstream ifile;
	ifile.open(FileName);
	if (!ifile) {
		cout << "Khong the mo tap tin " << FileName << "!\n";
		return;
	}

	//Đọc số lượng phần tử cần tạo ngẫu nhiên
	ifile >> n;
	ifile.close();

	//Tạo mảng ngẫu nhiên n phần tử
	arr = new int[n];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 10000 - 5000;

	//Xuất n và mảng arr lại vào file input
	ofstream ofile;
	ofile.open(FileName);
	ofile << n << "\n";
	for (int i = 0; i < n; ++i)
		ofile << arr[i] << " ";
	ofile.close();
}

//Xuất mảng số nguyên vào file
void XuatMangInt(const char* FileName, int* arr, int n) {
	//Mở file và xuất mảng số nguyên
	ofstream ofile;
	ofile.open(FileName);
	if (!ofile) {
		cout << "Khong the mo tap tin " << FileName << "!\n";
		return;
	}

	//Xuất mảng chuỗi vào file
	for (int i = 0; i < n; ++i)
		ofile << arr[i] << " ";
	ofile.close();
}

//Sắp xếp mảng tăng dần bằng MergeSort
//Hàm dùng trộn 2 mảng L(Left) và R(Right) thành mảng a mới thay cho mảng a ban đầu
void Merge(int *a, int left, int mid, int right) {
	//Định số phần tử và khởi tạo hai mảng L, R
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = new int[n1];
	int *R = new int[n2];

	//Đưa nửa mảng bên trái a vào L, nửa mảng bên phải a và R
	for (int i = left, k = 0; k < n1; ++i, ++k)	L[k] = a[i];
	for (int i = mid + 1, k = 0; k < n2; ++i, ++k)	R[k] = a[i];

	//Thay nửa mảng trái của a bằng các phần tử nhỏ hơn của từng mảng L, R
	//Thay nửa mảng phải của a bằng các phần tử lớn hơn của từng mảng L, R
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
		if (L[i] <= R[j]) a[k++] = L[i++];
		else a[k++] = R[j++];

		//Nếu một trong hai mảng bị hết phần tử thì đưa các phần tử còn lại vào mảng a
		while (i < n1) a[k++] = L[i++];
		while (j < n2) a[k++] = R[j++];
		delete[]L, R;
}

//Hàm MergeSort
//B1: Liên tục chia đôi mảng đến khi chỉ còn từng phần tử riêng biệt
//B2: Trộn từng mảng con thành các mảng con tăng dần (1 pt -> 2 pt ... -> n pt)
//Lặp lại phép chia ở B1 và B2 bằng đệ quy đến khi left = right (mảng con bị chia còn đúng 1 phần tử)
void MergeSort(int *a, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}
