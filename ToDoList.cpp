#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> tasks;

    bool run = true;

    while (run) {
        cout << "0. Exit." << endl;
        cout << "1. List all of my tasks." << endl;
        cout << "2. Add task." << endl;
        cout << "3. Remove task." << endl;

        string option;
        cin >> option;

        cout << endl;

        if (option == "0") {
            run = false;
        }
        else if (option == "1") {
            if (tasks.size() == 0) {
                cout << "No tasks to list." << endl;
                cout << endl;
                continue;
            }

            cout << "My tasks:" << endl;

            int i = 1;
            for (string task : tasks)
            {
                cout << i << ". " << task << endl;
                i++;
            }

            cout << endl;
        }
        else if (option == "2") {
            cout << "Task description:" << endl;

            string task;
            cin >> task;

            tasks.push_back(task);

            cout << "Task added." << endl;

            cout << endl;
        }
        else if (option == "3") {
            if (tasks.size() == 0) {
                cout << "No tasks to remove." << endl;
                cout << endl;
                continue;
            }

            cout << "Number of the task to remove:" << endl;

            string number;
            cin >> number;

            int index = stoi(number) - 1;

            if (index < 0 || index >(tasks.size() - 1)) {
                cout << "Number out of range." << endl;
                cout << endl;
                continue;
            }

            tasks.erase(tasks.begin() + index);

            cout << "Task removed." << endl;

            cout << endl;
        }
    }
}