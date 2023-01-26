#pragma once
#include <string>

class IInputHandler
{
public:
	virtual InputRes getInput(std::string &input) = 0;
};