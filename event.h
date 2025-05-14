/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <iostream>
#include <chrono>
#include "event.h"

namespace seneca {
	class Event {
		std::string event_name{};
		std::chrono::nanoseconds duration{};
	public: 
		Event() = default; 
		Event(const char* name, const std::chrono::nanoseconds& duration);
		friend std::ostream& operator<<(std::ostream& ostr, const Event& e); 
	};
}

#endif