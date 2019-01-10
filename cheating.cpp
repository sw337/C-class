#include <iostream>
#include <iomanip>
#include <algorithm>
#include <regex>
#include <sstream>
#include <vector>
#include <cassert>
#include <ctime>
using namespace std;

const int DefaultBoardSize = 10;
const int DefaultMinShipSize = 2;
const int DefaultMaxShipSize = 4;
const int DefaultShipCount = 6;
bool GlobalHintMode = false;

class Cell{
	enum mark {HIT, MISS, NONE};
	mark m_status;
	bool m_ship;
public:
	Cell() : m_status(NONE), m_ship(false) {}
	friend ostream& operator<<(ostream& os, const Cell& c){
		if(GlobalHintMode && c.m_ship && c.m_status == NONE) os << "*";
		switch(c.m_status) {
		case HIT: os << "@"; break;
		case MISS: os << "-"; break;
		case NONE: if(GlobalHintMode && c.m_ship) break;
					os << "."; break;
		default: assert(false);
		}
		return os << ' ';
	};
	bool getShip(){ return m_ship;}
	void setShip() {
		  //need to implement
	}
};

class Board{
	string m_name;
	int m_size;
	vector<vector<Cell> > m_map;
	int m_target;
	int m_bombed;
public:
	Board(const string& n, const int s = DefaultBoardSize) :
		m_name(n), m_size(s), m_target(0), m_bombed(0) {
		vector<Cell> arow(m_size, Cell());
		for(int i = 0; i < m_size; ++i) m_map.push_back(arow);
		init();
	}
//add methods freely
void init(const int n = DefaultShipCount){
	int shipsize;
	for(int i = 0; i <= 5; ++i){
		shipsize = rand() % 3 + 2;
		assert(shipsize >= DefaultMinShipSize && shipsize <= DefaultMaxShipSize);
	}
// have two values, one for adjusting vertically, and one for adjusting horizontally.
// if it is in row 8 for example, have the ability to adjust randomly.
}
bool bomb(const int row, const int col){
	//bool getShip();
	//if(m_target && getShip()) {return true;}
	return false;
}
bool isover() const {return m_target <= m_bombed;}
friend ostream& operator<< (ostream& os, const Board& m) {
	os << " <<" << m.m_name << ">>" << endl << " ";
	for (int row = 0; row < m.m_size; ++row) os << (char) ('A' + row) << ' ';
	os << endl;
	for (int row = 0; row < m.m_size; ++row) {
		for (int col = 0; col < m.m_size; ++col){
			if(!col) os << setw(2) << right << row + 1 << ' ';
			os << m.m_map[row] [col];
	}
		os << endl;
	}
return os;
}
};

int parse(const int size, int& row, int& col){
	cout << "\nEnter position, \"show\", \"init\" or \"quit\": ";
	string line;
	regex pattern1("show|init|quit");
	regex pattern2("[0-9]+[[:blank:]]+[a-z]");

	while(getline(cin,line)){
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		if(regex_match(line, pattern1)){
			if(line.find("init") != string::npos) return 2;
			if(line.find("show") != string::npos) return 1;
			if(line.find("quit") != string::npos) return -1;
 		}
		if(regex_match(line, pattern2)){
			string c, r;
			istringstream iss(line);
			iss >> c >> r;
			assert(!iss.fail());
			row = atoi(c.c_str()) - 1;
			col = r[0] - 'a';
			if(row >= 0 && row < size && col >= 0 && col < size) return 0;
		}
		cout << "Input error, try again: ";
	}
	assert(false);
	return 0;
}

int main() {
	srand(time(0));
	const int size = DefaultBoardSize;
	Board b("Atlantic Ocean" , size);

	while (true){
		cout << b;
		GlobalHintMode = false;
		int row, col, res = parse(size, row, col);
		if (res == -1) break;
		if (res == 1){
			GlobalHintMode = true;
			continue;
		}
		if (res == 2){
			b.init();
			continue;
		}
		bool r = b.bomb(row, col);
		cout << "You " << (r? "\a hit :)" : "missed :( ") << endl;
		if (b.isover()) {
			cout << "You bombed all the ships, congratulations!" << endl;
			break;
		}
	}
	cout << "Bye! Thank you for playing Besart's BattleShip game!" << endl;
	return 0;
}
