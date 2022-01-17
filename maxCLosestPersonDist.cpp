class Solution {
public:

// https://leetcode.com/problems/maximize-distance-to-closest-person/

// long sub of 0
// length -> odd -> seq is touching some end point (0 or n-1) len - 1 + 1
// if len is even len/2 
// len is odd = len/2 + 1

    
    int midlen(vector<int> &seats){
        int ans = 0;
        int tmp = 0;
        for(int i=0;i<seats.size();i++){
            if(seats[i] == 0) tmp++;
            else{
                ans = max(ans, tmp);
                tmp = 0;
            }
        }
        
        return ans = max(tmp, ans);
        
    }
    
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        // check for bound points sublists:
        int slen = 0;
        for(int i=0;i<n;i++){
            if(seats[i] == 1) break;
            else slen++;
        }
        int elen = 0;
        for(int i=n-1;i>=0;i--){
            if(seats[i] == 1) break;
            else elen++;
        }
        
        int mlen = midlen(seats);
        
        int mans;
        if(mlen % 2 == 0) mans = mlen/2;
        else mans = mlen/2 + 1;

        return max(max(slen, elen), mans);
        
        // case where midlen > slen but still ans is slen
        // 1 0 0 0 0 1 0 0 0
        
    }
};