#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

char moves[15];
char press[15];
int level;
int point = 0;
int chance = 3;

void makeMoves();
void checkMoves();
void sayGoodbye();
void chooseLevel();
bool correctMoves();

int main()
{
	point = 0;
	chance = 3;

	chooseLevel();
	makeMoves();
	checkMoves();
	system("pause");
}

//Yêu cầu người chơi nhập độ khó cho trò chơi
void chooseLevel()
{
	//Tạo bảng chọn cấp độ chơi
	cout << "WELCOME TO MINI AUDITION\n\n";
	cout << "1. EASY\n\n";
	cout << "2. MEDIUM\n\n";
	cout << "3. HARD\n\n";
	cout << "CHOOSE YOUR LEVEL: ";

	//Tuỳ theo cấp độ người chơi nhập vào và chọn mức phù hợp
	//Số bước nhảy mỗi lượt = 5 * mức độ
	cin >> level;
	level *= 5;
	system("cls");
}

//Tạo ngẫu nhiên các bước nhảy cho mỗi lượt chơi
void makeMoves()
{
	//Tạo dữ liệu gồm 4 kiểu nhảy
	char move[4] = { '^','v','<','>' };
	int num;

	//Sinh ngẫu nhiên các bước nhảy
	srand((unsigned int)time(NULL));
	for (int i = 0; i < level; i++)
	{
		num = rand() % 4;
		moves[i] = move[num];
	}

	//In ra màn hình số điểm và số lượt còn lại
	cout << "POINT: " << point << "\t";
	cout << "CHANCE: " << chance << "\n\n";

	//In ra màn hình số bước nhảy
	for (int i = 0; i < level; i++)
		cout << moves[i] << " ";
	cout << "\n\n";
}

//Kiểm tra các bước nhảy nhập vào
void checkMoves()
{
	//Chú ý: mỗi lần nhập thì giá trị đếm tăng lên 2
	int i = 0;

	while (true)
		if (_kbhit())
		{
			switch (_getch())
			{
			case 75: cout << "< "; press[i/2] = '<'; break;
			case 77: cout << "> "; press[i/2] = '>'; break;
			case 72: cout << "^ "; press[i/2] = '^'; break;
			case 80: cout << "v "; press[i/2] = 'v'; break;
			}
			i++;

			//Sau khi hoàn thành xong các bước nhảy thì kiểm tra
			if (i == 2 * level)
			{
				system("cls");
				if (correctMoves()) point += level;
				else chance--;

				//Nếu sai 3 lần thì trò chơi kết thúc
				if (!chance)
				{
					sayGoodbye();
					break;
				}

				//Nếu không thì tiếp tục màn chơi kế
				else
				{
					makeMoves();
					checkMoves();
				}
			}
		}
}

//Kiểm tra các bước nhảy nhập vào có đúng hay không
bool correctMoves()
{
	for (int i = 0; i < level; i++)
		if (moves[i] != press[i]) return false;
	return true;
}

//Nếu sai quá 3 lượt thì in thông báo kết thúc
//và hỏi người chơi có muốn chơi lại không
void sayGoodbye()
{
	cout << "GAME OVER!\n\n";
	cout << "YOUR SCORE = " << point << "\n\n";
	cout << "PLAY AGAIN? (Y/N): ";

	char c;
	cin >> c;
	if (c == 'Y')
	{
		system("cls");
		main();
	}
	else exit(0);
}
