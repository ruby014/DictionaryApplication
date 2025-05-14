/*
OOP345: Assignment 1
Ruchelle Baybayan
019315159
February 2nd 2024

I declare that this submission is the result of my own work and I only copied
the code that my professor provided to complete my assignments. This submitted
piece of work has not been shared with any other student or 3rd party content provider. */

#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

namespace seneca {
	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};

	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};

	class Dictionary {
		int numOfWords{0};
		Word* words{nullptr};
	public:
		Dictionary() = default;
		Dictionary(const char* filename); 
		void searchWord(const char* word); 
		/* implement the rule of 5 for this program to run */
		~Dictionary(); 
		Dictionary(const Dictionary&); 
		Dictionary& operator=(const Dictionary&); 
		Dictionary(Dictionary&&) noexcept; 
		Dictionary& operator=(Dictionary&&) noexcept;
		PartOfSpeech checkAndConvertToPOS(const std::string& str); 
		std::string posToStr(PartOfSpeech pos);
	};
}


#endif