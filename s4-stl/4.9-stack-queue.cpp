#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Task
{
public:
    Task(string name) : name(name) {}

    void print()
    {
        cout << name << flush;
    }

private:
    string name;
};

int main()
{
    stack<Task> taskStack;

    taskStack.push(Task("Wash Dishes"));
    taskStack.push(Task("Take out trash"));
    taskStack.push(Task("Clean litter box"));

    while (taskStack.size() > 0)
    {
        taskStack.top().print();
        taskStack.pop();
        cout << endl;
    }

    cout << endl;

    queue<Task> taskQueue;

    taskQueue.push(Task("Wash Dishes"));
    taskQueue.push(Task("Take out trash"));
    taskQueue.push(Task("Clean litter box"));

    while (taskQueue.size() > 0)
    {
        taskQueue.front().print();
        taskQueue.pop();
        cout << endl;
    }
}
