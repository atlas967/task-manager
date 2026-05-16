#include <vector>
#include <string>
#include "task.h"

#if !defined(TASK_MANAGER)
#define TASK_MANAGER

class TaskManager {
    private:
        std::vector<Task> tasks_;
        int next_id_ = 1;
    public:
        void addTask(const std::string& title, Priority p, const std::string& due);
        void removeTask(int id);
        void markDone(int id);
        void listTasks(bool show_done) const;
        void sortByPriority();
        const std::vector<Task>& getTasks() const;
        void setTasks(std::vector<Task> loaded);
};

#endif // TASK_MANAGER
