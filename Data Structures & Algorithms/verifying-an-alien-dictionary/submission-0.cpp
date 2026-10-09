class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> letter;
        for(int i = 0; i < order.size(); i++){
            letter[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; i++){
            int j = 0;
            while(j < words[i].size() && j < words[i+1].size()){
                if(words[i][j] != words[i+1][j]){
                    if(letter[words[i][j]] > letter[words[i+1][j]]){
                        
                        return false;
                    }else{
                        break;
                    }
                }
                j++;
            }
            if(j >= words[i+1].size()){
                if(words[i].size() > words[i+1].size()){
                    return false;
                }
            }
            
        }
        return true;
    }

};