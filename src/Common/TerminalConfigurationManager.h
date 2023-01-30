#pragma once
#include <iostream>
#include <boost/program_options.hpp>
#include "IConfigurationManager.h"

class TerminalConfigurationManager : public IConfigurationManager
{
public:
	TerminalConfigurationManager(int argc, const char* argv[]);
	virtual Configuration getConfig() override final;

private:
	
	boost::program_options::variables_map vm;
	boost::program_options::options_description desc {descStr};
	std::string static const descStr;
};

