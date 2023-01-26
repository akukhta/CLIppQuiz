#pragma once
#include "QuizLoader.h"
#include "CodeSegParser.h"
#include "IQuestionParserDecorator.h"
#include "IQuestionPrinter.h"
#include "TerminalPrinter.h"
#include "IInputHandler.h"

class CppQuiz
{
public:
	CppQuiz(std::unique_ptr<IQuestionPrinter> out, std::unique_ptr<IQuestionParserDecorator> parser, 
		std::unique_ptr<IQuestionParserDecorator> resultParser, std::unique_ptr<IQuestionParserDecorator> diffParser, std::unique_ptr<IInputHandler> input);
	
	void play();

private:
	std::unique_ptr<IQuestionPrinter> out;
	std::unique_ptr<IQuestionParserDecorator> parser;
	std::unique_ptr<QuizLoader> loader;
	std::unique_ptr<IQuestionParserDecorator> resultParser;
	std::unique_ptr<IQuestionParserDecorator> diffParser;
	std::unique_ptr<IInputHandler> input;

	size_t questionID;
	char difficulty;

};

