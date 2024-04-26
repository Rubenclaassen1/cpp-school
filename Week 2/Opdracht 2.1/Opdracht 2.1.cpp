// Opdracht 2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Opdracht 2.1.h"
#include <ctime>

class Stopwatch {
private:
	std::time_t startTime;
	std::time_t endTime;
public:
	Stopwatch() {
		this->startTime = std::time(0);
	}


	// Getter voor startTime
	std::time_t getStartTime() {
		return startTime;
	}

	// Getter voor endTime
	std::time_t getEndTime() const {
		return endTime;
	}

	void start() {
		this->startTime = std::time(0);
	}

	void end() {
		this->endTime = std::time(0);
	}

	time_t getElapsedTime() {
		time_t elapsedTime = endTime - startTime;

		return elapsedTime;
	}

};


int main()
{
    Stopwatch stopwatch;

	std::cout << "starting "  << std::endl;
	stopwatch.start();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "stopping" << std::endl;
	stopwatch.end();


	std::cout << "de verlopen tijd is: " << stopwatch.getElapsedTime() << " seconde" << std::endl;
   
}




