/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#include <iostream>
#include <chrono>
#include <cstring>
#include "timeMonitor.h"
#include "event.h"

namespace seneca {
	void TimeMonitor::startEvent(const char* name) {
		m_eventName = name; 
		m_start = std::chrono::steady_clock::now();
	}

	Event TimeMonitor::stopEvent() {
		m_end = std::chrono::steady_clock::now();  
		auto event_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_end - m_start);
		Event e1(m_eventName.c_str(), event_duration);
		return e1; 
	}
}