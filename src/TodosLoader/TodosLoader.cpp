#include "TodosLoader.hpp"

#include <fstream>


json TodosLoader::loadTodos(){
    std::ifstream file(todosFileName);
    json todos;
    if (file.good()) {
        file >> todos;
    } else {
        todos = getDefaultTodos();
        save(todos);
    }
    return todos;
}

void TodosLoader::save(json todos) {
    std::ofstream file(todosFileName);
    file << todos;
}

json TodosLoader::getDefaultTodos(){
    json todos;
    todos["todos"] = json::array();
    return todos;
}