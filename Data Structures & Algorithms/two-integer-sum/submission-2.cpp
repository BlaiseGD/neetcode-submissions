class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //can't be the same so if target is six and first element is three can't return [1,1]
        //brute force is to go through the array for each index and add it until it equals target 
        //and then return indices

        if(nums.size() == 2) return {0,1};
        unordered_multimap<int, int> indexLookup;
        for(size_t i = 0; i < nums.size(); i++){
                indexLookup.insert({nums[i], i});
        }
        for(auto& kvp : indexLookup){
            //ex 7 and 4
            //7-4 = 3
            //look up the first key with value 3 in the unordered multimap
                auto range = indexLookup.equal_range(target - kvp.first);
                for(auto it = range.first; it != range.second; it++){
                    if(kvp.second != it->second) return (it->second > kvp.second) ? vector<int>{kvp.second, it->second} : vector<int>{it->second, kvp.second};
                }
                


        }
        return {};
    }
};
