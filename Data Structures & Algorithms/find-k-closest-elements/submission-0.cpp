class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() -1;
        vector<int> closest;
        while(r-l >= k){
            if(max(x - arr[l], arr[l] - x) > max(x - arr[r], arr[r] - x)){
                l++;
            }else{
                r--;
            }
        }
        while(l <= r){
            closest.push_back(arr[l]);
            l++;
        }
        return closest;
    }
};