class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for(string str : strs){
            encode += str.length();
            encode += str;
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;
        int index = 0;
        while(index < s.length()){
            int len = s[index];
            index += 1;
            decode.push_back(s.substr(index, len));
            index += len;
        }
        return decode;
    }
};
