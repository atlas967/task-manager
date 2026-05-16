#include <string>

#if !defined(TASK)
#define TASK

enum class Priority
{
    low = 0,
    medium = 1,
    high = 2
};

inline std::string priorityToString(Priority p) {
    if (p == Priority::high)   return "high";
    if (p == Priority::medium) return "medium";
    return "low";
}

struct Task {
    int id;
    std::string title;
    bool done = false;
    std::string due_date;
    Priority priority = Priority::medium;
};


#endif // TASK
