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
#include "../Common/QuizBuilder.h"
#include "../Common/TerminalConfigurationManager.h"

int main(int argc, const char* argv[])
{
	std::unique_ptr<IConfigurationManager> manager = std::make_unique<TerminalConfigurationManager>(argc, argv);

	QuizBuilder builder;

	builder.setParser(std::make_unique<LexycalParserDecorator>(
		std::make_unique<CodeSegParser>(),
		std::unordered_map<std::string_view, std::string_view>{
			{"&quot;", "\""},
			{ "&lt;", "<" },
			{ "&gt;", ">" },
			{ "&amp;", "&" },
			{ "&#39;", "'" }
	}));

	builder.setOut(std::make_unique<TerminalPrinter>()).setDiffParser(std::make_unique<QuestionDIfficultyParserDecorator>(nullptr));	
	builder.setResultParser(std::make_unique<IQuestionParserDecorator>(std::make_unique<ResultParser>()));
	builder.setInput(std::make_unique<TerminalInput>());
	builder.setConfiguration(manager->getConfig());

	CppQuiz q = builder.build();

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
