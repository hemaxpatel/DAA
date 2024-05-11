#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; 

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    cout<<"Given indices number are 2,7,11,15"<<endl<<"Target is 18"<<endl;
    vector<int> result = twoSum(nums, target);
    cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << endl;
    return 0;
}