// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hours) {
        long long k = 1;
        
        int maxi = piles[0];
        for(auto x: piles) maxi = max(maxi, x);
        
        // O(N*logN):
        long long ans = INT_MAX;
        int l = 1;
        int h = maxi;
        
        while(l <= h){
            k = (h+l)/2;
            long long curHours = 0; 
            for(auto x: piles){
                if(x < k) curHours++;
                else{
                    curHours += int(x/k);
                    if(x%k) curHours++;
                }
            }

            if(curHours <= hours){
                ans = min(ans, k);
                h = k - 1;
            }
            else l = k+1;
        }
        
        // O(N*max)
//         while(k <= maxi){
//             long long curHours = 0;
            
//             for(auto x: piles){
//                 if(x < k) curHours++;
//                 else{
//                     curHours += int(x/k);
//                     if(x%k) curHours++;
//                 }
//             }

//             if(curHours <= h) return k;
//             else k++;
            
//         }
        
        return ans;
    }
};
