class Solution {
public:
    int minOperations(vector<string>& logs) {
        int counting =0;

        for(int i=0;i<logs.size();i++){
            if(logs[i] == "../") {
                if(counting > 0) {
                    counting--;
                }
            }
            else if(logs[i] == "./"){
                
            }
            else{
                counting++;
            }
        }
        return counting;
    }
};