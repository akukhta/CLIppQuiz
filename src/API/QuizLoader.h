#pragma once
#include <string>
#include <iostream>
#include <curl/curl.h>
#include <format>

class QuizLoader
{
public:
	QuizLoader() = default;

	std::string getQuestion();
	std::string getQuestion(size_t questionID);
	std::string sendAnswer(std::string const& answer);
	size_t getQuestionID();

private:
	static size_t WriteCallback(void*, size_t, size_t, void*);
	std::string currentQuestionUrl;
	std::string _getQuestion(std::string const &url);
};