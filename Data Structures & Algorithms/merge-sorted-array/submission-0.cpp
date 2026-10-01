class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> ret;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                ret.push_back(nums1[i]);
                i++;
            }else{
                ret.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            ret.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            ret.push_back(nums2[j]);
            j++;
        }
        for(int i = 0; i < ret.size(); i++){
            nums1[i] = ret[i];
          
        }
    }
};