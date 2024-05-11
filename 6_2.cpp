//optimal assigment
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Worker {
    string name;
    int cooking_time;
    int gardening_time;
    int cleaning_time;
};
int main() {
    vector<Worker> workers = {
        {"Amar", 2, 6, 7},
        {"Akbar", 4, 8, 3},
{"Anthony", 9, 5, 1}
    };
    int min_total_time = INT8_MAX;
    vector<int> optimal_assignment;
    vector<int> permutation = {0, 1, 2};
    do {
        int total_time = 0;
        for (int i = 0; i < workers.size(); ++i) {
            total_time += workers[i].cooking_time * (permutation[i] == 0);
            total_time += workers[i].gardening_time * (permutation[i] == 1);
            total_time += workers[i].cleaning_time * (permutation[i] == 2);
        }
        if (total_time < min_total_time) {
            min_total_time = total_time;
            optimal_assignment = permutation;
        }
    } while (next_permutation(permutation.begin(), permutation.end()));
    cout << "Optimal Job Assignment:" << endl;
    for (int i = 0; i < workers.size(); ++i) {
        cout << workers[i].name << " -> ";
        if (optimal_assignment[i] == 0)
            cout << "Cooking";
        else if (optimal_assignment[i] == 1)
            cout << "Gardening";
        else
            cout << "Cleaning";
        cout << endl;
    }
    cout << "Total Time: " << min_total_time << " hours" << endl;
    return 0;
}