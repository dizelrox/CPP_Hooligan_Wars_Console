#include <string>
#include <windows.h>
#include <ctime>
#include <iostream>
#include <conio.h>
#include "GameInitialize.cpp"
using namespace std;


int main()
{
	srand(time(NULL));
	GameInitialize game;
	cout << "Welcome to Hooligan Wars!\nPlease enter player name" << endl;
	string name;
	char input;
	cin >> name;
	game.getPlayer().setName(name);
	system("cls");
	cout << "Here is your character:\n" << endl;
	game.getPlayer().toString();
	cout << "\nPress ENTER to continue or ESC to quit..." << endl;
	
	do
	{
		fflush(stdin);
		input = _getch();
		if (input == 27)
			exit(0);
	} while (input != 27 && input != 13);
	

	system("cls");
	//int continueGame;
	
	do{
		game.setNewBot();

		cout << "To enter new game press ENTER\nTo exit press ESC" << endl;
		fflush(stdin);
		input = _getche();
		if (input == 27) break;
		if (input == 13)
		{
		
		do{
			int enterBattleChoice;
			do{
				int area;
				do {
					system("cls");
					cout << "Select attack area:" << endl;
					cout << "For head press 1" << endl;
					cout << "For chest press 2" << endl;
					cout << "For stomach press 3" << endl;
					cout << "For legs press 4" << endl;
					fflush(stdin);
					char input = _getche();
					area = input - '0';
				} while (area < 1 || area > 4);

				game.getPlayer().setAttackArea(area - 1);
				cout << "\nYou choose to attack opponent in the " << game.getPlayer().getAttackArea() << endl;


				Sleep(1000);


				do {
					system("cls");
					cout << "Select defence area:" << endl;
					cout << "For head press 1" << endl;
					cout << "For chest press 2" << endl;
					cout << "For stomach press 3" << endl;
					cout << "For legs press 4" << endl;
					// cin >> area;
					fflush(stdin);
					char input = _getche();
					area = input - '0';
				} while (area < 1 || area > 4);

				game.getPlayer().setDefenceArea(area - 1);
				cout << "\nYou choose to defend " << game.getPlayer().getDefenceArea() << endl;

				Sleep(1000);
				system("cls");


				cout << "If you're ready for battle press ENTER\nTo change selections press ESC" << endl;
					do
					{
						fflush(stdin);
						input = _getch();
						if (input == 13)
							enterBattleChoice = 1;
						else
							enterBattleChoice = 0;
					} while (input != 13 && input != 27);
				

				//enterBattleChoice = input - '0';

				} while (enterBattleChoice != 1);

			if (enterBattleChoice == 1)
			{
				game.getBot().setAttackArea(game.getBot().attackAreaToInt(game.getBot().getRandomAttackArea()));

				game.getBot().setDefenceArea(game.getBot().attackAreaToInt(game.getBot().getRandomAttackArea()));

				game.getPlayer().throwHit(game.getPlayer().getWeapon(), game.getPlayer().getStrengthFactor(), game.getPlayer().getAttackArea(), game.getBot());
			}

			system("cls");
			cout << game.getBot().getName() <<" blocked "<<game.getBot().getDefenceArea() << endl;

			 
			cout << game.getBot().getConsoleText() << endl;
					
			cout << game.getBot().getName() << "'s health is now " << game.getBot().getHealth() << endl;
			cout << "\nPress any key..." << endl;

			fflush(stdin);
			_getch();


			if (game.getBot().getHealth() > 0)
			{
				system("cls");
				game.getBot().throwHit(game.getBot().getWeapon(), game.getBot().getStrengthFactor(), game.getBot().getAttackArea(), game.getPlayer());

				cout << "You blocked " << game.getPlayer().getDefenceArea() << endl;
				cout << game.getPlayer().getConsoleText() << endl;
				cout << game.getPlayer().getName() << "'s health is now " << game.getPlayer().getHealth() << endl;
				cout << "\nPress any key..." << endl;

				fflush(stdin);
				_getch();
			}

		} while (game.getPlayer().getHealth() > 0 && game.getBot().getHealth() > 0);

		if (game.getPlayer().getHealth() <= 0)
		{
			cout << "You've lost the battle! Better luck next time!" << endl;
			Sleep(2000);
		}
		else
		{
			cout << "Congrats! You've won!" << endl;
			Sleep(2000);
		}

		}
		system("cls");
	} while (TRUE);



	
	
	return 0;
}