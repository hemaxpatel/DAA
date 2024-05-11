//0/1 knapsack
#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<pair<int, int>>> knapsack(vector<pair<int, int>>& objects, int W) {
    int n = objects.size();
    vector<vector<int>> table(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (objects[i - 1].first > j) {
                table[i][j] = table[i - 1][j];
            } else {
                table[i][j] = max(table[i - 1][j], objects[i - 1].second + table[i - 1][j - objects[i - 1].first]);
            }
        }
    }

    int max_value = table[n][W];
    vector<pair<int, int>> included_objects;
    int weight_remaining = W;
    for (int i = n; i > 0 && max_value > 0; --i) {
        if (max_value != table[i - 1][weight_remaining]) {
            included_objects.push_back(objects[i - 1]);
            max_value -= objects[i - 1].second;
            weight_remaining -= objects[i - 1].first;
        }
    }

    return make_pair(table[n][W], included_objects);
}

int main() {
    vector<pair<int, int>> objects = {{2, 12}, {1, 10}, {3, 20}, {2, 15}};
    int sack_capacity = 5;
    auto result = knapsack(objects, sack_capacity);
    cout << "Maximum value: " << result.first << endl;
    cout << "Included objects:" << endl;
    for (auto& obj : result.second) {
        cout << "Weight: " << obj.first << ", Value: " << obj.second << endl;
    }
    return 0;
}
