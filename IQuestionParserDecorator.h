#pragma once
#include "IQuestionParser.h"

class IQuestionParserDecorator : public IQuestionParser
{
public:
	explicit IQuestionParserDecorator(std::unique_ptr<IQuestionParser> parser) : parser(std::move(parser)) { ; }

	virtual std::string parse(std::string text) override
	{
		return parser ? parser->parse(text) : text;
	}

private:
	std::unique_ptr<IQuestionParser> parser;
};