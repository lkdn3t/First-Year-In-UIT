#include <iostream>
using namespace std;

class SoPhuc {
private:
	float thuc;
	float ao;

public:
	//Định các phép khởi tạo
	SoPhuc(float t = 0, float a = 0);
	SoPhuc(const SoPhuc &z);

	//Định các phép gán và lấy dữ liệu
	void setSoPhuc(float, float);
	float getThuc();
	float getAo();

	//Định các phép toán
	SoPhuc operator+(SoPhuc);
	SoPhuc operator-(SoPhuc);
	SoPhuc operator*(SoPhuc);
	SoPhuc operator/(SoPhuc);

	//Định phép nhập xuất
	friend istream& operator>>(istream& is, SoPhuc &p);
	friend ostream& operator<<(ostream& os, SoPhuc p);
};