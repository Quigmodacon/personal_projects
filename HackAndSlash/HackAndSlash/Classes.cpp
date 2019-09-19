
#include "Classes.h"

/////////////////////////////////////////////////////////////////////////
//// GameBoard Class
/////////////////////////////////////////////////////////////////////////

gameBoard::gameBoard() {
	setRegion();
	for (int y = BOARD_SIZE - 1; y >= 0; y--) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if ((x == 5 && y == 0) || (x == 5 && y == BOARD_SIZE - 1)) {
				squares[y][x] = '=';
			}
			else if (y == BOARD_SIZE - 1 || y == 0) {
				squares[y][x] = '-';
			}
			else if ((x == 0 && y == 5) || (x == BOARD_SIZE - 1 && y == 5)) {
				squares[y][x] = '=';
			}
			else if (x == 0 || x == BOARD_SIZE - 1) {
				squares[y][x] = '|';
			}
			else if (region % REGION_COUNT == 4) {
				squares[y][x] = '@';
			}
			else if (region % REGION_COUNT == 3) {
				squares[y][x] = ':';
			}
			else if (region % REGION_COUNT == 2) {
				squares[y][x] = '#';
			}
			else if (region % REGION_COUNT == 1) {
				squares[y][x] = '~';
			}
			else if (region % REGION_COUNT == 0) {
				squares[y][x] = '*';
			}
		}
	}
}

void gameBoard::redraw() {
	for (int y = BOARD_SIZE - 1; y >= 0; y--) {
		for (int x = 0; x < BOARD_SIZE; x++) {
			if ((x == 5 && y == 0) || (x == 5 && y == BOARD_SIZE - 1)) {
				squares[y][x] = '=';
			}
			else if (y == BOARD_SIZE - 1 || y == 0) {
				squares[y][x] = '-';
			}
			else if ((x == 0 && y == 5) || (x == BOARD_SIZE - 1 && y == 5)) {
				squares[y][x] = '=';
			}
			else if (x == 0 || x == BOARD_SIZE - 1) {
				squares[y][x] = '|';
			}
			/*else if (x == human.getX() && y == human.getY()) {
				squares[y][x] = '&';
			}
			else if (enemyFound(x, y, enemies)) {
				squares[y][x] = '%';
			}
			else if (x == human.spearX() && y == human.spearY()) {
				squares[y][x] = human.spearDirection();
			}*/
			else if (region % REGION_COUNT == 4) {
				squares[y][x] = '@';
			}
			else if (region % REGION_COUNT == 3) {
				squares[y][x] = ':';
			}
			else if (region % REGION_COUNT == 2) {
				squares[y][x] = '#';
			}
			else if (region % REGION_COUNT == 1){
				squares[y][x] = '~';
			}
			else if (region % REGION_COUNT == 0) {
				squares[y][x] = '*';
			}
		}
	}
}

void gameBoard::print(const player &human, const std::vector<enemy*> &enemies) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, BLACK_SAND);
	std::cout << "\n\n\n\n\n";
	for (int y = BOARD_SIZE - 1; y >= 0; y--) {
		std::cout << "         ";
		for (int x = 0; x < BOARD_SIZE; x++) {
			SetConsoleTextAttribute(hConsole, BLACK_SAND);
			if (x == human.getX() && y == human.getY()) {
				SetConsoleTextAttribute(hConsole, CHARACTER);
				std::cout << '&';
			}
			else if (x == human.spearX() && y == human.spearY()) {
				std::cout << human.spearDirection();
			}
			else if (enemyFound(x, y, enemies)) {
				SetConsoleTextAttribute(hConsole, ENEMY);
				std::cout << '%';
			}
			else if (squares[y][x] == '~') {
				SetConsoleTextAttribute(hConsole, SAND);
				std::cout << '~';
			}
			else if (squares[y][x] == '*') {
				SetConsoleTextAttribute(hConsole, FLOWER);
				std::cout << '*';
			}
			else if (squares[y][x] == '#') {
				SetConsoleTextAttribute(hConsole, SWAMP);
				std::cout << '#';
			}
			else if (squares[y][x] == ':') {
				SetConsoleTextAttribute(hConsole, LAVA_DRY);
				std::cout << ':';
			}
			else if (squares[y][x] == '@') {
				SetConsoleTextAttribute(hConsole, LAVA_WET);
				std::cout << '@';
			}
			else
				std::cout << squares[y][x];
		}
		SetConsoleTextAttribute(hConsole, BLACK_SAND);
		std::cout << "                 \n";
	}
}

