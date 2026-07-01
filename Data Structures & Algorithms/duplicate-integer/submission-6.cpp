class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return false;
        
        //this is a hash table with collision, so you can iterate through and check count.
        unordered_set<int> dupeSet;
        //need to insert with 
        for(size_t i = 0; i < nums.size(); i++){
            if(dupeSet.count(nums[i]) == 1) return true;
            dupeSet.insert(nums[i]);
        }

        return false;
    }
};