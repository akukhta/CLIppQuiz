#pragma once
#include <stdexcept>
#include "IQuestionParser.h"

class ResultParser : public IQuestionParser
{
public:
	virtual std::string parse(std::string text) override
	{
		for (auto const & [tag, out]:{ std::make_pair(correctTag, correctRes), std::make_pair(incorrectTag, incorrectRes)})
		{
			auto pos = text.find(tag);

			if (pos != std::string::npos)
			{
				return out;
			}

		}

		throw std::runtime_error("WrongFormat");
	}

private:
	std::string_view correctTag = "<div id=\"correct\">", incorrectTag = "<div id=\"incorrect\">";
	std::string const correctRes = "CORRECT", incorrectRes = "INCORRECT";
};