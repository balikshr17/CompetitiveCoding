#include<bits/stdc++.h>
using namespace std;
const int inf=1e6;
unordered_map<int,bool>vis;
int mx=INT_MIN;
int sum=0;
void dfs(vector<vector<int>>&edges,int node,vector<int>&A){

  for(auto x:edges[node]){
    if(vis[x]) continue;
    vis[x]=true;
    sum+=A[x-1];
    mx=max(mx,A[x-1]);
    // cout << mx << " sum " << sum << endl;
    dfs(edges,x,A);
  }

}
 

int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>edges(n+1);
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    edges[u].push_back(v);
    edges[v].push_back(u);
}
vector<int>A(n);
// cout << "running" << endl;
for(int i=0;i<n;i++){
    // cout << "running 2" << endl;
    cin>>A[i];
}

int ans=0;
for(int i=1;i<=n;i++){
     mx=A[i-1];
     sum=A[i-1];
    if(vis[i]) continue;
    vis[i]=true;
    dfs(edges,i,A);
    // cout<<sum<<" "<<mx<<endl;
    ans=ans+(sum-mx);
}
cout<<ans;
    return 0;
}