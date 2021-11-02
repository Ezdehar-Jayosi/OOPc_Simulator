//
// Created by gadee on 06/01/2021.
//

#ifndef OOPC_SIMULATOR_PORT_H
#define OOPC_SIMULATOR_PORT_H

#include "Base.h"
//#pragma managed(push, off)
using namespace std;

class Port {
private:
	Base* right;
	Base* left;
	Base* up;
	Base* down;
	Base* unit;
public:
	Port(Base* right, Base* left, Base* up, Base* down, Base* unit) {
		//if (left == NULL) std::cout << " left is null" << std::endl;
		//if (up == nullptr)  std::cout << " up is null" << std::endl;
		this->right = right; this->left = left; this->up = up; this->down = down;
		this->unit = unit;
	};

	void recieve(Direction dir, string packet) {

		switch (dir) {
		case RIGHT:
			right->receive_packet(packet);
			break;
		case LEFT:
			left->receive_packet(packet);
			break;
		case UP:
			up->receive_packet(packet);
			break;
		case DOWN:
			down->receive_packet(packet);
			break;
		case UNIT:
			unit->receive_packet(packet);
			break;
		}
	};
	Base* getPort(Direction dir) {

		switch (dir) {
		case RIGHT:
			//std::cout << "first one supposed to be here" << std::endl;
			return right;

		case LEFT:
			//std::cout << "left" << std::endl;
			return left;

		case UP:
			//std::cout << "up" << std::endl;
			return up;

		case DOWN:
			//std::cout << "down" << std::endl;
			return down;

		case UNIT:
			//std::cout << "unit" << std::endl;
			return unit;

		}
	};

	pair<int, int> getBase(int i) { //added to print router's legs
		switch (i) {
		case 0: if (right != nullptr) return right->getCord(); else break;
		case 1: if (left != nullptr)  return left->getCord(); else break;
		case 2: if (up != NULL) return up->getCord(); else break;
		case 3: if (down != nullptr)return down->getCord(); else break;
		case 4: if (unit != nullptr)return unit->getCord(); else break;
		}
		pair<int, int> pair_xy = std::make_pair(-1, -1);
		//std::cout << "      here     ";
		return pair_xy;

	}
	~Port() {};
};

#endif //OOPC_SIMULATOR_PORT_H
