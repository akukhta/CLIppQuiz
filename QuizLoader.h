#pragma once
#include <string>
#include <iostream>
#include <curl/curl.h>

class QuizLoader
{
public:
	QuizLoader() = default;

	std::string getQuestion();
	std::string sendAnswer(std::string const& answer);
	size_t getQuestionID();

private:
	static size_t WriteCallback(void*, size_t, size_t, void*);
	std::string currentQuestionUrl;
	
};