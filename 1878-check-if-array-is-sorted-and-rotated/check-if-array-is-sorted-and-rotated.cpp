class Solution {
public:
    bool check(vector<int>& nums) {
       int i =0;
       for( i=0; i< nums.size() - 1 ;i++){
        if(nums[i] > nums[i+1]){
            break;
        }
       }

if( i == nums.size() - 1 ) return true;
if( (i != 0) &&(nums[0] < nums[nums.size() - 1])) return false;


       for(int j =i+1;j<nums.size()-1;j++){
        if((nums[j] > nums[j+1]) || (nums[0] < nums[nums.size() - 1])) return false;
       }

       

       return true;
    }
};