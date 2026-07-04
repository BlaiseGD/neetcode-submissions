class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s;
        for(int i = 0; i < strs.size(); i++){
            s += (to_string(strs[i].length())+ "#" + strs[i]);
        }
        cout << s;
        return s;
    }

    //5#hello12#memorization12
    //with this example we read until hashtag and subtract from that index the end of the prior string
    //denoted by the previous hashtag
    vector<string> decode(string s) {
        if(s == "") return {};
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
