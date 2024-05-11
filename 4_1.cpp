#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pile {
    double value; 
    double weight; 
};

double fractional_knapsack(int W, vector<Pile>& piles) {
    sort(piles.begin(), piles.end(), [](const Pile& a, const Pile& b) {
        return (a.value / a.weight) > (b.value / b.weight);
    });

    double max_value = 0;

    for (const auto& pile : piles) {
        if (W >= pile.weight) { 
            max_value += pile.value;
            W -= pile.weight;
        } else { 
            max_value += (W / pile.weight) * pile.value;
            break; 
        }
    }

    return max_value;
}

int main() {
    int W = 50; // Capacity of the bag
    vector<Pile> piles = {{60, 10}, {100, 20}, {120, 30}};
    double max_value = fractional_knapsack(W, piles);
    cout << "Maximum value of piles that the burglar can take: " << max_value << endl;
    return 0;
}
