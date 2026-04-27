#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> prevMap; // value : index

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            
            // Check if the complement exists in the map
            if (prevMap.find(diff) != prevMap.end()) {
                return {prevMap[diff], i};
            }
            
            // Otherwise, add current number to map
            prevMap[nums[i]] = i;
        }
        return {}; // Default return
    }
};

