class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        char curr;
        int min = 1000000000;
        for(int i = 0; i < strs.size(); i++){
            if(strs[i].size() < min){
                min = strs[i].size();
            }
        }
        for(int i = 0; i < min; i++){
            curr = strs[0][i];
            bool match = true;
            for(int j = 0; j < strs.size(); j++){
                if(strs[j][i] != curr){
                    match = false;
                    break;
                }
            }
            if(!match){
                return prefix;
            }else{
                prefix += curr;
            }
        }

        return prefix;
    }
};