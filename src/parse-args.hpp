#pragma once 

#include <boost/program_options.hpp>

namespace po = boost::program_options;

po::variables_map parseArgs(int argc, char* argv[], po::options_description optionsDescription) {
    po::variables_map vm;        
    po::store(po::parse_command_line(argc, argv, optionsDescription), vm);
    po::notify(vm);    
    return vm;        
}