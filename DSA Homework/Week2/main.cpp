#include "Sort.h"
using namespace std;

int main(int argc, char *argv[]) {
	//Nhập yêu cầu X để sort từ command line
	int X;
	const char* FileInput;
	const char* FileOutput = "17520853.txt";
		
	if (argc > 2) {
		X = atoi(argv[1]);
		FileInput = argv[2];
	}
	else {
		cout << "Tham so X khong hop le!\n";
		return 0;
	}

	//Với từng yêu cầu, thực hiện theo đề bài	
	int n;
	switch (X) {
	case 1:
		//Trường hợp X = 1: sort mảng phân số giảm dần bằng BubbleSort
		PhanSo *ps;
		NhapMangPS(FileInput, ps, n);
		BubbleSort(ps, n);
		XuatMangPS(FileOutput, ps, n);
		break;

	case 2:
		//Trường hợp X = 2: sort mảng chuỗi tăng dần bằng QuickSort
		string *str;
		NhapMangChuoi(FileInput, str, n);
		QuickSort(str, 0, n - 1);
		XuatMangChuoi(FileOutput, str, n);
		break;

	case 3:
		//Trường hợp X = 3: sort mảng số nguyên tăng dần bằng MergeSort
		int *arr;
		NhapMangInt(FileInput, arr, n);
		MergeSort(arr, 0, n - 1);
		XuatMangInt(FileOutput, arr, n);
		break;

	default:
		//Trường hợp X không thuộc [1, 2, 3]
		cout << "Tham so nhap vao khong hop le (X = {1, 2, 3})\n";
		break;
	}
}