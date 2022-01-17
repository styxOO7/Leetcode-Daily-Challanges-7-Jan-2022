class Solution {
public:
    int minJumps(vector<int> &a){
        int n = a.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            m[a[i]].push_back(i);
        }

        // for avoiding visiting the same index again and again:
        vector<int> vis(n, 0);
        int jumps = 0;

        // queue for maintaing bfs and levels:
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        // perform the three moves:
        bool stop = false;
        while(!q.empty()){
            int s = q.size();
            
            while(s--){
                int i = q.front();
                q.pop();

                // if reached at last index:
                if(i == n-1){
                    stop = true;
                    break;
                }

                // first two moves if not visited:
                if(i-1 >= 0 and vis[i-1] == 0){
                    vis[i-1] = 1;
                    q.push(i-1);
                }
                if(i+1 < n and vis[i+1] == 0){
                    vis[i+1] = 1;
                    q.push(i+1);
                }

                // third move - check at every same number:
                if(vis[i] == 0){
                    for(auto idx: m[a[i]]){
                        if(vis[idx] == 0){
                            q.push(idx);vis[idx] = 1;
                        }
                    }
                    m.erase(a[i]);
                }

            }

            if(stop) break;
            else jumps++;

        }

        return jumps;

    } 
};
