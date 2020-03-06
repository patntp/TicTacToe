#include <iostream>
#include <string>
using namespace std;

class Player
{
public:
	string name;
	char symbol;
	int play()
	{
		int choice;
		cout << name << " choose: ";
		cin >> choice;
		return choice;
	};
};

class Board
{
public:
	char box[9] = { };
	string result = "tie";
	void playXO(Player a)
	{
		int index = a.play() - 1;
		if (box[index] != 'X' && box[index] != 'O')
			box[index] = a.symbol;
		else//box is filled
		{
			cout << a.name << " , please choose again.\n\n";
			playXO(a);
		}
	};

	void gameDisplay()
	{
		cout << box[0] << " | " << box[1] << " | " << box[2] << endl;
		cout << "__|___|__" << endl;
		cout << box[3] << " | " << box[4] << " | " << box[5] << endl;
		cout << "__|___|__" << endl;
		cout << box[6] << " | " << box[7] << " | " << box[8] << endl << endl;
	};

	bool isGameOver()
	{
		gameDisplay();
		if (box[0] == box[1] && box[1] == box[2] && box[0] != 0)
			return true;
		else if (box[3] == box[4] && box[4] == box[5] && box[3] != 0)
			return true;
		else if (box[6] == box[7] && box[7] == box[8] && box[6] != 0)
			return true;
		else if (box[0] == box[3] && box[3] == box[6] && box[0] != 0)
			return true;
		else if (box[1] == box[4] && box[4] == box[7] && box[1] != 0)
			return true;
		else if (box[2] == box[5] && box[5] == box[8] && box[2] != 0)
			return true;
		else if (box[0] == box[4] && box[4] == box[8] && box[0] != 0)
			return true;
		else if (box[2] == box[4] && box[4] == box[6] && box[2] != 0)
			return true;
		return false;
	};
};

int main()
{
	cout << "Let's play TIC-TAC-TOE\n";
	cout << "Player 1 plays X\n";
	cout << "Player 2 plays O\n\n";
	
	Board XO;
	Player player1, player2;
	cout << "Player 1, please type your name: ";
	getline(cin, player1.name);
	player1.symbol = 'X';
	cout << "Player 2, please type your name: ";
	getline(cin, player2.name);
	player2.symbol = 'O';
	cout << endl;
	cout << "1 | 2 | 3" << endl;
	cout << "__|___|__" << endl;
	cout << "4 | 5 | 6" << endl;
	cout << "__|___|__" << endl;
	cout << "7 | 8 | 9" << endl;
	cout << "Choose a number(1-9) to indicate your move." << endl;

	int round = 1;
	do {
		XO.playXO(player1);
		if (XO.isGameOver())//player1 wins
		{
			XO.result = player1.name;
			break;
		}
		else if (round == 5)// tie
			break;
		XO.playXO(player2);
		round++;
	} while (!XO.isGameOver());
	
	if (XO.result != player1.name && round != 5)//player2 wins
		XO.result = player2.name;
	cout << "Result: " << XO.result;
	if (XO.result != "tie")
		cout << " is the winner!!!";

	return 0;
}
