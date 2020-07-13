class Solution {
public:
        
        vector<pair<int,double>>g[(int)1e6];
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back({edges[i][1],succProb[i]});
            g[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        
        double dis[n];
        
        for(int i=0;i<n;i++) dis[i]=0;
        
        dis[start]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        vector<int> vis(n,0);
        
        while(!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();
            
            if(vis[u]){
                continue;
            }
            vis[u]=1;
            
            for(auto v:g[u])
            {
                double wt=v.second;
                if(dis[u] * wt >= dis[v.first])
                {
                    dis[v.first]=dis[u] * wt;
                    pq.push({dis[v.first],v.first});
                }    
            }
        }
        
        return dis[end];
        
    }
};

//https://leetcode.com/contest/weekly-contest-197/problems/path-with-maximum-probability/
