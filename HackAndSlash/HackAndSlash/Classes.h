#ifndef CLASSES_HPP_
#define CLASSES_HPP_

#include <iostream>
#include <time.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <ctype.h>
#include <fstream>
#include <string>

const int BLACK_SAND = 128;
const int CHARACTER = 2;
const int ENEMY = 4;
const int SAND = 103;
const int SPEAR = 96;
const int FLOWER = 45;
const int SWAMP = 18;
const int LAVA_DRY = 6;
const int LAVA_WET = 96;

const char TURN_UPPER = 'E';
const char TURN_LOWER = 'e';
const char MOVE_UPPER = 'W';
const char MOVE_LOWER = 'w';
const char ATTACK_UPPER = 'Q';
const char ATTACK_LOWER = 'q';
const char END_TURN_UPPER = 'X';
const char END_TURN_LOWER = 'x';

const int BOARD_SIZE = 11;
const int REGION_COUNT = 5;

class gameBoard;

struct weapon {
	int x, y;
	int tempX, tempY;
	char direction;
};

class player {
public:
	player();
	player(int _x, int _y, int _hp, int _damage);
	void load(std::string file);
	void save(std::string file) const;
	void reset(int _x, int _y);
	bool move(int direction, const gameBoard board);
	void attackThrust();
	void attackReset();
	void turn(int direction);
	int getX() const { return x; }
	int getY() const { return y; }
	int getDamage() const { return damage; }
	int spearX() const { return spear.x; }
	int spearY() const { return spear.y; }
	int getMoney() const { return money; }
	void addMoney(int _money) { money = money + _money; }
	void buyDamage(int cost);
	void buyHealth(int cost);
	char spearDirection() const { return spear.direction; }
	bool isDead() const { return hp <= 0; }
	void damaged(int damageRecieved);
	int getDmgUp() const { return damageUps; }
	int getHpUp() const { return healthUps; }
	void setDoor(int side);

	void printStat() const;
private:
	int x, y;
	int hp;
	int damage;
	int money;
	int damageUps;
	int healthUps;
	weapon spear;
};

// use % for enemy characters
// use a vector<enemy*> to store pointers to objects to allow infinite enemies;
class enemy {
public:
	enemy();
	enemy(int _x, int _y, int _hp, int _damage, int _worth);
	void move(int direction);
	bool death();
	void reset(int _x, int _y, int _hp, int _damage, int _worth);
	bool isMatch(int _x, int _y) const;
	int getX() const { return x; }
	int getY() const { return y; }
	int getDamage() const { return damage; }
	int getWorth() const { return worth; }
	void setPos(int _x, int _y) { x = _x; y = _y; }
	void damaged(int damageRecieved);
private:
	int x, y;
	int hp;
	int damage;
	int worth;
	//weapon sword;
};

class gameBoard {
public:
	gameBoard();
	// Add parameter : vector<enemy*> enemies
	// when ready for enemies
	void redraw();
	void print(const player &human, const std::vector<enemy*> &enemies);
	bool check(int x, int y) const;
	void setRegion();
	bool checkDoor(int x, int y) const;
private:
	char squares[BOARD_SIZE][BOARD_SIZE];
	int region;
};

bool enemyFound(int _x, int _y, const std::vector<enemy*> &enemies);
void enemyHit(player &human, std::vector<enemy*> &enemies);
int enemyDead(std::vector<enemy*> enemies);

#endif // !Classes_HPP

