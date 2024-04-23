// a simple console-based to-do list manager that allows users to add, view, and delete tasks
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits> 
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }
