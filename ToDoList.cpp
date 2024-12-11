#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string fileName = "tasks.txt";

vector<string> loadTasks() {
    vector<string> tasks;

    try {
        ifstream file(fileName);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                tasks.push_back(line);
            }
            file.close();
        }
    }
    catch (exception) {
        return tasks;
    }

    return tasks;
}

void saveTasks(vector<string> tasks) {
    try {
        ofstream file(fileName);

        if (file.is_open()) {
            for (string task : tasks)
            {
                file << task << endl;
            }
            file.close();
        }
    }
    catch (exception) {
        return;
    }
}

int main()
{
    vector<string> tasks = loadTasks();

    while (true) {
        cout << "0. Exit." << endl;
        cout << "1. List all of my tasks." << endl;
        cout << "2. Add task." << endl;
        cout << "3. Remove task." << endl;

        string option;
        cin >> option;

        cout << endl;

        if (option == "0") {
            return 0;
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

            saveTasks(tasks);

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

            saveTasks(tasks);

            cout << "Task removed." << endl;

            cout << endl;
        }
    }
}