class Solution {
public:
    bool isPalindrome(string s) {
        int position = s.length();
        string palinCheck;
        for(int i = 0; i < position; i++){
            if(!isalnum(s[i])){        
                s.erase(i,1);
                position--;
                i--;
                continue;
            }
            if(s[i] >= 48 && s[i] <= 57){
                    palinCheck = s[i] + palinCheck;
                    continue;
            }       
            palinCheck = (char)tolower(s[i]) + palinCheck;
            s[i] = tolower(s[i]);
           
        }
        cout << "palinCheck: " << palinCheck << "\ns: " << s << '\n';
        if(palinCheck == s) return true;
        return false;
    }
};
