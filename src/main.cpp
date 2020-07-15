#include "App.hpp"
#include "parse-args.hpp"
#include "Commands.hpp"

#include <boost/program_options.hpp>

#include <vector>
#include <iostream>
#include <memory>

namespace po = boost::program_options;

int main(int ac, char* av[])
{
    po::options_description desc("Allowed options");
    try {
        desc.add_options()
            ("help", "produce help message")
            ("add,a", po::value<std::vector<std::string>>()->multitoken(), "add todo")
            ("list,l", "show  todos list")
        ;

        auto args = parseArgs(ac, av, desc);

        Controller controller;

        controller.registerCommand("list", std::make_shared<ListCommand>());
        controller.registerCommand("add", std::make_shared<AddCommand>());

        App app = App{controller, args};
        app.run();
    }
    catch (BadCommadException& bce) {
        std::cerr << "error: " << bce.what() << "\n";
        std::cout << desc << "\n";
        return 1;
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
    }

    return 0;
}
