/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include "event.h"

namespace seneca {
	class Event; 

	class TimeMonitor {
		std::string m_eventName{};
		std::chrono::steady_clock::time_point m_start{}; // time_point
		std::chrono::steady_clock::time_point m_end{};
	public: 
		void startEvent(const char* name); 
		Event stopEvent(); 
	};
}

#endif 