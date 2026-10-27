class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> list;
        int complement = 0;

        for (int i = 0; i < nums.size(); i++){
            complement = target - nums[i];
            if (list.count(complement)){
                return {list[complement], i};
            }
            list[nums[i]] = i;
        }
        return{};
    }
};
