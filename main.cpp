#include <iostream>
#include <vector>

std::string get_desired_operation() {
  std::cout << "Please enter one of the following todo operations:" << std::endl;
  std::cout << "add, list, edit, delete, clear or exit." << std::endl;
  std::string desired_operation;
  getline(std::cin, desired_operation);
  return desired_operation;
};

std::string get_todo() {
  std::cout << "Please enter a new todo:" << std::endl;
  std::string new_todo;
  getline(std::cin, new_todo);
  return new_todo;
};

void list_todos(std::vector<std::string> const &todos) {
  std::cout << "\n-----------------------------" << std::endl;
  std::cout << "The current todos are as follows:" << std::endl;
  for(auto const &todo: todos) {
    std::cout << todo << std::endl;
  }
  std::cout << "-----------------------------\n\n";
};

void throw_error() {
  std::cout << "\n-----------------------------" << std::endl;
  std::cout << "ERROR! ERROR! INVALID INPUT!" << std::endl;
  std::cout << "-----------------------------\n\n";
};

void edit_todo(std::vector<std::string> &todos) {
  std::cout << "Please enter the todo that you want to edit:" << std::endl;
  std::string todo_for_edit;
  getline(std::cin, todo_for_edit);
  std::cout << "Please enter the new value:" << std::endl;
  std::string new_todo_value;
  getline(std::cin, new_todo_value);
  bool todo_was_found {false};
  for(auto &todo: todos) {
    if(todo == todo_for_edit) {
      todo = new_todo_value;
      todo_was_found = true;
    }
  }
  if(!todo_was_found) {
    std::cout << "That todo doesn't exist." << std::endl;
  }
};

void delete_todo(std::vector<std::string> &todos) {
  std::cout << "Please select the todo that you want to delete." << std::endl;
  std::string todo_for_deletion;
  getline(std::cin, todo_for_deletion);
  bool todo_was_found {false};
  for(size_t i {0}; i < todos.size(); i++) {
    if(todos[i] == todo_for_deletion) {
      todos.erase(todos.begin() + i);
      todo_was_found = true;
    }
  }
  if(!todo_was_found) {
    std::cout << "todo not found." << std::endl;
  }
};

void clear_todos(std::vector<std::string> &todos) {
  std::cout << "Are you sure that you want to clear all of the todos?" << std::endl;
  std::cout << "yes to confirm, no to decline." << std::endl;
  std::string answer;
  getline(std::cin, answer);
  if(answer == "yes") {
    todos.clear();
    std::cout << "Todos cleared." << std::endl;
  } else if(answer == "no") {
    std::cout << "Todos not cleared." << std::endl;
  } else {
    std::cout << "Invalid selection." << std::endl;
  }
};

int main() {
  std::vector<std::string> todos {};
  std::string desired_operation {get_desired_operation()};
  while(desired_operation != "exit") {
    if(desired_operation == "add") {
      todos.push_back(get_todo());
      desired_operation = get_desired_operation();
    } else if(desired_operation == "list") {
        list_todos(todos);
        desired_operation = get_desired_operation();
    } else if(desired_operation == "edit") {
        edit_todo(todos);
        desired_operation = get_desired_operation();
    } else if(desired_operation == "delete") {
        delete_todo(todos);
        desired_operation = get_desired_operation();
    } else if(desired_operation == "clear") {
        clear_todos(todos);
        desired_operation = get_desired_operation();
    } else {
        throw_error();
        desired_operation = get_desired_operation();
    }
  }
  std::cout << "Program shutting down. Goodbye.";
  return 0;
};
