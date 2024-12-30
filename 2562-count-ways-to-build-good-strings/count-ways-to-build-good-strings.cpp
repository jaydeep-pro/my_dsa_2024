class Solution {
public:
  int mod = 1000000007;
  
  int solve(int end , int zero, int one , vector<int> &dp){
      if(dp[end] != -1) return dp[end];

      int count =0;
      if(end>=one){
          count+=solve(end-one, zero, one ,dp);
      }
      if(end>=zero){
          count+=solve(end-zero, zero, one , dp);
      }
      dp[end]=count%mod;
      return dp[end];
  }
    int countGoodStrings(int low, int high, int zero, int one) {
      
        vector<int> dp(high+1 , -1);
        dp[0]=1;
        int ans=0;
        for(int i=low;i<=high;++i){
            ans+=solve(i, zero, one , dp);
            ans %= mod;
        }
           return ans;
    }
};