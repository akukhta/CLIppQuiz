#pragma once
#include "QuizLoader.h"
#include "../Common/CodeSegParser.h"
#include "../Common/IQuestionParserDecorator.h"
#include "../IO/IQuestionPrinter.h"
#include "../IO/TerminalPrinter.h"
#include "../IO/IInputHandler.h"
#include "../Common/IConfigurationManager.h"

class CppQuiz
{
public:
	CppQuiz(Configuration configuration, std::unique_ptr<IQuestionPrinter> out, std::unique_ptr<IQuestionParserDecorator> parser, 
		std::unique_ptr<IQuestionParserDecorator> resultParser, std::unique_ptr<IQuestionParserDecorator> diffParser, std::unique_ptr<IInputHandler> input);
	
	void play();

private:
	std::unique_ptr<IQuestionPrinter> out;
	std::unique_ptr<IQuestionParserDecorator> parser;
	std::unique_ptr<QuizLoader> loader;
	std::unique_ptr<IQuestionParserDecorator> resultParser;
	std::unique_ptr<IQuestionParserDecorator> diffParser;
	std::unique_ptr<IInputHandler> input;
	Configuration configuration;

	size_t questionID;
	char difficulty;

};

