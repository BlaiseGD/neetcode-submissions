class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //can't be the same so if target is six and first element is three can't return [1,1]
        //brute force is to go through the array for each index and add it until it equals target 
        //and then return indices 
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++){
            //store array values in hash map as key with index as value (bc it's what we're returning)
            //check if map has the difference value of the currentArrVal-target in it and that they have diff indexes
            //this ensures the two values add to target and have different indices
            
            if(myMap.count(target-nums[i])){
                return {myMap[target-nums[i]], i};
            }
            myMap[nums[i]] = i;
        }
        return {};
    }
};
