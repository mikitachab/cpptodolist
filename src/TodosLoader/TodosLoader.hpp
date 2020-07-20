#pragma once

#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct TodosLoader  {
    std::string todosFileName{"todos.json"};

    json loadTodos();
    void save(json todos);
    json getDefaultTodos();
};