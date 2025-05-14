/* 
OOP345: Assignment 1
Ruchelle Baybayan 
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied 
the code that my professor provided to complete my assignments. This submitted 
piece of work has not been shared with any other student or 3rd party content provider. */

#include <iostream>
#include <utility>
#include "logger.h"
#include "event.h"

namespace seneca {
	Logger::~Logger() {
		delete[] events;
		events = nullptr;
	}

	Logger::Logger(Logger&& src) noexcept {
		*this = std::move(src);
	}

	Logger& Logger::operator=(Logger&& src) noexcept {
		if (this != &src) {
			delete[] events;
			events = src.events; 
			numEvents = src.numEvents; 
			src.events = nullptr;
			src.numEvents = 0; 
		}
		return *this; 
	}

	void Logger::addEvent(const Event& event) {
		Event* newEvents = new Event[numEvents + 1]; 
		for (int i = 0; i < numEvents; i++) {
			newEvents[i] = events[i]; 
		}
		newEvents[numEvents] = event;

		delete[] events; 
		events = newEvents; 
		numEvents++;
	}

	std::ostream& operator<<(std::ostream& ostr, const Logger& log) {
		for (int i = 0; i < log.numEvents; i++) {
			ostr << log.events[i] << std::endl;
		}
		return ostr; 
	}
}