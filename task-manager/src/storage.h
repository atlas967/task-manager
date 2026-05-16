#include <vector>
#include <string>
#include "task.h"
#include <sstream>
#include <fstream>

#if !defined(STORAGE)
#define STORAGE

class Storage {
    public:
        void saveTasks(const std::vector<Task>& tasks);
        std::vector<Task> loadTasks();
};



#endif // STORAGE
