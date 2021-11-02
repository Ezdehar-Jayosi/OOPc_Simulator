//
// Created by win10 on 1/8/2021.
//

#ifndef OOPC_SIMULATOR_BASE_H
#define OOPC_SIMULATOR_BASE_H
#include <string>
#include <utility>
#include <iostream>
/* adding RouterBase, Routers and Units both have id, x and y coordinates, to avoid causing a cycle with the includes
	RouterBase is going to solve the problem.
	Router and Unit both must inherit RouterBase.
	We don't need port anymore.
*/
using namespace  std;
enum Direction { LEFT, RIGHT, UP, DOWN, UNIT };
class Base {
protected:
	int cord_x = -1;
	int cord_y = -1;
public:
	Base(int cord_x, int cord_y) : cord_x(cord_x), cord_y(cord_y) {}
	Base(const Base& obj) = default;
	Base& operator=(const Base&) = default;
	virtual  void send_packet() {};

	virtual  void receive_packet(string packet) {
		std::cout << "we are here and not in port recieved packet func" << std::endl;
	};
	virtual std::pair<int, int> getCord() {
		//std::cout << cord_x << "   " << cord_y << std::endl;
		std::pair<int, int> pair_xy = std::make_pair(cord_x, cord_y);
		return pair_xy;

	} //added for printing router's legs
};


#endif //OOPC_SIMULATOR_BASE_H
