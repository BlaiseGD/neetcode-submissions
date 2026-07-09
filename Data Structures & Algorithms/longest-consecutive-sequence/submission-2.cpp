class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> numsSet(nums.begin(), nums.end());
        int tmp = 0;
        int count = 0;
        int tmpCount = 0;
        bool firstEl = true;
        for(const auto& value : numsSet){
            if((value == tmp+1) && firstEl == false){
                tmpCount++;
            }
            else{
                count = count = max(count, tmpCount);
                tmpCount = 1;
            }
            tmp = value;
            firstEl = false;
        }
        count = max(count, tmpCount);
        return count;
    }
};
