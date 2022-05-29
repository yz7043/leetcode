class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int w = grid.size(); int h = grid[0].size();
        vector<vector<int>> st(w, vector<int>(h, -1));
        queue<vector<int>> q;
        q.push({0,0,k,0}); // i, j, k, step
        while(!q.empty()){
            vector<int> t = q.front(); q.pop();
            if(t[0] < 0 || t[0] >= w || t[1] < 0 || t[1] >= h)
                continue;
            if(grid[t[0]][t[1]] == 1){
                if(t[2] > 0){
                    t[2]--;
                }else
                    continue;
            }
            if(t[0] == w-1 && t[1] == h-1) return t[3];
            if(st[t[0]][t[1]] != -1 && st[t[0]][t[1]] >= t[2]) continue;
            st[t[0]][t[1]] = t[2];
            q.push({t[0]+1, t[1], t[2], t[3]+1});
            q.push({t[0], t[1]+1, t[2], t[3]+1});
            q.push({t[0]-1, t[1], t[2], t[3]+1});
            q.push({t[0], t[1]-1, t[2], t[3]+1});
        }
        return -1;
    }
};
