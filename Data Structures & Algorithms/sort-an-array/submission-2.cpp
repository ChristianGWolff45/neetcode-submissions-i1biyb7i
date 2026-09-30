class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r){
            return;
        }
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        merge(nums, l, r, mid);
    }
    void merge(vector<int>& nums, int l, int r, int mid){
        int i = l;
        int j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= r){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i = 0; i < temp.size(); i++){
            nums[l+i] = temp[i];
        }

    }
};