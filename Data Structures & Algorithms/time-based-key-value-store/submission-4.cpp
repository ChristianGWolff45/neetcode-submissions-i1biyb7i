class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> values;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        values[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!values.contains(key)){
            return "";
        }
        int l = 0; int r = values[key].size() - 1;
        int mid = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(timestamp == values[key][mid].first){
                return values[key][mid].second;
            }
            else if(timestamp < values[key][mid].first){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(mid == 0){
            return values[key][mid].first <= timestamp ? values[key][mid].second : "";
        }
        return values[key][mid].first <= timestamp ? values[key][mid].second : values[key][mid-1].second;
    }
};
