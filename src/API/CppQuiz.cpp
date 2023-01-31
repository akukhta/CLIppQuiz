#include "CppQuiz.h"

CppQuiz::CppQuiz
	(
		Configuration configuration, std::unique_ptr<IQuestionPrinter> out, std::unique_ptr<IQuestionParserDecorator> parser,
		std::unique_ptr<IQuestionParserDecorator> resultParser, std::unique_ptr<IQuestionParserDecorator> diffParser,
		std::unique_ptr<IInputHandler> input
	) :
		configuration(configuration), loader(std::make_unique<QuizLoader>()), out(std::move(out)), parser(std::move(parser)),
		resultParser(std::move(resultParser)), diffParser(std::move(diffParser)), input(std::move(input)),
		questionID(0), difficulty('0')
{
}

void CppQuiz::play()
{
	for (size_t questionNum = 1; questionNum <= configuration.countOfQuestions; questionNum++)
	{
		auto question = loader->getQuestion();
		auto diffCulty = diffParser->parse(question);

		question = parser->parse(question);

		size_t attempts = 0;
		RunRes result = RunRes::IGN;

		std::string inputStr;

		while (result != RunRes::CORRECT)
		{
			out->clear();
			out->printInfo(diffCulty, loader->getQuestionID(), attempts++, { questionNum , configuration.countOfQuestions });
			out->print(question);

			InputRes resInpt = input->getInput(inputStr);

			if (resInpt == InputRes::EXIT)
			{
				return;
			}
			else if (resInpt == InputRes::NORM)
			{
				result = getRes(resultParser->parse(loader->sendAnswer(inputStr)));
			}
		}

		out->printSolvedMsg(attempts);
	}
}

