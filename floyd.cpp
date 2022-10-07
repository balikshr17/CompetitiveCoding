#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    // vector<vector<pair<int,int>>>adj(n);
     int mx=100000000;
    vector<vector<int>>dist(n,vector<int>(n,mx));
    for(int i=0;i<e;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        dist[x][y]=wt;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
   
   for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
        if(dist[i][j]==mx) cout<<"I"<<" ";
        else cout<<dist[i][j]<<" ";
     }
     cout<<endl;
   }
    
    

}