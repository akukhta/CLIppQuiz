// CLIppQuiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../API/CppQuiz.h"
#include "IQuestionParserDecorator.h"
#include "../IO/TerminalPrinter.h"
#include "LexycalParserDecorator.h"
#include "ResultParser.h"
#include "QuestionDifficultyParserDecorator.h"
#include "../IO/TerminalInput.h"

int main()
{
	std::unique_ptr<IQuestionParserDecorator> parser = std::make_unique<LexycalParserDecorator>(
		std::make_unique<CodeSegParser>(),
		std::unordered_map<std::string_view, std::string_view>{
			{"&quot;", "\""},
			{ "&lt;", "<" },
			{ "&gt;", ">" },
			{ "&amp;", "&" },
			{ "&#39;", "'" }
		});

	std::unique_ptr<IQuestionPrinter> printer = std::make_unique<TerminalPrinter>();
	std::unique_ptr<IQuestionParserDecorator> resParser = std::make_unique<IQuestionParserDecorator>(std::make_unique<ResultParser>());
	std::unique_ptr<IQuestionParserDecorator> diffParser = std::make_unique<QuestionDIfficultyParserDecorator>(nullptr);
	std::unique_ptr<IInputHandler> input = std::make_unique<TerminalInput>();

	CppQuiz q(std::move(printer), std::move(parser), std::move(resParser), std::move(diffParser), std::move(input));

	q.play();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
