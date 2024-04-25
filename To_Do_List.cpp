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

    void viewTasks() {
        cout << "Tasks:" << endl;
        int count = 1;
        for (const Task& task : tasks) {
            cout << count++ << ". " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]" << endl;
        }
    }

    void markAsCompleted(int index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void removeTask(int index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\n==== ToDo List Manager ====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            continue; 
        }

        switch (choice) {
            case 1: {
                cin.ignore();
                string description;
                cout << "Enter task description: ";
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case 2:
                todoList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                if (!(cin >> index)) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    continue; 
                }
                todoList.markAsCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter the index of the task to remove: ";
                if (!(cin >> index)) {
                    cout << "Invalid input. Please enter a number." << endl;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue; 
                }
                todoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
