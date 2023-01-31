#include "QuizLoader.h"

size_t QuizLoader::WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    (static_cast<std::string*>(userp))->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

std::string QuizLoader::_getQuestion(std::string const& url)
{
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    std::string readBuffer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        res = curl_easy_perform(curl);

        char* url = nullptr;

        curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

        currentQuestionUrl = url ? url : "";

        return readBuffer;
    }
    else
    {
        throw std::runtime_error("Request has failed");
    }
}

std::string QuizLoader::getQuestion()
{
    return _getQuestion("https://cppquiz.org/");
}

std::string QuizLoader::getQuestion(size_t questionID)
{
    return _getQuestion(std::format("https://cppquiz.org/quiz/question/{}", questionID));
}

std::string QuizLoader::sendAnswer(std::string const& answer)
{

    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    std::string readBuffer;

    std::string req = currentQuestionUrl + answer;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, req.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        res = curl_easy_perform(curl);

        return readBuffer;
    }
    else
    {
        throw std::runtime_error("Request has failed");
    }
}

size_t QuizLoader::getQuestionID()
{
    auto pos = currentQuestionUrl.find_last_of('/');

    return std::stoi(currentQuestionUrl.substr(pos + 1, currentQuestionUrl.size() - pos));
}
