//
// Hack and Slash by Jonathan Hansen
//

#pragma comment(lib, "winmm.lib")

#include "Classes.h"

// Remember to change arguments when enemies are added
#define boardDraw board.print(human, enemies); human.printStat()

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(nullptr));
	int spawn = 0;
	int difficulty = 0;
	int damage = 1;
	int hp = 5;
	int worth = 1;

	bool isValid = false;

	bool quit = false;
	int menuAction = '0';

	bool endturn = false;
	int turns = 0;
	int actions = 0;
	int action = '0';
	int direction = '0';

	int tempX;
	int tempY;

	gameBoard board;
	player human;
	std::vector<enemy*> enemies {};

	int costHealth = 5;
	int costDamage = 5;

	PlaySound(TEXT("DesertMix.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);



	while (!quit) {
		menuAction = '0';
		board.print(human, enemies);
		std::cout << "          AMPERSAND:                 \n";
		std::cout << "     AND THE ARENA OF SAND           \n";
		std::cout << "  1) Play Game                       \n";
		std::cout << "  2) Upgrade character: $" << human.getMoney() << "           \n";
		std::cout << "  3) Load Previous Save              \n";
		std::cout << "  4) Save Current Game               \n";
		std::cout << "  5) Quit                            \n";
		std::cout << "  Enter value of option to continue: \n";
		do {
			menuAction = _getch();
		} while (menuAction != '1' && menuAction != '2' && menuAction != '3' && menuAction != '4' && menuAction != '5');
		//std::cin >> menuAction;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}

		if (menuAction == '1') {
			menuAction = '0';
			enemies.push_back(new enemy(9, 5, 5, 1, 1));
			human.reset(5, 1);
			boardDraw;
			std::cout << " Letters to movement, #s to turning: \n";
			std::cout << " Q W E     7 8 9                     \n" 
					  << " A   D     4   6                     \n" 
				      << " Z X C     1 2 3                     \n";
			std::cout << " * To quit                           \n";
			while (!human.isDead() && !quit) {
				++turns;
				if (turns % 5 == 0) {
					if (difficulty % 2 == 0)
						++damage;
					if (difficulty % 2 == 1)
						hp += 5;
					if (difficulty % 2 == 1)
						++worth;
					++difficulty;
				}
				endturn = false;
				actions = 0;
				while (!endturn) {
					std::cout << " S to Attack                         ";
					do {
						isValid = false;
						do {
							action = _getch();
						} while (action != 'q' && action != 'w' && action != 'e'
							&& action != 'a' && action != 'd'
							&& action != 'z' && action != 'x' && action != 'c'
							&& action != '1' && action != '2' && action != '3'
							&& action != '4' && action != '6'
							&& action != '7' && action != '8' && action != '9'
							&& action != '*' && action != 's');

						if (action == 'q' || action == 'w' || action == 'e'
							|| action == 'a' || action == 'd'
							|| action == 'z' || action == 'x' || action == 'c') {
							++actions;
							isValid = human.move(action, board);
							action = '0';
							if (isValid) {
								if (board.checkDoor(human.getX(), human.getY())) {
									if (human.getX() == 0)
										human.setDoor(3);
									if (human.getX() == BOARD_SIZE - 1)
										human.setDoor(1);
									if (human.getY() == 0)
										human.setDoor(2);
									if (human.getY() == BOARD_SIZE - 1)
										human.setDoor(4);
									board.setRegion();
									board.redraw();
									for (std::vector<enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
										delete (*it);
									}
									enemies.clear();
								}
								boardDraw;
							}
						}
						else if (action == '1' || action == '2' || action == '3'
							|| action == '4' || action == '6'
							|| action == '7' || action == '8' || action == '9') {
							human.turn(action);
							action = '0';
							boardDraw;
							isValid = true;
						}
						else if (action == 's') {
							++actions;
							enemyHit(human, enemies);
							human.attackThrust();
							boardDraw;
							enemyHit(human, enemies);
							human.attackReset();
							boardDraw;
							enemyHit(human, enemies);
							isValid = true;
						}
						/*do {
							action = _getch();
						} while (action != TURN_LOWER && action != TURN_UPPER && action != '*'
							&& action != MOVE_LOWER && action != MOVE_UPPER
							&& action != ATTACK_LOWER && action != ATTACK_UPPER); */
							//std::cin >> action;
						if (action == '*') {
							isValid = true;
						}
					} while (!isValid);
					if (action == '*') {
						quit = true;
						break;
					}
					if ((actions >= 2)) {
						endturn = true;
						++turns;
					}
				}
				if (action != '*') {
					for (std::size_t i = 0; i < enemies.size(); ++i) {
						if (enemies[i]->isMatch(-1, -1))
							continue;
						else {
							tempX = enemies[i]->getX();
							tempY = enemies[i]->getY();
							if (enemies[i]->getX() < human.getX() && enemies[i]->getY() < human.getY())
								enemies[i]->move(9);
							else if (enemies[i]->getX() > human.getX() && enemies[i]->getY() > human.getY())
								enemies[i]->move(1);
							else if (enemies[i]->getX() > human.getX() && enemies[i]->getY() < human.getY())
								enemies[i]->move(7);
							else if (enemies[i]->getX() < human.getX() && enemies[i]->getY() > human.getY())
								enemies[i]->move(3);
							else if (enemies[i]->getY() > human.getY())
								enemies[i]->move(2);
							else if (enemies[i]->getX() > human.getX())
								enemies[i]->move(4);
							else if (enemies[i]->getY() < human.getY())
								enemies[i]->move(8);
							else if (enemies[i]->getX() < human.getX())
								enemies[i]->move(6);
							if (enemies[i]->isMatch(human.getX(), human.getY())) {
								enemies[i]->setPos(tempX, tempY);
								human.damaged(enemies[i]->getDamage());
								if (human.isDead())
									break;
							}
							boardDraw;
						}
					}
				}
				spawn = rand() % 10 + 1;
				if (spawn == 10 || spawn == 1) {
					int tmpX = rand() % 4 + 1;
					int tmpY;
					switch (tmpX) {
					case 1: tmpX = 1; tmpY = 5; break;
					case 2: tmpX = 5; tmpY = 1; break;
					case 3: tmpX = 5; tmpY = 9; break;
					case 4: tmpX = 9; tmpY = 5; break;
					}
					if (enemyDead(enemies) != -1)
						enemies[enemyDead(enemies)]->reset(tmpX, tmpY, hp, damage, worth);
					else
						enemies.push_back(new enemy(tmpX, tmpY, hp, damage, worth));
				}
			}
			std::cout << "Game Over                          \n";
			for (std::vector<enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it) {
				delete (*it);
			}
			enemies.clear();
			quit = false;
		}
		else if (menuAction == '2') {
			menuAction = '0';
			while (menuAction != '3') {
				std::cout << "\n  $: " << human.getMoney() << "                               \n";
				std::cout << "  1) Damage Upgrade: " << costDamage << "               \n";
				std::cout << "  2) Health Upgrade: " << costHealth << "               \n";
				std::cout << "  3) Return to Menu                  \n";
				do {
					menuAction = _getch();
				} while (menuAction != '1' && menuAction != '2' && menuAction != '3');
				//std::cin >> menuAction;
				if (menuAction == '1') {
					menuAction = '0';
					if (human.getMoney() >= costDamage) {
						human.buyDamage(costDamage);
						costDamage *= 1.5;
					}
					else {
						std::cout << "You don't have enough money for that!\n";
					}
				}
				if (menuAction == '2') {
					menuAction = '0';
					if (human.getMoney() >= costHealth) {
						human.buyHealth(costHealth);
						costHealth *= 1.5;
					}
					else {
						std::cout << "You don't have enough money for that!\n";
					}
				}
				if (menuAction == '3')
					break;
			}
			menuAction = '0';
		}
		else if (menuAction == '3') {
			menuAction = '0';
			while (true) {
				std::cout << "\n  1) File 1:                       \n";
				std::cout << "  2) File 2:                        \n";
				std::cout << "  3) File 3:                        \n";
				std::cout << "  4) Return to Menu                 \n";
				do {
					menuAction = _getch();
				} while (menuAction != '1' && menuAction != '2' && menuAction != '3' && menuAction != '4');
				if (menuAction == '1')
					human.load("SaveOne.txt");
				else if (menuAction == '2')
					human.load("SaveTwo.txt");
				else if (menuAction == '3')
					human.load("SaveThree.txt");
				if (menuAction = '4')
					break;

				costHealth = 5;
				costDamage = 5;

				if (human.getHpUp() > 0)
					costHealth = 5 * (1.5 * human.getHpUp());
				if (human.getDmgUp() > 0)
					costDamage = 5 * (1.5 * human.getDmgUp());
				break;
			}
		}
		else if (menuAction == '4') {
			menuAction = '0';
			std::cout << "\n  1) File 1:                       \n";
			std::cout << "  2) File 2:                        \n";
			std::cout << "  3) File 3:                        \n";
			std::cout << "  4) Return to Menu                 \n";
			do {
				menuAction = _getch();
			} while (menuAction != '1' && menuAction != '2' && menuAction != '3' && menuAction != '4');
			if (menuAction == '1')
				human.save("SaveOne.txt");
			else if (menuAction == '2')
				human.save("SaveTwo.txt");
			else if (menuAction == '3')
				human.save("SaveThree.txt");
			else if (menuAction = '4');
		}
		else if (menuAction == '5') {
			quit = true;
			break;
		}
		else {
			std::cout << "Invalid Option!\n";
		}
	}
}