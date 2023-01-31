#include "QuizBuilder.h"

QuizBuilder& QuizBuilder::setOut(std::unique_ptr<IQuestionPrinter> out)
{
    this->out = std::move(out);
    return *this;
}

QuizBuilder& QuizBuilder::setParser(std::unique_ptr<IQuestionParserDecorator> parser)
{
    this->parser = std::move(parser);
    return *this;
}

QuizBuilder& QuizBuilder::setLoader(std::unique_ptr<QuizLoader> loader)
{
    this->loader = std::move(loader);
    return *this;
}

QuizBuilder& QuizBuilder::setResultParser(std::unique_ptr<IQuestionParserDecorator> parser)
{
    this->resultParser = std::move(parser);
    return *this;
}

QuizBuilder& QuizBuilder::setDiffParser(std::unique_ptr<IQuestionParserDecorator> diffParser)
{
    this->diffParser = std::move(diffParser);
    return *this;
}

QuizBuilder& QuizBuilder::setInput(std::unique_ptr<IInputHandler> input)
{
    this->input = std::move(input);
    return *this;
}

QuizBuilder& QuizBuilder::setConfiguration(Configuration configuration)
{
    this->configuraiton.countOfQuestions = configuration.countOfQuestions;
    this->configuraiton.showExplanation = configuration.showExplanation;
    this->configuraiton.specificQuestion = configuration.specificQuestion;

    return *this;
}

CppQuiz QuizBuilder::build()
{
    return CppQuiz(configuraiton, std::move(out), std::move(parser), std::move(resultParser),
        std::move(diffParser), std::move(input));
}
