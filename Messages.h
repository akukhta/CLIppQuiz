#pragma once
#include <string_view>

enum class InputRes : char { NORM, EXIT, TRYAGAIN};

enum class RunRes : char { INCORRECT, CORRECT, IGN};

RunRes getRes(std::string const& s);


class Messages
{
public:
	Messages() = delete;
	static std::string_view quitMessage()
	{
		return "QUIT";
	}

	static std::string_view hintMessage()
	{
		return "HINT";
	}

	static std::string_view const gvMessage()
	{
		return "GIVEUP";
	}

	static std::string_view const aqMessage()
	{
		return "ANOTHER";
	}
};