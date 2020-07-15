#pragma once

#include "Command.hpp"
#include "TodosLoader/TodosLoader.hpp"

#include <boost/program_options.hpp>
#include <boost/algorithm/string/join.hpp>

#include <iostream>


namespace po = boost::program_options;

struct ListCommand : Command {
    void execute(po::variables_map args) {
        TodosLoader loader;
        json todosJson = loader.loadTodos();
        auto todos = todosJson["todos"].get<std::vector<std::string>>();
        int i = 1;
        for (const auto& todo : todos) {
            std::cout << i << ". " << todo << std::endl;
            i++;
        }        
    }
};


struct AddCommand : Command {

    std::string getTodoContent(po::variables_map args){
        auto addTextTokens = args["add"].as<std::vector<std::string>>();
        std::string todoContent = boost::algorithm::join(addTextTokens, " ");
        return todoContent;
    }

    void execute(po::variables_map args) {
        std::string todoContent = getTodoContent(args);
        TodosLoader loader; 
        json todosJson = loader.loadTodos();
        todosJson["todos"].push_back(todoContent);
        loader.save(todosJson);
    }
};