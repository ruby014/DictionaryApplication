/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

namespace seneca {
	struct Settings {
		bool m_show_all{false};
		bool m_verbose{false};
		std::string m_time_units{ "nanoseconds" };
	};    
	extern Settings g_settings;
}

#endif 