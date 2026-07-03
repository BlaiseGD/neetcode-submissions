class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqList;
        unordered_map<int, vector<int>> ansList;
        set <int, greater<int>> uniqueCount;
        vector<int> ansVec;
        //store nums[i], count
        //return array 
       for(size_t i = 0; i < nums.size(); i++){
        //only has the highest count for each nums[i]
            freqList[nums[i]]++;
       } 
       for(const auto& kvp : freqList){
            //this has the reversed list with vector in case of duplicates with same count
            ansList[kvp.second].push_back(kvp.first);
            //has set so it's in order
            uniqueCount.insert(kvp.second);
       }

       //for the growing list of elements from highest count to lowest count > k
       //add to answervector and output

       while(ansVec.size() < k){
            auto& vec = ansList[*uniqueCount.begin()];
            if((ansVec.size() + vec.size()) > k){
                ansVec.insert(ansVec.end(), vec.begin(), vec.begin()+(k-ansVec.size()));
                return ansVec;
            }
            else{
                ansVec.insert(ansVec.end(), vec.begin(), vec.end());
            }
            uniqueCount.erase(uniqueCount.begin());
       }
       return ansVec;
    }
};
