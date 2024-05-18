//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr) 
    {
        int left=0;
       int right=arr.size()-1;
       int mid=0;
       int ans=0;
       
       while(left<=right){
           
           mid=left+(right-left)/2;
            if (mid==arr.size()-1){
                right=mid-1;
                continue;
            }
           if(arr[mid]>arr[mid+1]){
               right=mid-1;
           }
           else{
             left=mid+1;
           }
           
       }
       return arr[left];
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends