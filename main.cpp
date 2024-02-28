#include <iostream>
#include <vector>

std::string get_desired_operation() {
  std::cout << "Please enter one of the following todo operations:" << std::endl;
  std::cout << "add, list, edit, delete or exit." << std::endl;
  std::string desired_operation;
  getline(std::cin, desired_operation);
  // std::cin >> desired_operation;
  return desired_operation;
};

std::string get_todo() {
  std::cout << "Please enter a new todo:" << std::endl;
  std::string new_todo;
  getline(std::cin, new_todo);
  // std::cin >> new_todo;
  return new_todo;
};

void list_todos(std::vector<std::string> const &todos) {
  std::cout << "\n-----------------------------" << std::endl;
  std::cout << "The current todos are as follows:" << std::endl;
  for(auto todo: todos) {
    std::cout << todo << std::endl;
  }
  std::cout << "-----------------------------\n\n";
};

void throw_error() {
  std::cout << "\n-----------------------------" << std::endl;
  std::cout << "ERROR! ERROR! INVALID INPUT!" << std::endl;
  std::cout << "-----------------------------\n\n";
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
    } else {
        throw_error();
        desired_operation = get_desired_operation();
    }
  }
  std::cout << "Program shutting down. Goodbye.";
  return 0;
};
