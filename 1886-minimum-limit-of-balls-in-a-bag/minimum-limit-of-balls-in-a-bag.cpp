class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int r=*max_element(nums.begin(),nums.end());
        int l=1;
        int res=r;
        while(l<r){
            int p=(l+r)/2;
            int op=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>p){
                    if(nums[i]%p==0){
                    op+=(nums[i]/p)-1;
                }
                else{
                    op+=nums[i]/p;
                }
                }

            }
            if(op<=maxOperations){
                res=p;
                r=p;
            }
            else{
                l=p+1;
            }

        }
        return res;


    }
};