// https://leetcode.com/problems/cherry-pickup-ii/

class Solution {
public:
    int dp[70][70][70] = {};
    int moves[3] = {-1, 0, 1};
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int m = grid.size(), n = grid[0].size();
        return helper(grid, m, n, 0, 0, n-1);        
    }
    
    int helper(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2){
        if(r == m) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        // calculate for current: if on same or different:-
        int ans = 0;
        if(c1 == c2) ans = grid[r][c1];
        else ans = grid[r][c2] + grid[r][c1];
        
        // find max for next step: cal for all possible cases:-
        // pairs of robot moves:
        int nex_ans = 0;
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                // new cols:
                int new_c1 = c1 + moves[i];
                int new_c2 = c2 + moves[j];
                
                // if in grid:
                if(new_c1 >=0 and new_c1 < n and new_c2 >=0 and new_c2 < n){
                    nex_ans = max(nex_ans, helper(grid, m, n, r+1, new_c1, new_c2));
                }
                    
            }
        }
        
        return dp[r][c1][c2] = ans + nex_ans;
        
    }
    
};