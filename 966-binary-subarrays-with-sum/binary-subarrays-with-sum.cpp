class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> freq(goal+n+1, 0); //freq[goal+sum]= freq of sum 
        int sum=0, cnt=0;
        for(int x:nums){
            sum+=x;
            if(sum==goal) cnt++;
            if (freq[sum]!=0) 
                cnt+=freq[sum];//freq[sum]=freq of sum-goal
            freq[sum+goal]++;//freq[goal+sum]= freq of sum
        }
        return cnt;
    }
};