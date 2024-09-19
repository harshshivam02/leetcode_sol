class Solution {
public:
   bool dfs(vector<int>adj[],vector<int>&visi,vector<int>&pathvisi,vector<int >&check ,int node){
    pathvisi[node]=1;
    visi[node]=1;
    for(auto it : adj[node]){
        if(visi[it]==0){
            if(dfs(adj,visi,pathvisi,check,it)==true)return true;
        }
        else if(pathvisi[it])return true;
    }
    check[node]=1;
    pathvisi[node]=0;
    return false ;
   }
   
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();

        vector<int >adj[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>visi(n+1,0);
        vector<int>pathvisi(n+1,0);
        vector<int>check(n+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(visi[i]==0){
                dfs(adj,visi,pathvisi,check,i);
            }
        }
        for(int i=0;i<n;i++){
           if(check[i]==1){
            ans.push_back(i);
           }
        }
        return ans ;
    }
};