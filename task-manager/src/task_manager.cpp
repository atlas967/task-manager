#include "task.h"
#include "task_manager.h"
#include <iostream>

void TaskManager::addTask(const std::string& title, Priority p, const std::string& due) {
    // Build a Task object using the arguments
    Task t;
    t.title = title;
    t.priority = p;
    t.due_date = due;
    t.done = false;

    // Assign it the current next_id_, then increment next_id_
    t.id = next_id_;
    next_id_++;

    // Push the task into tasks_
    tasks_.push_back(t);
}

void TaskManager::removeTask(int id)
{
    // Use std::remove_if with a lambda that checks task.id == id
    std::remove_if(tasks_.begin(), tasks_.end(), [id](const Task& t) { return t.id == id; });
    // Call tasks_.erase() on the result
    tasks_.erase(std::remove_if(tasks_.begin(), tasks_.end(), [id](const Task& t) { return t.id == id; }), tasks_.end());
    // If nothing matched, print an error message
    auto it = std::remove_if(tasks_.begin(), tasks_.end(), [id](const Task& t) { return t.id == id; });
    if (it == tasks_.end()) {
        std::cout << "Error: Task with ID " << id << " not found." << std::endl;
    } else {
        tasks_.erase(it, tasks_.end());
        std::cout << "Task deleted successfully." << std::endl;
    }
}

void TaskManager::markDone(int id)
{
    // Use std::find_if to search tasks_ for matching id
    auto it = std::find_if(tasks_.begin(), tasks_.end(), [id](const Task& t) { 
        return t.id == id; 
    });
    // If found, set task.done = true
    if (it != tasks_.end()) {
        it->done = true;
    } else {
        // If not found, print "Task not found"
        std::cout << "Task not found" << std::endl;
    }
}

void TaskManager::listTasks(bool show_done) const
{
    // Loop through tasks_ with a range-based for loop
    for (const Task& t : tasks_) {
        // If show_done is false, skip tasks where done == true
        if (!show_done && t.done) {
            continue;
        }

        // Print each task's id, title, priority, and status in a clean format
        std::cout << "[" << t.id << "] " 
                  << t.title 
                  << " | Priority: " << priorityToString(t.priority)
                  << " | Status: " << (t.done ? "Done" : "Pending") 
                  << std::endl;
    }
}

void TaskManager::sortByPriority()
{
    // Call std::sort on tasks_. Pass a lambda comparator that compares task.priority values
    std::sort(tasks_.begin(), tasks_.end(), [](const Task& a, const Task& b) {return a.priority > b.priority;});
}

const std::vector<Task> &TaskManager::getTasks() const
{
    // Just return tasks_ — no logic needed here
    return tasks_;
    // The const at the end means this function will not modify anything
}

void TaskManager::setTasks(std::vector<Task> loaded)
{
    tasks_ = loaded;
    for (const Task& t : tasks_) {
        if (t.id >= next_id_) next_id_ = t.id + 1;
    }
}
