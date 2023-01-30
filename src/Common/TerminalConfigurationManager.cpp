#include "TerminalConfigurationManager.h"

std::string const  TerminalConfigurationManager::descStr = "CLIppQuiz - CLI version of www.cppquiz.org\nOptions";

TerminalConfigurationManager::TerminalConfigurationManager(int argc, const char* argv[])
{
    desc.add_options()
        ("help,h", "Help screen")
        ("explain,e", "Show explanation")
        ("specific,s", "Solve specific question")
        ("count,c", boost::program_options::value<int>(), "Set number of questions to solve");

    store(parse_command_line(argc, argv, desc), vm);
}

Configuration TerminalConfigurationManager::getConfig()
{
    Configuration cfg;


    if (vm.count("help"))
    {
        std::cout << desc << '\n';
    }

    if (vm.count("count"))
    {
        cfg.countOfQuestions = vm["count"].as<size_t>();
    }

    if (vm.count("explain"))
    {
        cfg.showExplanation = true;
    }

    if (vm.count("specific"))
    {
        cfg.specificQuestion = { true, vm["specific"].as<int>() };
    }

    return cfg;
}
