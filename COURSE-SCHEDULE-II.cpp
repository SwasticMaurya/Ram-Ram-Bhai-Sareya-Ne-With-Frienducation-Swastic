class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& a) {
        vector<int> ans;
        vector<int> topo;
        if(n==1){
            topo.push_back(0);
            return topo;
        }
        vector<int> ind(n,0);
        vector<int> g[n];
        for(auto it:a){
            g[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;++i){
            for(auto it:g[i]){
                ind[it]++;
            }
        }
        queue<int> q;
        
        for(int i=0;i<n;++i){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto child:g[node]){
                ind[child]--;
                if(ind[child]==0) q.push(child);
            }
        }
        if(topo.size()==n){
            return topo;
        }
        else return ans;
    }
};