#pragma once
#include <memory>
#include <unordered_map>
#include "IQuestionParserDecorator.h"

class LexycalParserDecorator : public IQuestionParserDecorator
{
public:
	LexycalParserDecorator(std::unique_ptr<IQuestionParser> parser, std::unordered_map<std::string_view, std::string_view> && replacingTable)
		: IQuestionParserDecorator(std::move(parser)), replacingTable(std::move(replacingTable)) { ; }

	virtual std::string parse(std::string text) override
	{
		text = IQuestionParserDecorator::parse(text);

		for (auto [sym, repVal] : replacingTable)
		{
			size_t pos = text.find(sym);

			while (pos != std::string::npos)
			{
				text.replace(text.begin() + pos, text.begin() + pos + sym.size(), repVal);
				pos = text.find(sym);
			}
		}
		
		return text;
	}

private:

	std::unordered_map<std::string_view, std::string_view> replacingTable;
};