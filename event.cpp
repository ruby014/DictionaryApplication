/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#include <iostream>
#include <iomanip>
#include <chrono>
#include "event.h"
#include "settings.h"

namespace seneca {

	Event::Event(const char* name, const std::chrono::nanoseconds& duration) {
		event_name = ""; 
		if (name) event_name = name; 
		this->duration = duration; 
	}

	std::ostream& operator<<(std::ostream& ostr, const Event& e) { 
		static int counter = 0;
		counter++;
		int fieldWidth = 0;

		ostr << std::setw(2) << counter << ": ";
		ostr << std::setw(40) << e.event_name << " -> ";

		if (g_settings.m_time_units == "seconds") {
			fieldWidth = 2;
			auto duration_value = std::chrono::duration_cast<std::chrono::seconds>(e.duration);
			ostr << std::right << std::setw(fieldWidth) << duration_value.count() << " seconds";
		}
		else if (g_settings.m_time_units == "milliseconds") {
			fieldWidth = 5;
			auto duration_value = std::chrono::duration_cast<std::chrono::milliseconds>(e.duration);
			ostr << std::right << std::setw(fieldWidth) << duration_value.count() << " milliseconds";
		}
		else if (g_settings.m_time_units == "microseconds") {
			fieldWidth = 8;
			auto duration_value = std::chrono::duration_cast<std::chrono::microseconds>(e.duration);
			ostr << std::right << std::setw(fieldWidth) << duration_value.count() << " microseconds";
		}
		else { // nanoseconds 
			fieldWidth = 11;
			ostr << std::right << std::setw(fieldWidth) << e.duration.count() << " nanoseconds";
		}

		return ostr;
	}
}