bool gameBoard::check(int x, int y) const {
	if (squares[y][x] == '|' || squares[y][x] == '-')
		return false;
	return true;
}

void gameBoard::setRegion() {
	region = rand() % REGION_COUNT + 1;
}

bool gameBoard::checkDoor(int x, int y) const {
	if (squares[y][x] == '=') {
		return true;
	}
	return false;
}

/////////////////////////////////////////////////////////////////////////
//// Player Class
/////////////////////////////////////////////////////////////////////////

player::player() {
	x = 1; y = 1;
	hp = 10;
	damage = 1;
	damageUps = 0;
	healthUps = 0;
	money = 0;
	spear.x = x + 1;
	spear.y = y + 1;
	spear.direction = '/';
}

player::player(int _x, int _y, int _hp, int _damage) {
	x = _x;
	y = _y;
	hp = _hp;
	damage = _damage;
	damageUps = 0;
	healthUps = 0;
	money = 0;
	if (x <= BOARD_SIZE / 2) {
		spear.x = x;
		spear.y = y + 1;
		spear.direction = '^';
	}
	else if (x > BOARD_SIZE / 2) {
		spear.x = x;
		spear.y = y - 1;
		spear.direction = 'v';
	}
}

void player::load(std::string file) {
	std::ifstream in(file);
	if (in.is_open()) {
		std::cout << "Loading previous save...\n";
		in >> money;
		in >> damageUps;
		in >> healthUps;
	}
	else {
		std::cout << "Failed to open";
	}
	in.close();
}

void player::save(std::string file) const {
	std::ofstream out(file);
	if (out.is_open()) {
		std::cout << "Saving game...\n";
		out << money << '\n';
		out << damageUps << '\n';
		out << healthUps << '\n';
	}
	else
		std::cout << "Failed to open";
	out.close();
}

void player::reset(int _x, int _y) {
	x = _x;
	y = _y;
	spear.x = x;
	spear.y = y + 1;
	spear.direction = '^';
	hp = 10 + healthUps;
	damage = 1 + damageUps;
}

bool player::move(int direction, const gameBoard board) {
	switch (direction) {
	case 'z': if (board.check(x-1, y-1)) {
			y -= 1; x -= 1; spear.y -= 1; spear.x -= 1;
			return true;
		}
		return false;
	case 'x': if (board.check(x, y - 1)) {
			y -= 1; spear.y -= 1;
			return true;
		}
		return false;
	case 'c': if (board.check(x+1, y-1)) {
			y -= 1; x += 1; spear.y -= 1; spear.x += 1;
			return true;
		}
		return false;
	case 'a': if (board.check(x-1, y)) {
			x -= 1; spear.x -= 1;
			return true;
		}
		return false;
	case 'd': if (board.check(x+1, y)) {
			x += 1; spear.x += 1;
			return true;
		}
		return false;
	case 'q': if (board.check(x-1, y+1)) {
			y += 1; x -= 1; spear.y += 1; spear.x -= 1;
			return true;
		}
		return false;
	case 'w': if (board.check(x, y + 1)) {
			y += 1; spear.y += 1;
			return true;
		}
		return false;
	case 'e': if (board.check(x + 1, y + 1)) {
			y += 1; x += 1; spear.y += 1; spear.x += 1;
			return true;
		}
		return false;
	}
}

void player::attackThrust() {
	spear.tempX = spear.x;
	spear.tempY = spear.y;
	if (spear.x == x && spear.y > y)
		spear.y += 1;
	else if (spear.x > x && spear.y > y) {
		spear.x += 1; spear.y += 1;
	}
	else if (spear.x > x && spear.y == y) {
		spear.x += 1;
	}
	else if (spear.x > x && spear.y < y) {
		spear.x += 1; spear.y -= 1;
	}
	else if (spear.x == x && spear.y < y) {
		spear.y -= 1;
	}
	else if (spear.x < x && spear.y < y) {
		spear.x -= 1; spear.y -= 1;
	}
	else if (spear.x < x && spear.y == y) {
		spear.x -= 1;
	}
	else if (spear.x < x && spear.y > y) {
		spear.x -= 1; spear.y += 1;
	}
	
}

