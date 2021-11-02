//
// Created by gadee on 06/01/2021.
//

#ifndef OOPC_SIMULATOR_ROUTER_H
#define OOPC_SIMULATOR_ROUTER_H
//#pragma managed(push, off) 
extern bool time_out_flag;
extern int load;
#include "Base.h"
#include "Port.h"
#include <vector>
#include <thread>
#include <iostream>
#include<stdio.h>
#include <mutex>		

using namespace std;

class Router : public Base {
private:
	//basic impl
	Port* ports;//changed to RouterBase, vector<RouterBase> can accept RouterBase, Unit and Router.
	vector<string> packets;
	bool thread_initialized = false;
	//mutexes for each router leg (the ports);
	class my_mutex;
	//std::unique_ptr < void* > m_impl;
	my_mutex* north_mutex;
	my_mutex* south_mutex;
	my_mutex* west_mutex;
	my_mutex* east_mutex;
	my_mutex* unit_mutex;
	my_mutex* local_mutex;

	//condition variable
	//std::condition_variable_any packets_available;
	class packets_available_cond;
	packets_available_cond* my_cond;
	packets_available_cond* start_cond;
	//vector of threads
	vector<std::thread*> my_threads;
	int num_of_threads;
	//to use for the heat map
	int num_of_recieved_packets = 0;
	int num_of_sent_packets = 0;
	//my_mutex
		//std::unique_ptr<my_mutex> m_impl;
		//for every port there are two mutexes
		//to explain how the ports sorted in the vector
public:
	Router(int x, int y, int threads);
	Router(const Router& obj) :Base(obj.cord_x, obj.cord_y) {

		this->ports = nullptr;
		this->north_mutex = nullptr;
		this->south_mutex = nullptr;
		this->west_mutex = nullptr;
		this->unit_mutex = nullptr;
		this->east_mutex = nullptr;
		this->local_mutex = nullptr;
		this->my_cond = nullptr;
		this->num_of_threads = obj.num_of_threads;
	}
	Router& operator=(const Router& obj) {
		this->ports = nullptr;
		this->cord_x = obj.cord_x;
		this->cord_y = obj.cord_y;
		this->north_mutex = nullptr;
		this->south_mutex = nullptr;
		this->west_mutex = nullptr;
		this->east_mutex = nullptr;
		this->unit_mutex = nullptr;
		this->local_mutex = nullptr;
		this->my_cond = nullptr;

	}
	//Router(int id,Port* ports): id(id), ports(ports){};
	void send_packet();
	//take a packet from the vector of packets//XY algorithm
	void receive_packet(string packet);
	void setPorts(Port* ports) {
		this->ports = ports;
	};
	Direction routing(string pckt) {  //check how to 
		int string_to_num = stoi(pckt);
		int dist_cord_x = (string_to_num / 10) % 10;
		int dist_cord_y = string_to_num % 10;
		//std::cout << "printing the dist cord x " << dist_cord_x << " dist cord y " << dist_cord_y << std::endl;
		Direction ret;
		if (dist_cord_x < cord_x) {

			ret = UP;
			//std::cout << "dir is up " << ret << std::endl;
		}
		if (dist_cord_x > cord_x) {

			ret = DOWN;
			//std::cout << "dir is down " << ret << std::endl;
		}
		else {//dist_x==cord_x
			if (dist_cord_y == cord_y) {

				ret = UNIT;
				//std::cout << "dir is unit " << ret << std::endl;
			}
			else if (dist_cord_y < cord_y) {

				ret = LEFT;
				//std::cout << "dir is left " << ret << std::endl;
			}

			else {
				ret = RIGHT;
				//std::cout << "dir is right " << ret << std::endl;
			}
		}

		return ret;

	};
	
	void lock_mutexes(Direction dir);
	void unlock_mutexes(Direction dir);
	//toDelete
	int getCord_x() {
		return cord_x;
	};
	int getCord_y() {
		return cord_y;
	};

	int numOfReceivedPackets() { return this->num_of_recieved_packets; };
	int numOfSentPackets() { return this->num_of_sent_packets; };
	vector<string>& getPackets() {
		return packets;
	}

	void printLegs() {
		if (ports == nullptr) return;
		std::cout << "right is: cord x " << (ports->getBase(1)).first << "cord y " << ports->getBase(1).second <<
			"left is: cord x " << ports->getBase(0).first << "cord y " << ports->getBase(0).second <<
			"up is: cord x " << ports->getBase(2).first << "cord y " << ports->getBase(2).second <<
			"down is: cord x " << ports->getBase(3).first << "cord y " << ports->getBase(3).second <<
			"unit is: cord x " << ports->getBase(4).first << "cord y " << ports->getBase(4).second << std::endl;
	};
	void stopThreads();
	~Router() { //ready
		//m_impl.reset();
		//check if this is how to delete the mutexes

		delete this->north_mutex;
		delete west_mutex;
		delete east_mutex;
		delete south_mutex;
		delete local_mutex;
		delete unit_mutex;
		delete my_cond;
		ports = nullptr;
		while (!packets.empty()) {
			packets.pop_back();
		}
		while (!my_threads.empty()) {
			my_threads.back()->join();
			my_threads.pop_back();

		}

		/*	for (int i = 0; i < num_of_threads; i++) {
				delete my_threads[i];
			}*/

	};
};
#endif //OOPC_SIMULATOR_ROUTER_H
