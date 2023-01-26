#pragma once
#include <iostream>
#include <format>
#include "Messages.h"
#include "IInputHandler.h"

class TerminalInput : public IInputHandler
{
public:

	virtual InputRes getInput(std::string& input) override
	{
		char mode;

		std::cin >> mode;

		switch (mode)
		{
		case '1':
		{
			std::cout << "Answer: ";
			std::string answer;
			std::cin >> answer;
			input = std::format("?result=OK&answer={}&did_answer=Answer", answer);
			return InputRes::NORM;
		}

		case '2':
		{
			input = "?result=CE&answer=&did_answer=Answer";
			return InputRes::NORM;
		}

		case '3':
		{
			input = "?result=US&answer=&did_answer=Answer";
			return InputRes::NORM;
		}

		case '4':
		{
			input = "?result=UD&answer=&did_answer=Answer";
			return InputRes::NORM;
		}

		case 'q':
		{
			return InputRes::EXIT;
		}

		default:
		{
			return InputRes::TRYAGAIN;
		}
		}
	}
};

