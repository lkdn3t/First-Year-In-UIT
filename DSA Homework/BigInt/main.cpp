#include "BigInt.h"

int main(int argc, char* argv[]) {
	const char* oFileName = "17520853.txt";
	const char* iFileName1 = NULL;
	const char* iFileName2 = NULL;
	char operate;
	
	if (argc > 3) {
		iFileName1 = argv[1];
		iFileName2 = argv[2];
		operate = argv[3][0];
	}

	BigInt lst1, lst2, result;
	Input(iFileName1, lst1);
	Input(iFileName2, lst2);

	switch (operate) {
		case '+': {
			result = Add(lst1, lst2);
			break;
		}

		case '-': {
			result = Subtract(lst1, lst2);
			break;
		}

		case '*': {
			result = Multiply(lst1, lst2);
			break;
		}

		default: {
			cout << "Invalid operator!" << endl;
			return 0;
		}
	}

	Print(oFileName, result);
	DeleteAll(lst1); 
	DeleteAll(lst2);
	DeleteAll(result);
	return 0;
}