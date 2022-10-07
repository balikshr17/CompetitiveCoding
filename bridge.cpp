#include<bits/stdc++.h>
using namespace std;
    
   void dfs( vector<vector<int>> &g,int parent,int &timer,int node,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&vis,vector<vector<int>>&res ){
        vis[node]=true;
        disc[node]=low[node]=timer++;
        for(auto x:g[node]){
            if(x==parent) continue;
            if(vis[x]==true){
                low[node]=min(low[node],disc[x]);
            }
            else{
                dfs(g,node,timer,x,disc,low,vis,res);
                low[node]=min(low[node],low[x]);
                if(low[x]>disc[node]){
                   vector<int>v;
                    v.push_back(node);
                    v.push_back(x);
                    res.push_back(v);
                }
            }
        }
        
        
    }

int main(){

int v,e;
cin>>v>>e;
vector<vector<int>>g(v+1);
for(int i=0;i<e;i++){
    int n1,n2;
    cin>>n1>>n2;
    g[n1].push_back(n2);
    g[n2].push_back(n1);
}

        vector<int>disc(v,-1);
        vector<int>low(v,-1);
        int timer=0;
        int parent=-1;
    unordered_map<int,bool>vis;
    vector<vector<int>>res;
        for(int i=0;i<v;i++){
            if(vis[i]==true) continue;
           dfs(g,parent,timer,i,disc,low,vis,res);
        }
 
    for(int i=0;i<res.size();i++) cout<<res[i][0]<<" "<<res[i][1]<<endl;


    return 0;
}