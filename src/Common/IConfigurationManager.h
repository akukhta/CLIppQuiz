#pragma once

struct Configuration
{
	Configuration() : showExplanation(false), specificQuestion({ false, size_t() }), countOfQuestions(1) 
	{
		auto r = rand();
		r += rand();
	}
	
	bool showExplanation;
	std::pair<bool, size_t> specificQuestion;
	size_t countOfQuestions;
};

class IConfigurationManager
{
public:
	virtual Configuration getConfig() = 0;
};