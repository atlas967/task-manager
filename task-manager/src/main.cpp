#include <iostream>
#include "task.h"
#include "task_manager.h"
#include "storage.h"

int main(int argc, char* argv[]) {
    Storage storage;
    std::vector<Task> loadedTasks = storage.loadTasks();
    TaskManager manager;

    manager.setTasks(loadedTasks);

    if (argc == 1) {
        std::cout << "Usage:\n"
                  << "  task add \"title\"\n"
                  << "  task list\n"
                  << "  task done <id>\n"
                  << "  task rm <id>\n";
        return 1; 
    }
    std::string command = argv[1];

    if (command == "list") {
        manager.listTasks(true);
    } 
    else if (command == "add" && argc >= 3) {
        manager.addTask(argv[2], Priority::medium, "");
        storage.saveTasks(manager.getTasks());
    } 
    else if (command == "done" && argc >= 3) {
        manager.markDone(std::stoi(argv[2]));
        storage.saveTasks(manager.getTasks());
    } 
    else if (command == "rm" && argc >= 3) {
        manager.removeTask(std::stoi(argv[2]));
        storage.saveTasks(manager.getTasks());
    } else {
        // unknown command — print usage, return 1
        std::cout << "Usage:\n"
                  << "  task add \"title\"\n"
                  << "  task list\n"
                  << "  task done <id>\n"
                  << "  task rm <id>\n";
        return 1; 
    }

    return 0;
}