#pragma once

struct Configuration
{
	bool showExplanation = false;
	std::pair<bool, size_t> specificQuestion = { false, size_t() };
	size_t countOfQuestions = 1;
};

class IConfigurationManager
{
public:
	virtual Configuration getConfig() = 0;
};