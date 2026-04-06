#include <array>

class Solution {
public:
    struct ArrayHash {
        size_t operator()(const array<int, 26>& arr) const noexcept {
            size_t h = 0;
            for (int x : arr)
                h = h * 31 + x;  
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> grouped;
        unordered_map<array<int, 26>, vector<string>, ArrayHash> groups;
        for(string& str : strs){
            array<int, 26> count = {0};
            for(char c : str)
                count[c - 'a']++;
            
            groups[count].push_back(str);
        }
        for(auto& [_, group] : groups){
            grouped.push_back(move(group));
        }
        return grouped;

    }
};
