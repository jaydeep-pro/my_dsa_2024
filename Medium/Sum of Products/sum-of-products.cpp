//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
     long long pairAndSum(int n, long long arr[]) {
        // code here
        long long ans=0;
        for(int i=0;i<31;i++){
             long long cnt=0;
             long long bitMask=(1<<i);
            for(int i=0;i<n;i++){
                if((arr[i]& bitMask)>0)cnt++;
            }
            long long pairs=cnt*(cnt-1)/2;
            if(pairs>0){
                bitMask*=pairs;
                ans+=bitMask;
            }
            // cout<<pairs<<"-->"<<ans<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends