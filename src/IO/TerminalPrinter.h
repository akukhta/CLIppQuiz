#pragma once
#include <iostream>
#include <format>
#include "../Common/Messages.h"
#include "IQuestionPrinter.h"

class TerminalPrinter final : public IQuestionPrinter
{
public:

	virtual void clear() override
	{
		system("cls");
	}

	void setQuestion(std::string const &question)
	{
		currentQuestion = question;
	}

	std::string getQuestion()
	{
		return currentQuestion;
	}

	virtual void printInfo(std::string const& difficulty, size_t questionID, size_t atttempts, std::pair<size_t,size_t> questionNumber) override
	{
		std::cout << "Difficulty: [";

		size_t diffInt = std::stoi(difficulty);

		for (size_t i = 0; i < diffInt; i++)
		{
			std::cout << "*";
		}

		for (size_t i = 1; i <= 3 - diffInt; i++)
		{
			std::cout << " ";
		}

		std::cout << std::format("]\tQuestion ID:\t{}\tAttempts:\t{}\tQuestion: {}\\{}\n\n", questionID, atttempts, questionNumber.first, questionNumber.second);
	}

	virtual void print(std::string const& question) override
	{
		std::cout << question << "\n\n" << menu << std::endl;
	}

	virtual void printSolvedMsg(size_t attempts) override
	{
		std::cout << std::format("Solved with {} attempts!\n", attempts);
	}

private:
	std::string_view const menu = "1. The program is guaranteed to output:\n2. The program has a compilation error\n3. The program is unspecified / implementation defined\n4. The program is undefined\nq. Quit";

	std::string currentQuestion;
};

