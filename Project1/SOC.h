//
// Created by gadee on 06/01/2021.
//

#ifndef OOPC_SIMULATOR_SOC_H
#define OOPC_SIMULATOR_SOC_H

#include "Router.h"
#include "Unit.h"
bool simulation_did_not_start = false;
//#pragma managed(push, off)
class SystemOnAChip {
private:
	vector<vector<Unit*>> system_topology;
	int** rate;// -1 for identity
	int num_units; //might be routers more than units
	// num of router is power of 2, and num of units is according to what the user inserts
	int num_routers;//may be usable
	int num_cycles;




public:
	//bool* time_out;

	SystemOnAChip(vector<vector<Unit*>> units, int** rate, int num_units, int num_routers) :
		num_units(num_units), num_routers(num_routers), num_cycles(0) {
		this->rate = rate;
		this->system_topology = units;
		//*(this->time_out) = false;

	};
	// void increase_num_units();
	// void increase_num_routers();
	void set_num_cycles(int num_of_cycles) {
		num_cycles = num_of_cycles;
	}
	int get_num_cycles() {
		return num_cycles;
	}
	vector<vector<Unit*>> getSystemTopology() {
		return system_topology;
	}
	
	Unit* getLeaderUnit() {
		for (int i = 0; i < system_topology.size(); i++) {
			for (int j = 0; j < system_topology[0].size(); j++) {
				if (system_topology[i][j]->getIsBus()) return system_topology[i][j];
			}
		}
		//should not be here!!!

		return system_topology[0][0];
	}
	void wake_up_units(int start_clock, int num_of_cycles) {
		for (int i = 0; i < system_topology.size(); i++) {
			for (int j = 0; j < system_topology[0].size(); j++) {
				if (system_topology[i][j]->getCord_x() != -1) {
					std::cout << "waking up unit ... " << std::endl;
					system_topology[i][j]->set_clock(start_clock, num_of_cycles);
				}
			}
		}
	}
	void print() {
		std::cout << "The system has " << num_units << " units && " << num_routers << " routers" << endl;
		std::cout << "Here is the system topology: " << endl;
		std::cout << "The simulation duration is: " << num_cycles << endl;
		for (int i = 0; i < system_topology.size(); i++) {
			for (int j = 0; j < system_topology[0].size(); j++) {
				std::cout << "unit " << (system_topology[i][j])->getCord_x() << " , " << (system_topology[i][j])->getCord_y() << " :" << endl;
				std::cout << "router is :" << (system_topology[i][j])->getRouter() << " && and isBus == " << (system_topology[i][j])->getIsBus() << endl;
				//std::cout << "router legs is: ";
				//((system_topology[i][j]).getRouter())->printLegs();
				std::cout << endl;
				std::cout << endl;
				std::cout << endl;
			}
		}
		//print the rates:
	}
};
#endif //OOPC_SIMULATOR_SOC_H
