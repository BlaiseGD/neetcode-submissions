class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s;
        for(int i = 0; i < strs.size(); i++){
            s += (strs[i] + "😀");
        }
        cout << s;
        return s;
    }

    vector<string> decode(string s) {
        if(s.find("😀") == std::string::npos) return {};
        size_t position = 0;
        size_t found = s.find("😀", position);
        //smiley has weird size for some reason
        string smiley = "😀";
        vector<string> ansVec;
        //basically go through with find and every match, update substring to contain last smiley position to most recent smiley
        //multiple smileys at once means there is a blank string
        //😀😀hello😀world😀😀this😀😀😀
        //"" "" hello world "" this "" "" ""
        while(found != std::string::npos){
            if(found == position){
                ansVec.push_back("");
                position = found + smiley.size();
                found = s.find("😀", position);
                continue;
            }
               ansVec.push_back(s.substr(position, found - position));
               position = found+smiley.size();
               found = s.find("😀", position);
               cout << found << '\n';
        }
        ansVec[ansVec.size()-1] = ansVec[ansVec.size()-1].substr(0, ansVec[ansVec.size()-1].find("😀"));
        return ansVec;
    }
};
