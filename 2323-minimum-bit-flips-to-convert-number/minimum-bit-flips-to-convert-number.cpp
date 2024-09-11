class Solution {
public:
    int minBitFlips(int start, int goal) { 
        
        int xorFlips = start ^ goal;
        int flips =0;
        
        while(xorFlips){
            flips += xorFlips & 1;

            xorFlips = xorFlips >> 1;
        }
        return flips;
         }
};