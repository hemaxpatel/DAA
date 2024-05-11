#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void printParentheses(vector<vector<int>>& brackets, int i, int j, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParentheses(brackets, i, brackets[i][j], name);
    printParentheses(brackets, brackets[i][j] + 1, j, name);
    cout << ")";
}

int matrixChainOrder(vector<pair<int, int>>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> brackets(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = numeric_limits<int>::max();
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i - 1].first * dimensions[k].second * dimensions[j].second;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }
    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printParentheses(brackets, 1, n - 1, name);
    cout << endl;
    return dp[1][n - 1];
}

int main() {
    vector<vector<pair<int, int>>> testCases = {
        {{0, 0}, {3, 5}, {5, 6}, {6, 4}},
        {{0, 0}, {30, 35}, {35, 15}, {15, 5}, {5, 10}, {10, 20}, {20, 25}}
    };

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test Case " << i + 1 << ":" << endl;
        int scalarMultiplications = matrixChainOrder(testCases[i]);
        cout << "Number of Scalar Multiplications: " << scalarMultiplications << endl << endl;
    }

    return 0;
}  
