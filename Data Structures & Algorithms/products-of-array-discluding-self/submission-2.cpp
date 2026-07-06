class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //1,2,4,6
        //for len array: add to sum the product of nums starting from the back
        //nums[i] = nums[0]
        // i = 0, product = 6 
        // i = 1, product = 24
        // i = 2, product = 48
        // i = 3, product = 48 because num.size() - i - 1 = 0, we don't multiply the beginning of array in this case
        
        //next iter same thing but nums[i] = nums[1], this runtime is O(n^2)
        //O(n^2) because outer for loop needed for total number of elements in array
        //inner loop needed to calc the product for each output element

        int product = 1;
        int zeroCount = 0;
        for(const auto& num : nums){
            if(num == 0){
                zeroCount++;
                continue;
            }
            product*=num;
        }
        if(zeroCount > 0){
                vector<int> ansVec(nums.size(), 0);
                if(zeroCount > 1) return ansVec;
                ansVec[distance(nums.begin(), find(nums.begin(), nums.end(), 0))] = product;
                return ansVec;
            }
        vector<int> ansVec;
        for(size_t i = 0; i < nums.size(); i++){
            ansVec.push_back(product / nums[i]);
        }
        return ansVec;
    }

};
