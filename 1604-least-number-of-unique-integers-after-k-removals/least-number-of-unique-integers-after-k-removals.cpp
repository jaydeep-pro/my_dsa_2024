class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        arr.clear();

        for(auto it: mp){
            arr.push_back(it.second);
        }
        sort(arr.begin(), arr.end());
       int i= 0;
        while(k>0){
            if(k>= arr[i]){
                k = k- arr[i];
            }
            else{
                break;
            }

            i++;

        }
        return arr.size()-i;
    }
};