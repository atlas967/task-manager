#include "storage.h"

const std::string FILE_PATH = "tasks.csv";

void Storage::saveTasks(const std::vector<Task> &tasks)
{
    std::ofstream file(FILE_PATH);
    if (!file) {
        return; 
    }
    for (const auto &t : tasks) {
        file << t.id << "," << t.title << "," << priorityToString(t.priority) << "," << t.done << "," << t.due_date << "\n";
    }
}

std::vector<Task> Storage::loadTasks()
{
    std::vector<Task> tasks;
    std::ifstream file(FILE_PATH);
    if (!file) {
        return tasks; 
    }
    std::string line;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string field;
        Task t;

        std::getline(iss, field, ',');
        t.id = std::stoi(field);
        
        std::getline(iss, field, ',');
        t.title = field;

        std::getline(iss, field, ',');
        t.priority = static_cast<Priority>(std::stoi(field));

        std::getline(iss, field, ',');
        t.done = std::stoi(field);

        std::getline(iss, field, ',');
        t.due_date = field;


        tasks.push_back(t);
    } 
    return tasks;
}
