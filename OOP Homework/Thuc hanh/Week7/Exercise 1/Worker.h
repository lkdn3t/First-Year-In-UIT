#include <iostream>
#include <string>

using namespace std;

class Worker {
protected:
	string Name;
	struct Date {
		int day;
		int month;
		int year;
	} Birth;
	long long Salary;

public:
	Worker();
	void setName(string name);
	void setBirth(int d, int m, int y);
	void setSalary(long long salary);

public:
	string getName()      const;
	int getBirthDay()     const;
	int getBirthMonth()   const;
	int getBirthYear()    const;
	long long getSalary() const;

public:
	virtual void input();
	virtual void output() const;
	virtual void computeSalary();
};

class ProductionWorker : public Worker {
private:
	int NumProducts;
	long long BaseSalary;

public:
	void input();
	void output() const;
	void computeSalary();

public:
	void setNumProducts(int np);
	void setBaseSalary(long long bs);
	int  getNumProducts() const;
	long long getBaseSalary() const;
};

class OfficeWorker : public Worker {
private:
	int WorkDays;

public:
	void input();
	void output() const;
	void computeSalary();

public:
	int getWorkDays() const;
	void setWorkDays(int wd);
};