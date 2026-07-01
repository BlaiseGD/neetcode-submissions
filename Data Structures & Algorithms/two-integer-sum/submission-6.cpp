class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //can't be the same so if target is six and first element is three can't return [1,1]
        //brute force is to go through the array for each index and add it until it equals target 
        //and then return indices

        if(nums.size() == 2) return {0,1};
        //approach is to get subtract target from nums[i] to get what we need and look it up 
        unordered_map<int, int> myMap;
        for(int i = 0; i < nums.size(); i++){
            //index:value
            //0:3, 1:4, 2:5, 3:6  Target=7
            //difference from target value
            //4,3,2,1

            //0:4,1:5,2:6  Target = 10
            //6,5,4

            //0:5, 1:5  Target=10
            //5,5

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
