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
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <utility>
#include "dictionary.h"
#include "settings.h"

namespace seneca {
	Dictionary::~Dictionary() {
		delete[] words;
		words = nullptr;
	}

	Dictionary& Dictionary::operator=(const Dictionary& src) {
		if (this != &src) {
			delete[] words;
			words = nullptr;
			numOfWords = src.numOfWords;

			if (src.words) {
				words = new Word[numOfWords];
				for (int i = 0; i < numOfWords; i++) {
					words[i] = src.words[i];
				}

			}
		}
		return *this;
	}

	Dictionary::Dictionary(const Dictionary& src) {
		*this = src;
	}

	Dictionary& Dictionary::operator=(Dictionary&& src) noexcept {
		if (this != &src) {
			delete[] words;
			numOfWords = src.numOfWords;
			words = src.words;
			src.numOfWords = 0; 
			src.words = nullptr;
		}
		return *this;
	}

	Dictionary::Dictionary(Dictionary&& src) noexcept {
		*this = std::move(src);
	}

	PartOfSpeech Dictionary::checkAndConvertToPOS(const std::string& str) {
		if (str == "n." || str == "n. pl.") {
			return PartOfSpeech::Noun;
		}
		else if (str == "pron.") {
			return PartOfSpeech::Pronoun;
		}
		else if (str == "a.") {
			return PartOfSpeech::Adjective;
		}
		else if (str == "adv.") {
			return PartOfSpeech::Adverb;
		}
		else if (str == "v." || str == "v. i." || str == "v. t." || str == "v. t. & i.") {
			return PartOfSpeech::Verb;
		}
		else if (str == "prep.") {
			return PartOfSpeech::Preposition;
		}
		else if (str == "conj.") {
			return PartOfSpeech::Conjunction;
		}
		else if (str == "interj.") {
			return PartOfSpeech::Interjection;
		}
		else {
			return PartOfSpeech::Unknown;
		}
	}

	std::string Dictionary::posToStr(PartOfSpeech pos) {
		switch (pos) {
		case PartOfSpeech::Noun:
			return "noun";
		case PartOfSpeech::Pronoun:
			return "pronoun";
		case PartOfSpeech::Adjective:
			return "adjective";
		case PartOfSpeech::Adverb:
			return "adverb";
		case PartOfSpeech::Verb:
			return "verb";
		case PartOfSpeech::Preposition:
			return "preposition";
		case PartOfSpeech::Conjunction:
			return "conjunction";
		case PartOfSpeech::Interjection:
			return "interjection";
		default:
			return "";
		}
	}

	Dictionary::Dictionary(const char* filename) {
		std::ifstream fin(filename);
		std::string line;

		if (fin.is_open()) {
			while (std::getline(fin, line)) {
				numOfWords++;
			}

			// Reset state of fin and move file ptr back to beginning of file 
			fin.clear();
			fin.seekg(0, std::ios::beg);
			line.clear();

			words = new Word[numOfWords];

			int i = 0;
			std::string pos_str;

			while (std::getline(fin, line)) {
				std::stringstream ss(line);
				std::getline(ss, words[i].m_word, ',');
				std::getline(ss, pos_str, ',');
				std::getline(ss, words[i].m_definition);
				words[i].m_pos = checkAndConvertToPOS(pos_str);
				i++;
			}
			fin.close();
		}
		else {
			words = nullptr;
			numOfWords = 0;
		}

	}

	void Dictionary::searchWord(const char* word) {
		bool firstDefinition = true;
		bool found = false;
		int wordLen = strlen(word);

		for (int i = 0; i < numOfWords; i++) {
			if (words[i].m_word == word) {
				found = true;

				if (firstDefinition == true) {
					// print word only for the first definition
					std::cout << words[i].m_word << " - ";
					firstDefinition = false;
				}
				else { 
					std::cout << std::setw(wordLen + 3) << " - "; // 3 because of " - " = 3 char
				}

				if (g_settings.m_verbose == true && words[i].m_pos != PartOfSpeech::Unknown) {
					std::cout << "(" << posToStr(words[i].m_pos) << ") ";
				}

				std::cout << words[i].m_definition << std::endl;
				if (g_settings.m_show_all == false) return;
			}
		} 
		if (found == false) {
			std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
		}
	}


}