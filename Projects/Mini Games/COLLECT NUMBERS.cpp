#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#define length	20
#define width	18

using namespace std;

int score = 0;				//Số điểm người chơi đạt được
int target = 10;			//Số điểm cần đạt được để qua màn
int level = 1;				//Cấp độ màn chơi
int chance = 3;				//Số lượt chọn số ở mỗi màn
int delay = 800;			//Thời gian trễ để người chơi quyết định chọn số
int a[width];				//Mảng sinh số ngẫu nhiên


//Hàm đưa vị trí của con nháy đến toạ độ (x,y)
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x , y };
	SetConsoleCursorPosition(h, c);
}

//In khung viền và điểm của trò chơi
void printBoard()
{
	for (int i = 0; i <= length; i++)
		cout << "#";
	cout << "     |\n";

	for (int i = 1; i < width; i++)
	{
		cout << "#";
		gotoxy(length, i);
		cout << "#     |\n";
	}

	for (int i = 0; i <= length; i++)
		cout << "#";
	cout << "     |\n";
}

//Sinh các số ngẫu nhiên trên sân
void randomNums()
{
	srand((unsigned int)time(NULL));

	for (int i = 1; i < width; i++)
		a[i] = rand() % 10;

	for (int i = 1; i < width; i++)
	{
		int rand_x = rand() % (length - 3) + 2;
		gotoxy(rand_x, i);
		cout << a[i];
	}

	gotoxy(length + 1, width + 1);
}

//In ra màn chơi (level hiện tại)
void printLevel()
{
	gotoxy(length + 10, 0);
	cout << "LEVEL " << level;
}

//In ra số lượt chọn số còn lại (mỗi màn chọn tối đa 3 số)
void printChance()
{
	gotoxy(length + 10, 2);
	cout << "CHANCE = " << chance;
}

//In ra số điểm cần đạt được
void printTarget()
{
	gotoxy(length + 10, 4);
	cout << "TARGET = " << target << "\n";
}

//In ra số điểm người chơi đạt được
void printScore()
{
	gotoxy(length + 10, 6);
	cout << "SCORE = " << score << "\n";
}

//In kết thúc trò chơi nếu người chơi không đạt yêu cầu
void printGoodbye()
{
	gotoxy(length / 2 - 4, width / 2 - 1);
	cout << "GAME OVER!\n";
}

//In ra các thông số trong trò chơi (level, target, score)
void printInfo()
{
	printLevel();
	printTarget();
	printScore();
	printChance();
}

//Xoá sàn sau một khoảng thời gian nhất định
void clrBoard()
{
	for (int i = 1; i <= width; i++)
	{
		//Xoá dòng phía trên sau khoảng delay
		if (i > 1)
		{
			gotoxy(2, i - 1);
			for (int j = 2; j < length - 1; j++)
				cout << " ";
		}

		//Đưa dòng xoá xuống 1 đơn vị độ rộng
		gotoxy(2, i);
		for (int j = 2; j < length - 1 && i < width; j++)
			cout << "-";

		//In ra số điểm bị quét qua để người chơi quyết định
		//chọn số đó hay không trong khoảng delay
		gotoxy(length + 2, i);
		if (i < width) cout << a[i];
		Sleep(delay);

		//Nếu người chơi nhấn phím Space thì số quét qua cộng vào điểm người chơi
		if (_kbhit())
			switch (_getch())
			{
			case ' ':
				if (chance)
				{
					score += a[i];
					chance--;
					printScore();
					printChance();
					break;
				}
			}
	}

	//Xoá các số bị đưa ra cũ để quét qua màn mới
	for (int i = 1; i < width; i++)
	{
		gotoxy(length + 2, i);
		cout << " ";
	}
}

//Hỏi người chơi có muốn chơi lại sau khi thua hay không?
bool isPlayAgain()
{
	gotoxy(length / 2 - 5, width / 2 + 1);
	cout << "PLAY AGAIN?\n";

	gotoxy(length / 2 - 4, width / 2 + 2);
	cout << "(Y/N): ";

	char c;
	cin >> c;

	return c == 'Y';
}

//In hướng dẫn chơi
void printAbout()
{
	cout << " WELCOME TO COLLECTING NUMBERS\n";

	cout << "\n You have 2 seconds to look at the board with random numbers.\n";
	cout << "\n After 2 seconds, a line goes through numbers and delays for a while.\n";
	cout << "\n You can choose at most 3 numbers when the line is delaying by pressing SPACE button.\n";
	cout << "\n The chosen numbers will be added to your score\n";
	cout << "\n Try to reach the target score.\n";
	cout << "\n The line will go faster and faster every level. GOOD LUCK!\n";
	cout << "\n ...PRESS ANY KEY TO PLAY...\n";
}

//Tăng độ khó sau mỗi màn chơi
void UpLevel()
{
	//Cập nhật giao diện sau mỗi màn chơi
	chance = 3;
	level++;

	//Tăng tốc độ quét + điểm số cần đạt
	if (delay > 150) delay -= 50;
	if (level <= 5) target += 10;
	else if (level <= 10) target += 15;
	else if (level <= 20) target += 20;
	else target += 22;
}

void Game()
{
	//In hướng dẫn trò chơi
	printAbout();
	_getch();

	//In ra giao diện trò chơi
	system("cls");
	printBoard();
	while (true)
	{
		//In các thông số, sinh số ngẫu nhiên trên sàn, sau đó
		//cho 2s để người chơi quan sát màn hình và bắt đầu quét số
		printInfo();
		randomNums();
		Sleep(2000);
		clrBoard();

		//Kiểm tra xem người chơi có qua màn hay không
		if (score < target)
		{
			printGoodbye();
			break;
		}
		else UpLevel();

	}

	//Yêu cầu người chơi chọn chơi lại nếu muốn
	if (isPlayAgain())
	{
		system("cls");
		Game();
	}
	else exit(0);
}

int main()
{
	Game();
}
