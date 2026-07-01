class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> outVec;
        unordered_map<string, vector<string>> myMap;
        //general approach is use sorted string as key and unsorted string as values
        for(int i = 0; i < strs.size(); i++){
            string tmpUnsorted = strs[i];
            sort(strs[i].begin(), strs[i].end());
            myMap[strs[i]].push_back(tmpUnsorted);
        }
        //now have hash map with all the anagrams and the original values
        //go through each key in the hash map and output its vector
        for(const auto& kvp : myMap){
            outVec.push_back(kvp.second);
        }
        return outVec;

    }
};
