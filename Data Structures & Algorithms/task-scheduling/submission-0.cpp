class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
                int taskCount[26] = {0};
                int numMax = 0;
                int indexMax = 0;
                for(auto task : tasks){
                        taskCount[task - 'A']++;
                        if(taskCount[task - 'A'] > taskCount[indexMax]){
                                indexMax = task - 'A';
                        }
                }
                for(auto count : taskCount){
                        if(count == taskCount[indexMax]){
                                numMax++;
                        }
                }

                return numMax + (n+1) * (taskCount[indexMax]-1) > tasks.size() ? numMax + (n+1) * (taskCount[indexMax]-1) : tasks.size();
        }
                                                                                                                
};