#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Single pass hashmap solution.
        unordered_map<int, int> num_to_index;    
        int temp_target;
        for (int i = 0; i < nums.size(); i++) {
            temp_target = target - nums[i];
            if (num_to_index.find(temp_target) != num_to_index.end()) {
                if (num_to_index[temp_target] != i) {
                    return {num_to_index[temp_target], i};
                }
            }
            num_to_index[nums[i]] = i;
        }
        return {};
    }
};
