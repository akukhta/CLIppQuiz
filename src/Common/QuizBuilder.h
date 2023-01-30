#pragma once
#include "../API/CppQuiz.h"
#include "IConfigurationManager.h"

// Builder pattern implementation 
// Use to create instance of CppQuiz
// Without passing NULLPTRS etc
// builder.setOut(std::move(out)).setInput(std::move(input)).build();

class QuizBuilder
{
public:
	QuizBuilder() = default;

	QuizBuilder& setOut(std::unique_ptr<IQuestionPrinter> out);
	QuizBuilder& setParser(std::unique_ptr<IQuestionParserDecorator> parser);
	QuizBuilder& setLoader(std::unique_ptr<QuizLoader> loader);
	QuizBuilder& setResultParser(std::unique_ptr<IQuestionParserDecorator> parser);
	QuizBuilder& setDiffParser(std::unique_ptr<IQuestionParserDecorator> diffParser);
	QuizBuilder& setInput(std::unique_ptr<IInputHandler> input);
	QuizBuilder& setConfiguration(Configuration configuration);

	CppQuiz build();

private:
	std::unique_ptr<IQuestionPrinter> out = nullptr;
	std::unique_ptr<IQuestionParserDecorator> parser = nullptr;
	std::unique_ptr<QuizLoader> loader = nullptr;
	std::unique_ptr<IQuestionParserDecorator> resultParser = nullptr;
	std::unique_ptr<IQuestionParserDecorator> diffParser = nullptr;
	std::unique_ptr<IInputHandler> input = nullptr;
	Configuration configuraiton;
};