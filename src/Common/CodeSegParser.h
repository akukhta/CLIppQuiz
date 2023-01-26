#pragma once
#include <stdexcept>
#include "IQuestionParser.h"

class CodeSegParser : public IQuestionParser
{
public:
	virtual std::string parse(std::string text) override
	{
		auto pos = text.find(openTag);

		if (pos == std::string::npos)
		{
			throw std::runtime_error("Incorrect document format");
		}

		auto codeSeg = std::string(text.begin() + pos + openTag.size(), text.begin() + text.find(closeTag));

		return codeSeg;
	}

private:
	std::string_view openTag = "<code class=\"cpp hljs\">", closeTag = "</code>";
};