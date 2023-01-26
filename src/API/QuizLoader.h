#pragma once
#pragma comment(lib, "wldap32.lib" )
#pragma comment(lib, "crypt32.lib" )
#pragma comment(lib, "Ws2_32.lib")
#define CURL_STATICLIB

#include <curl/curl.h>
#include <string>
#include <iostream>


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