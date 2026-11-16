class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> let;
        int missing = 0;
        for(char c : t){
            let[c]++;
            if(let[c] == 1){
                missing++;
            }
        }
        int l = 0; int r = 0;
        int min = s.size()+1;
        int minl = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(let[s[i]]-- == 1){
                missing--;
                
            }
            while(1){
                if(let[s[l]] < 0){
                    let[s[l]]++;
                    l++;
                }else{
                    break;
                }
            }
            if(missing == 0 && i - l < min){
                min = i - l;
                minl = l;
            }
        }

        return missing == 0 ? s.substr(minl, min + 1) : "";
    }
};
