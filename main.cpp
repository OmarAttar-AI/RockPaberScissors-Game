#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

enum enChoice { Stone = 1, Paber = 2, Scissors = 3 };

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
int NumberOfRounds()
{
	int Number = 0;
	do {
		cout << "How Many Rounds 1 to 10?\n";
		cin >> Number;
	} while (Number < 1 || Number > 10);
	return Number;
}
enChoice PlayerChoice()
{
	int c = 0;
	enChoice Choice;
	do {
		cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? \n";
		cin >> c;
	} while (c < 1 || c > 3);
	Choice = (enChoice)c;
	return Choice;

}
string ChoiceToString(enChoice Choice)
{
	switch (Choice)
	{
	case enChoice::Paber:
	{
		return "Paber";
		break;
	}
	case enChoice::Stone:
	{
		return "Stone";
		break;
	}
	case enChoice::Scissors:
	{
		return "Scissors";
		break;
	}
	}
}
void PrintHeader(enChoice PlayerChoice, enChoice CompeterChoice, string Result, int RoundNumber)
{
	cout << "Round [" << RoundNumber << "] begins: \n\n";
	cout << "______________________Round [" << RoundNumber << "] __________________\n\n";
	cout << "Player1 Choice: " << ChoiceToString(PlayerChoice) << endl
		<< "Comouter Choice: " << ChoiceToString(CompeterChoice) << endl
		<< "Round Winner: " << Result << endl << endl;
	cout << "______________________________________________\n\n";
}
void GameOver(int RoundNumbers, int PlayerWins, int ComputerWins, int Draw)
{
	cout << "\t\t-----------------------------------------------------\n\n"
		<< "\t\t\t+++  G a m e  O v e r  +++\n\n"
		<< "\t\t-----------------------------------------------------\n\n"
		<< "\t\t------------------------- [Game Results] -------------------\n\n";
	cout << "\t\tGame Rounds         : " << RoundNumbers << endl
		<< "\t\tPlayer1 won times   : " << PlayerWins << endl
		<< "\t\tComputer won times  : " << ComputerWins << endl
		<< "\t\tDraw times          : " << Draw << endl
		<< "\t\tFinal Winner        : ";
	if (PlayerWins > ComputerWins)
	{
		system("color 0A");
		cout << "Player1\n";
	}
	else if (ComputerWins > PlayerWins)
	{
		system("color 0C");
		cout << "Computer\n";
	}
	else
	{
		system("color 0E");
		cout << "No Winner" << endl;
	}
	cout << "\t\t-----------------------------------------------------\n\n";
}
void GamePlay()
{
	char Answer = 'Y';
	do {
		int RoundNumbers = NumberOfRounds();
		int PlayerWins = 0, ComputerWins = 0, Draw = 0;
		for (int i = 1; i <= RoundNumbers; i++)
		{
			enChoice Player1Choice = PlayerChoice();
			enChoice ComputerChoice = (enChoice)RandomNumber(1, 3);
			switch (Player1Choice)
			{
			case enChoice::Paber:
			{
				if (ComputerChoice == enChoice::Stone)
				{
					system("color 0A");
					PrintHeader(Player1Choice, ComputerChoice, "Player WINS!", i);
					PlayerWins++;
				}
				else if (ComputerChoice == enChoice::Scissors)
				{
					system("color 0C");
					PrintHeader(Player1Choice, ComputerChoice, "Computer WINS!", i);
					cout << "\a";
					ComputerWins++;
				}
				else
				{

					system("color 0E");
					PrintHeader(Player1Choice, ComputerChoice, "[No Winner]", i);
					Draw++;
				}
				break;
			}
			case enChoice::Stone:
			{
				if (ComputerChoice == enChoice::Scissors)
				{
					system("color 0A");
					PrintHeader(Player1Choice, ComputerChoice, "Player WINS!", i);
					PlayerWins++;
				}
				else if (ComputerChoice == enChoice::Paber)
				{
					system("color 0C");
					PrintHeader(Player1Choice, ComputerChoice, "Computer WINS!", i);
					cout << "\a";
					ComputerWins++;
				}
				else
				{

					system("color 0E");
					PrintHeader(Player1Choice, ComputerChoice, "[No Winner]", i);
					Draw++;
				}
				break;
			}
			case enChoice::Scissors:
			{
				if (ComputerChoice == enChoice::Paber)
				{
					system("color 0A");
					PrintHeader(Player1Choice, ComputerChoice, "Player WINS!", i);
					PlayerWins++;
				}
				else if (ComputerChoice == enChoice::Stone)
				{
					system("color 0C");
					PrintHeader(Player1Choice, ComputerChoice, "Computer WINS!", i);
					cout << "\a";
					ComputerWins++;
				}
				else
				{

					system("color 0E");
					PrintHeader(Player1Choice, ComputerChoice, "[No Winner]", i);
					Draw++;
				}
				break;
			}
			}

		}
		GameOver(RoundNumbers, PlayerWins, ComputerWins, Draw);
		cout << "Do You Want To Play Again? Y/N?\n";
		cin >> Answer;

	} while (toupper(Answer) == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	GamePlay();
	
	return 0;
}