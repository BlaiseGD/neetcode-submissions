class Solution {
public:
    bool isPalindrome(string s) {
        int position = s.length();
        string palinCheck;
        for(int i = 0; i < position; i++){
            //if it's not alpha numeric, remove it from s and change index values
            if(!isalnum(s[i])){        
                s.erase(i,1);
                position--;
                i--;
                continue;
            }
            //check if number, no to lower
            if(s[i] >= 48 && s[i] <= 57){
                    palinCheck = s[i] + palinCheck;
                    continue;
            }       
            //tolower for string value and add character to palindrome
            palinCheck = (char)tolower(s[i]) + palinCheck;
            s[i] = tolower(s[i]);
           
        }
        //if palindrome, return true
        if(palinCheck == s) return true;
        return false;
    }
};