void player::attackReset() {
	spear.x = spear.tempX;
	spear.y = spear.tempY;
}

void player::turn(int direction) {
	switch (direction) {
	case '1': 
		spear.direction = '/';
		spear.x = x - 1;
		spear.y = y - 1;
		break;
	case '2':
		spear.direction = 'v';
		spear.x = x - 0;
		spear.y = y - 1;
		break;
	case '3':
		spear.direction = '\\';
		spear.x = x + 1;
		spear.y = y - 1;
		break;
	case '4':
		spear.direction = '<';
		spear.x = x - 1;
		spear.y = y - 0;
		break;
	case '6':
		spear.direction = '>';
		spear.x = x + 1;
		spear.y = y - 0;
		break;
	case '7':
		spear.direction = '\\';
		spear.x = x - 1;
		spear.y = y + 1;
		break;
	case '8':
		spear.direction = '^';
		spear.x = x - 0;
		spear.y = y + 1;
		break;
	case '9':
		spear.direction = '/';
		spear.x = x + 1;
		spear.y = y + 1;
		break;
	}
}

void player::buyDamage(int cost) {
	++damageUps;
	money -= cost;
}

void player::buyHealth(int cost) {
	++healthUps;
	money -= cost;
}

void player::damaged(int damageRecieved) {
	hp -= damageRecieved;
}

void player::printStat() const {
	std::cout << "     HP: " << hp << "  DMG: " << damage << "  $: " << money 
		<< "            " << std::endl;
}

void player::setDoor(int side) {
	switch (side) {
	case 1: x -= BOARD_SIZE - 2; spear.x -= BOARD_SIZE - 2; break;
	case 2: y += BOARD_SIZE - 2; spear.y += BOARD_SIZE - 2; break;
	case 3: x += BOARD_SIZE - 2; spear.x += BOARD_SIZE - 2; break;
	case 4: y -= BOARD_SIZE - 2; spear.y -= BOARD_SIZE - 2; break;
	}
}

/////////////////////////////////////////////////////////////////////////
//// Enemy Class
/////////////////////////////////////////////////////////////////////////

enemy::enemy() {
	x = 1;
	y = 1;
	hp = 10;
	damage = 1;
	worth = 1;
}

enemy::enemy(int _x, int _y, int _hp, int _damage, int _worth) {
	x = _x;
	y = _y;
	hp = _hp;
	damage = _damage;
	worth = _worth;
}

void enemy::move(int direction) {
	switch (direction) {
	case 1: y -= 1; x -= 1; break;
	case 2: y -= 1; break;
	case 3: y -= 1; x += 1; break;
	case 4: x -= 1; break;
	case 6: x += 1; break;
	case 7: y += 1; x -= 1; break;
	case 8: y += 1; break;
	case 9: y += 1; x += 1; break;
	}
}

bool enemy::death() {
	if (hp <= 0)
		return true;
	return false;
}

void enemy::reset(int _x, int _y, int _hp, int _damage, int _worth) {
	x = _x;
	y = _y;
	hp = _hp;
	damage = _damage;
	worth = _worth;
}

bool enemy::isMatch(int _x, int _y) const {
	if (x == _x && y == _y)
		return true;
	return false;
}

void enemy::damaged(int damageRecieved) {
	hp -= damageRecieved;
}

bool enemyFound(int _x, int _y, const std::vector<enemy*> &enemies) {
	for (std::size_t i = 0; i < enemies.size(); ++i)
		if (enemies[i]->isMatch(_x, _y))
			return true;
	return false;
}

void enemyHit(player &human, std::vector<enemy*> &enemies) {
	for (std::size_t i = 0; i < enemies.size(); ++i)
		if (enemies[i]->isMatch(human.spearX(), human.spearY())) {
			enemies[i]->damaged(human.getDamage());
			if (enemies[i]->death()) {
				enemies[i]->setPos(-1, -1);
				human.addMoney(enemies[i]->getWorth());
			}
		}
}

int enemyDead(std::vector<enemy*> enemies) {
	for (std::size_t i = 0; i < enemies.size(); ++i)
		if (enemies[i]->death())
			return i;
	return -1;
}