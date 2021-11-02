//
// Created by gadee on 06/01/2021.
//

#ifndef OOPC_SIMULATOR_UNIT_H
#define OOPC_SIMULATOR_UNIT_H
#include <iostream>
#include <stdio.h>
#include "Base.h"
#include "Router.h"
#include <string>
#include <vector>
#include <time.h>
#include <chrono>
//#pragma managed(push, off)
using namespace std;
extern bool simulation_did_not_start;
class Unit : public Base {
private:
	Router* router;
	vector<string> packets;
	bool isBus;
	int num_packets;
	int start_time = -1;
	int num_of_cycles;
	int num_of_sent_packets = 0;
	vector<vector<int>> units_rates;
	vector<pair<int, int>*>* active_units_cords;
	std::thread* unit_thread;

	// to add mutex to the entry of the unit
public:
	Unit(int cord_x, int cord_y, Router router, bool isBus, int threads) : Base(cord_x, cord_y), isBus(isBus), num_packets(0) {
		Router* new_router = new Router(router.getCord_x(), router.getCord_y(), threads);
		this->router = new_router;
	};
	void send_packet() {
		/*//waiting for a new cycle to start
		std::cout << "waiting for a cycle to start ...." << std::endl;
		int time_now = (clock() - start_time) / (double CLOCKS_PER_SEC);
		while (start_time == -1 || time_now < 1) {
			time_now = (clock() - start_time) / (double CLOCKS_PER_SEC);
		}*/
		//int endwait = start_time + seconds * CLOCKS_PER_SEC;
		//cycles of sending packet to other units started
		//std::cout << "cycle started ..." << std::endl;
	/*while (this->num_of_cycles > 0) {
		//	int t = clock();
			string new_packet = this->getRandPacket();
			router->receive_packet(new_packet);
			/*int now = (clock() - t);
			while (now < 1) {
				now = (clock() - t);
			}
			this->num_of_cycles--;
			t = clock();
		}*/
		while (!simulation_did_not_start) {
			std::cout << "Unit Thread Waiting ..." << std::endl;
		}
		while (this->num_of_cycles) {
			string new_packet = this->getRandPacket();
			router->receive_packet(new_packet);
			this->num_of_sent_packets++;
			this->num_of_cycles--;
			//std::cout << "Unit Thread Sent A Packet..." << std::endl;
		}
		//this->unit_thread->join();
	};
	void receive_packet(string packet) {
		//std::cout << " unit cord_x : " << cord_x << " cord_y : " << cord_y << " has recieved the packet" << std::endl;
		//std::cout << "unit recieved the packet" << std::endl;
		///this->packets.push_back(packet);
		num_packets++;
		//std::cout << "pushed the packet in the vector" << std::endl;
		//std::cout << "we are here yeeesh " << std::endl;
	};
	void start_thread(int num_of_cycles) {
		this->unit_thread = new std::thread(&Unit::send_packet, this);
		this->num_of_cycles = num_of_cycles;
	}
	void setRouterPorts(Base* right, Base* left, Base* up, Base* down, Base* unit) {
		//if (left == nullptr) std::cout << " 2left is null" << std::endl;
		///if (up == nullptr)  std::cout << " 2up is null" << std::endl;
		Port* ports = new Port(right, left, up, down, unit);
		/*std::cout << right << " " << left << " " << up << " " << down << " " << unit << endl;
		std::cout << "cord_x: " << cord_x << " cord_y: " << cord_y << std::endl;
		std::cout << "router cord_x" << router->getCord_x() << "router cord_y" << router->getCord_y() << std::endl;*/
		router->setPorts(ports);
	}
	void set_clock(int clock_t, int num_cycles) {
		this->start_time = clock_t;
		this->num_of_cycles = num_cycles;
		send_packet();
	}
	void set_active_units(vector<pair<int, int>*>* active_units) {
		if (cord_x == -1) return;
		active_units_cords = new vector<pair<int, int>*>();
		for (auto i = active_units->begin(); i != active_units->end(); ++i) {
			pair<int, int>* curr = new pair<int, int>();
			if (cord_x == (*i)->first && cord_y == (*i)->second) {
				//active_units->erase(i);
				continue;
			}
			curr->first = (*i)->first;
			curr->second = (*i)->second;
			active_units_cords->push_back(curr);
		}
		for (int i = 0; i < units_rates.size(); i++) {
			for (int j = 0; j < units_rates[0].size(); j++) {
				if (units_rates[i][j] != -1) {
					int k = units_rates[i][j] - 1;
					while (k > 0) {
						pair<int, int>* curr = new pair<int, int>();
						curr->first = i;
						curr->second = j;
						active_units_cords->push_back(curr);
						k--;
					}
				}

			}
		}
		/*std::cout << "the active units for unit " << cord_x << ", " << cord_y << " is : ";
		for (auto i = active_units_cords->begin(); i != active_units_cords->end(); ++i) {
			std::cout << (*i)->first << "," << (*i)->second << "   ";
		}
		std::cout << std::endl;*/
	}
	void set_units_rates(int** rates, int size, int unit_index) {
		int k = 0;
		//std::cout << "the rates for this unit is : ";
		for (int i = 0; i < size; i++) {
			vector<int> curr;
			for (int j = 0; j < size; j++) {
				curr.push_back(rates[unit_index][k]);
				std::cout << rates[unit_index][k] << " , ";
				k++;
			}
			std::cout << std::endl;
			units_rates.push_back(curr);
		}
	}
	string getRandPacket() {
		int index = rand() % (active_units_cords->size());
		//std::cout << "the size is: " << active_units_cords->size() << std::endl;
		string packet;
		packet.push_back((active_units_cords->at(index))->first + '0');
		packet.push_back((active_units_cords->at(index))->second + '0');
		//std::cout << "here the packet is :  " << packet << std::endl;
		return packet;
	}
	void printActiveUnitCords() {
		for (auto i = active_units_cords->begin(); i != active_units_cords->end(); ++i) {
			std::cout << (*i)->first << "," << (*i)->second << "   ";
		}
		std::cout << std::endl;
	}
	Router* getRouter() {
		return router;
	}
	//toDelete
	int getCord_x() {
		return cord_x;
	}
	int getCord_y() {
		return cord_y;
	}

	bool getIsBus() {
		return isBus;
	}
	int NumRecievedPacket() {
		return this->num_packets;
	}
	int NumSentPackets() {
		return this->num_of_sent_packets;
	}
	int getNumWaitingPackets() {
		vector<string> packets = router->getPackets();
		int counter = 0;
		for (int i = 0; i < packets.size(); i++) {
			if (packets[0][0] == (cord_x + '0') && packets[0][1] == (cord_y + '0')) counter++;
		}
		return counter;
	}
	~Unit() {};
};
#endif //OOPC_SIMULATOR_UNIT_H
