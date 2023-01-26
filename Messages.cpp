#include "Messages.h"

RunRes getRes(std::string const& s)
{
	if (s == "CORRECT")
	{
		return RunRes::CORRECT;
	}
	else if (s == "INCORRECT")
	{
		return RunRes::INCORRECT;
	}
	else
	{
		return RunRes::IGN;
	}
}
