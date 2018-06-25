#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int data;
	Node *pNext;
	Node *pPrev;
};

typedef struct List {
	Node *pHead;
	Node *pTail;;
} BigInt;

Node *GetNode(int data) {
	Node *node = new Node;
	if (!node) return NULL;
	node->data = data;
	node->pNext = NULL;
	node->pPrev = NULL;
}

void Init(List &lst) {
	lst.pHead = NULL;
	lst.pTail = NULL;
}

void AddHead(List &lst, Node *node) {
	if (lst.pHead == NULL) {
		lst.pHead = lst.pTail = node;
		return;
	}
	node->pNext = lst.pHead;
	lst.pHead->pPrev = node;
	lst.pHead = node;
}

void AddTail(List &lst, Node *node) {
	if (lst.pHead == NULL) {
		lst.pHead = lst.pTail = node;
		return;
	}
	lst.pTail->pNext = node;
	node->pPrev = lst.pTail;
	lst.pTail = node;
}

void Input(const char* FileName, List &lst) {
	Init(lst);
	ifstream ifile;
	ifile.open(FileName);

	if (!ifile) {
		cout << "Cannot open " << FileName << " file!" << endl;
		return;
	}

	char c;
	while (ifile >> c) {
		if (c == '\n') break;
		AddTail(lst, GetNode(c - 48));
	}

	ifile.close();
}

void Print(const char* FileName, List lst) {
	ofstream ofile;
	ofile.open(FileName);

	if (!ofile) {
		cout << "Cannot open " << FileName << " file!" << endl;
		return;
	}

	for (Node *p = lst.pHead; p != NULL; p = p->pNext) {
		if (p->data == -1) ofile << "-";
		else ofile << p->data;
	}

	ofile.close();
}

List Add(List lst1, List lst2) {
	List Sum; Init(Sum);
	int carry = 0;
	Node *p1 = lst1.pTail;
	Node *p2 = lst2.pTail;

	while (p1 && p2) {
		int x = p1->data + p2->data + carry;
		AddHead(Sum, GetNode(x % 10));
		carry = x / 10;
		p1 = p1->pPrev;
		p2 = p2->pPrev;
	}

	while (carry) {
		if (p1) {
			int x = p1->data + carry;
			AddHead(Sum, GetNode(x % 10));
			p1 = p1->pPrev;
			carry = x / 10;
		}
		else if (p2) {
			int x = p2->data + carry;
			AddHead(Sum, GetNode(x % 10));
			p2 = p2->pPrev;
			carry = x / 10;
		}
		else {
			AddHead(Sum, GetNode(carry));
			break;
		}
	}

	while (p1) {
		AddHead(Sum, GetNode(p1->data));
		p1 = p1->pPrev;
	}
	while (p2) {
		AddHead(Sum, GetNode(p2->data));
		p2 = p2->pPrev;
	}
	return Sum;
}

int getLength(List lst) {
	int count = 0;
	for (Node *p = lst.pHead; p != NULL; p = p->pNext)
		count++;
	return count;
}

void DeleteHead(List &lst) {
	if (!lst.pHead) return;
	Node *p = lst.pHead;
	lst.pHead = lst.pHead->pNext;
	delete p;
}

void DeleteLeadZero(List &lst) {
	while (lst.pHead->data == 0)
		DeleteHead(lst);
}

void DeleteAll(List &lst) {
	if (!lst.pHead) return;
	Node *cur = lst.pHead;
	Node *next;

	while (cur) {
		next = cur->pNext;
		delete cur;
		cur = next;
	}
}

bool isNotSmaller(List lst1, List lst2) {
	Node *p1 = lst1.pHead;
	Node *p2 = lst2.pHead;
	while (p1 && p2) {
		if (p1->data < p2->data)
			return false;
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	return true;
}

void subtract_AddHead(int &x, int &borrow, List &lst) {
	borrow = x < 0;
	if (borrow) x += 10;
	AddHead(lst, GetNode(x));
}

List Subtract(List lst1, List lst2) {
	int len1 = getLength(lst1);
	int len2 = getLength(lst2);
	int x, borrow = 0;

	List Diff; Init(Diff);
	Node *p1 = lst1.pTail;
	Node *p2 = lst2.pTail;

	if (len1 != len2) {
		while (p1 && p2) {
			x = p1->data - p2->data - borrow;
			if (len1 < len2) x = -x;
			subtract_AddHead(x, borrow, Diff);
			p1 = p1->pPrev;
			p2 = p2->pPrev;
		}

		while (borrow) {
			if (p1) {
				x = p1->data - borrow;
				p1 = p1->pPrev;
			}
			else if (p2) {
				x = p2->data - borrow;
				p2 = p2->pPrev;
			}
			subtract_AddHead(x, borrow, Diff); 
		}

		while (p1) {
			AddHead(Diff, GetNode(p1->data));
			p1 = p1->pPrev;
		}

		while (p2) {
			AddHead(Diff, GetNode(p2->data));
			p2 = p2->pPrev;
		}

		DeleteLeadZero(Diff);
		if (len1 < len2) AddHead(Diff, GetNode(-1));
	}

	else {
		bool isSmaller = !isNotSmaller(lst1, lst2);
		while (p1) {
			x = p1->data - p2->data - borrow;
			if (isSmaller) x = -x;
			subtract_AddHead(x, borrow, Diff);
			p1 = p1->pPrev;
			p2 = p2->pPrev;
		}
		DeleteLeadZero(Diff);
		if (isSmaller) AddHead(Diff, GetNode(-1));
	}
	return Diff;
}

List Multiply(List lst1, List lst2) {
	int x, carry = 0, count = 0;
	List Pro; Init(Pro);
	
	for (Node *p2 = lst2.pTail; p2 != NULL; p2 = p2->pPrev) {
		List tmp; 
		Init(tmp);

		for (Node *p1 = lst1.pTail; p1 != NULL; p1 = p1->pPrev) {
			x = p1->data * p2->data + carry;
			carry = x / 10;
			AddHead(tmp, GetNode(x % 10));
		}
		if (carry) AddHead(tmp, GetNode(carry));
		
		for (int i = 0; i < count; i++)
			AddTail(tmp, GetNode(0));
		
		Pro = Add(Pro, tmp);
		DeleteAll(tmp);
		count++;
	}
	return Pro;
}