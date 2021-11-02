#include "Router.h"
#include <condition_variable>
bool time_out_flag = false;
extern int load = 0;
class Router::my_mutex {
public:
	std::mutex m;
	~my_mutex() {};
};
class Router::packets_available_cond {
public:
	std::condition_variable c;
	~packets_available_cond() {};
};

Router::Router(int x, int y, int threads) : Base(x, y), south_mutex(new my_mutex), north_mutex(new my_mutex),
east_mutex(new my_mutex), west_mutex(new my_mutex), unit_mutex(new my_mutex), local_mutex(new my_mutex),
my_cond(new packets_available_cond), start_cond(new packets_available_cond) {

	ports = nullptr;
	num_of_threads = threads;
	//this->m_impl = std::unique_ptr<void*>(my_mutex);
}

void Router::lock_mutexes(Direction dir) {
	//std::cout << "locking port mutex (inside function) ... " << std::endl;
	if (dir == LEFT) west_mutex->m.lock();
	else if (dir == RIGHT)east_mutex->m.lock();
	else if (dir == UP) north_mutex->m.lock();
	else if (dir == DOWN) south_mutex->m.lock();
	else if (dir == UNIT) unit_mutex->m.lock();
	//std::cout << "DONE .... " << std::endl;

}
//dont know it we ever gonna need this
/*
_Requires_lock_held_(Router->west_mutex->m)
_Requires_lock_held_(Router->east_mutex->m)
_Requires_lock_held_(Router->north_mutex->m)
_Requires_lock_held_(Router->south_mutex->m)
_Requires_lock_held_(Router->unit_mutex->m)
*/

void Router::unlock_mutexes(Direction dir) {
	if (dir == LEFT) west_mutex->m.unlock();
	else if (dir == RIGHT)east_mutex->m.unlock();
	else if (dir == UP) north_mutex->m.unlock();
	else if (dir == DOWN) south_mutex->m.unlock();
	else if (dir == UNIT) unit_mutex->m.unlock();

}

void Router::send_packet() {
	while (time_out_flag == false) {
		if (time_out_flag == true) {
			stopThreads();
		}
		//std::unique_lock<std::mutex> lk(local_mutex->m);
		local_mutex->m.lock();
		/*while (not_ready) {
			std::cout << " Waiting for the lock..... " << std::endl;
			(my_cond->c).wait(lk);
		}*/
		if (packets.empty()) {
			//std::cout << "Waiting for a packet ... " << std::endl;
			//(my_cond->c).wait(lk);
			//lk.unlock();
			local_mutex->m.unlock();
			continue;
		}

		//local_mutex->m.lock();
		//std::cout << "Recieved a packet ...  packet dist is " << packets.front() << std::endl;

		string packet(packets.back());
		packets.erase(packets.begin());
		Direction dir = routing(packet);
		Base* distPort = ports->getPort(dir);
		this->num_of_sent_packets++;
		//	std::cout << "the port is in DIR ... " << dir << std::endl;
			//lk.unlock();
		local_mutex->m.unlock();
		//std::cout << "locking port mutex ... " << std::endl;
		lock_mutexes(dir);
		//std::cout << "sending the packet to the port ... " << "port cords " << (distPort->getCord()).first << " " << (distPort->getCord()).second << std::endl;
		//std::cout << "unit cord_x is: " << cord_x << "  && cord_y is: " << cord_y << std::endl;
		//std::cout << packet << std::endl;
		distPort->receive_packet(packet);

		//std::cout << "unlocking port mutex ... " << std::endl;
		//std::cout << "Num of sent packets is " << this->num_of_sent_packets << std::endl;
		unlock_mutexes(dir);
		//std::cout << "DONE  ... " << std::endl;


	}
	//std::cout << " router threads stopped ... " << std::endl;
	load = this->num_of_recieved_packets - this->num_of_sent_packets;

};//take a packet from the vector of packets//XY algorithm
void Router::stopThreads() {
	//std::cout << "here in router for time out" << std::endl;
	if (time_out_flag == true) {
		//std::cout << "cycles ended should stop ...." << std::endl;
		//std::cout << "passed the unlocking ... " << std::endl;
		while (!my_threads.empty()) {
			my_threads.back()->join();
			my_threads.pop_back();

		}
		//std::cout << "passed the threads joining ... " << std::endl;
	}
}
void Router::receive_packet(string packet) {
	//std::cout << "dealing with the recieved packet ..." << std::endl;
	//std::cout << "first printing my cords ..." << " cord x = " << cord_x << "  cord y = " << cord_y << std::endl;
	//std::unique_lock<std::mutex> lk(local_mutex->m);
	/*if (time_out_flag == true) {
		stopThreads();
	}*/
	local_mutex->m.lock();
	if (!thread_initialized) {
		//	std::cout << "threads initialization ..." << std::endl;
		for (int i = 0; i < num_of_threads; i++) {
			std::thread* thrd = new std::thread(&Router::send_packet, this);
			this->my_threads.push_back(thrd);
		}
		thread_initialized = true;
		//	std::cout << "DONE threads initialization ..." << std::endl;
	}

	//local_mutex->m.lock();
	packets.push_back(packet);
	this->num_of_recieved_packets++;

	local_mutex->m.unlock();

	//(my_cond->c).notify_all();

	//lk.unlock();	//local_mutex->m.unlock();
	//packets_available.notify_all();

};

