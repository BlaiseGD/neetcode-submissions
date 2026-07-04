class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s;
        for(string st : strs){
            s += (to_string(st.size()) + "#" + st);
        }
        return s;
    }

    vector<string> decode(string s) {
        size_t position = 0;
        size_t found = s.find("#", position);
        vector<string> ansVec;
       while(found != std::string::npos){
               ansVec.push_back(s.substr(found+1, stoi(s.substr(position, found - position))));
               position = found + stoi(s.substr(position, found - position)) + 1;
               found = s.find("#", position);
        }
        return ansVec;
    }
};
