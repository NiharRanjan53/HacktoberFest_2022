class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int, int>mp;
        for(int i = 0;i<nums.size();i++) {
            mp[nums[i]] = i;
        }
        for(int i = 0;i<operations.size();i++) {
            int value = operations[i][0];
            int index = mp[operations[i][0]];
            int new_value = operations[i][1];
            nums[index] = new_value;
            mp.erase(value);
            mp[new_value] = index;
        }
        return nums;
    }
};

// add all values in map
// find place of any element and update it
// remove previous value in map
// again update map
