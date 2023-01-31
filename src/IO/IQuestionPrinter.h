#pragma once
#include <string>

class IQuestionPrinter
{
public:
	virtual void printInfo(std::string const& difficulty, size_t questionID, size_t atttempts, std::pair<size_t, size_t> quesionNumber) = 0;
	virtual void print(std::string const &question) = 0;
	virtual void clear() = 0;
	virtual void printSolvedMsg(size_t attempts) = 0;
};