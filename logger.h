/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "event.h"

namespace seneca {
	class Logger {
		Event* events;
		int numEvents{}; 
	public:
		// rule of five 
		Logger() : events(nullptr), numEvents(0) {};
		~Logger();
		Logger(Logger&&) noexcept; 
		Logger& operator=(Logger&&) noexcept; 
		void addEvent(const Event& event);
		// disable copy operations 
		Logger(const Logger&) = delete;
		Logger& operator=(const Logger&) = delete;
		friend std::ostream& operator<<(std::ostream&, const Logger&); 
	};
}


#endif