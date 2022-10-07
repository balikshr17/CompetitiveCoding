#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int parent[N];
int find(int a){
    if(a==parent[a]) return a;
    return find(parent[a]);
}

bool Union(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x==y) {
        return false;
    }
    parent[y]=x;
    return true;
}

int main(){
int n,e;
cin>>n>>e;
for(int i=0;i<n;i++) parent[i]=i;

set<pair<int,pair<int,int>>>st;
for(int i=0;i<e;i++){
    int x,y,wt;
    cin>>x>>y>>wt;
    // adj[x].push_back({y,wt});
    // adj[y].push_back({x,wt});
   st.insert({wt,{x,y}});
}
int wtsum=0;
while(st.size()>0){
    auto x=*(st.begin());
    st.erase(*(st.begin()));
    int wt=x.first;
    int n1=x.second.first;
    int n2=x.second.second;
    if(Union(n1,n2)==true) wtsum+=wt;
}

cout<<wtsum;

    return 0;
}