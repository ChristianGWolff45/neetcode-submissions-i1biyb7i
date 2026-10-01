class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(r > l){
            if(s[r] != s[l]){
                return palindrome(s.substr(l+1, r - l)) || palindrome(s.substr(l, r - l));
            }else{
                r--;
                l++;
            }
        }
        return true;
    }
    bool palindrome(string s){
        int l = 0; int r = s.size() - 1;
        while(r > l){
            if(s[l] != s[r]){

                return false;
            }
            l++;r--;
        }
        return true;
    }
};