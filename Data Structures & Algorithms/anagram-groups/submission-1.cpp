class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> outVec;
        unordered_map<string, vector<string>> myMap;
        //general approach is use sorted string as key and unsorted string as values
        for(string anagramString : strs){
            string tmpUnsorted = anagramString;
            sort(anagramString.begin(), anagramString.end());
            myMap[anagramString].push_back(tmpUnsorted);
        }
        //now have hash map with all the anagrams and the original values
        //go through each key in the hash map and output its vector
        for(auto& [key,val] : myMap){
            outVec.push_back(val);
        }
        return outVec;

    }
};
