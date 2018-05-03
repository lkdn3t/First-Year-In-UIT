#include "Worker.h"

using namespace std;

int main(int argc, char *argv[])
{
	//Initialize array of workers to get information
	int NumWorkers;
	cout << "Enter number of workers: ";
	cin >> NumWorkers;
	Worker **worker = new Worker*[NumWorkers];
	
	//Get information of workers base on type of input
	for (int i = 0; i < NumWorkers; i++)
	{
		cout << "\n...Information of worker " << i + 1 << "..." << endl;

		char type;
		do {
			cout << "Enter type of worker (P/O): ";
			cin >> type;
		} while (type != 'P' && type != 'O');

		cin.ignore();
		type == 'P' ? worker[i] = new ProductionWorker : worker[i] = new OfficeWorker;
		worker[i]->input();
		worker[i]->computeSalary();
	}

	//Print information of input-workers
	for (int i = 0; i < NumWorkers; i++)
	{
		cout << "\n...Information of worker " << i + 1 << "..." << endl;
		worker[i]->output();
	}
	
	for (int i = 0; i < NumWorkers; i++)
		delete worker[i];
	delete[]worker;

	system("pause");
	return 0;
}