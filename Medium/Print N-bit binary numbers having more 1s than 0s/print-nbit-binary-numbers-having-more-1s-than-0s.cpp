//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int num,int n,vector<string>&ans){
        string t="";
        int z=0,o=0;
        for(int i=n-1;i>=0;i--){
            if(num & 1<<i){
                o++;
                t+='1';
            }
            else{
                z++;
                t+='0';
            }
            if(z>o) return;
        }
        ans.push_back(t);
    }
    vector<string> NBitBinary(int n)
    {
        // Your code goes here
        int s=pow(2,n-1);  //start
        int e=pow(2,n)-1;   // end
        vector<string>ans;
        for(int i=e;i>=s;i--)
            solve(i,n,ans);   // check if valid number
        return ans;
    }


};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends