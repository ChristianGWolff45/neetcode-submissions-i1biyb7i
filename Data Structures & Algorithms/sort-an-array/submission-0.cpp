class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() -1);
        return nums;
    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);

    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int k = 0;
        int i = left;
        int j = mid + 1;
        while(i <= mid && j <= right){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
            k++;
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
            k++;
        }
        while(j <= right){
            temp.push_back(nums[j]);
            j++;
            k++;
        }
        for(int i = 0; i < temp.size(); i++){
            nums[i + left] = temp[i];
        }
    }
    

};