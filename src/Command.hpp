#pragma once

#include <boost/program_options.hpp>

namespace po = boost::program_options;

struct Command {
    virtual void execute(po::variables_map) = 0; 
};
