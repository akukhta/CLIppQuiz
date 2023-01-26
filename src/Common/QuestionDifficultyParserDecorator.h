#pragma once
#include <memory>
#include <stdexcept>
#include "IQuestionParserDecorator.h"

class QuestionDIfficultyParserDecorator : public IQuestionParserDecorator
{
public:
	explicit QuestionDIfficultyParserDecorator(std::unique_ptr<IQuestionParser> parser)
		: IQuestionParserDecorator(std::move(parser)) {
		;
	}

	virtual std::string parse(std::string text) override
	{
		text = IQuestionParserDecorator::parse(text);

		auto pos = text.find(tagToFind);

		if (pos == std::string::npos)
		{
			throw std::runtime_error("Wrong format");
		}

		std::string pValue = text.substr(pos + tagToFind.size());

		return pValue;
	}

private:
	std::string_view tagToFind = "Difficulty: <img src=\"/static/level-";
};