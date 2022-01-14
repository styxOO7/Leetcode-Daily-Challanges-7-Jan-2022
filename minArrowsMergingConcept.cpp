// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Merging Problem:
bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans = 0;
        int arrow;
        
        sort(points.begin(), points.end(), cmp);
        
        for(int i=0;i<points.size();i++){
            int start = points[i][0];
            int end = points[i][1];
            
            if(ans == 0 or arrow < start){
                ans++;
                arrow = end;
            }
                
        }
        
        return ans;
        
    }
};