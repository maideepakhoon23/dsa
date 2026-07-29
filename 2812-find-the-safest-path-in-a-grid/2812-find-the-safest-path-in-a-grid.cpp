class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                   dis[nr][nc]==INT_MAX){

                    dis[nr][nc]=dis[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        // Max Heap
        priority_queue<vector<int>> pq;
        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({dis[0][0],0,0});

        while(!pq.empty()){

            auto cur=pq.top();
            pq.pop();

            int safe=cur[0];
            int r=cur[1];
            int c=cur[2];

            if(vis[r][c]) continue;
            vis[r][c]=1;

            if(r==n-1 && c==n-1)
                return safe;

            for(int k=0;k<4;k++){

                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){

                    pq.push({min(safe,dis[nr][nc]),nr,nc});
                }
            }
        }

        return 0;
    }
};