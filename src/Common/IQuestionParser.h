#pragma once
#include <string>

class IQuestionParser
{
public:
	virtual std::string parse(std::string) = 0;
};