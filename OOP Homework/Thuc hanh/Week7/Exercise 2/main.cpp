#include "People.h"

int main() {
	//Input information of a student
	cout << "...Enter information of a student..." << endl;
	Person *person1 = new Student();
	person1->input();

	cout << "\n...Information of the input-student..." << endl;
	person1->output();
	cout << endl;

	//Input information of a Pupil
	cout << "...Enter information of a pupil..." << endl;
	Person *person2 = new Pupil();
	person2->input();

	cout << "\n...Information of the input-pupil..." << endl;
	person2->output();
	cout << endl;

	//Input information of a Worker
	cout << "...Enter information of a worker..." << endl;
	Person *person3 = new Worker();
	person3->input();

	cout << "\n...Information of the input-worker..." << endl;
	person3->output();
	cout << endl;

	//Input information of an artist
	cout << "...Enter information of an artist..." << endl;
	Person *person4 = new Artist();
	person4->input();

	cout << "\n...Information of the input-artist..." << endl;
	person4->output();
	cout << endl;

	//Input information of a singer
	cout << "...Enter information of a singer..." << endl;
	Person *person5 = new Singer();
	person5->input();

	cout << "\n...Information of the input-singer..." << endl;
	person5->output();
	cout << endl;

	delete person1, person2, person3, person4, person5;
	system("pause");
	return 0;
}