#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int parent[N];
int size[N];
void make(int v){
  parent[v]=v;
   
//    size of group 
  size[v]=1;

}

int find(int v){
   if(v==parent[v]) return v;

//    Path compression
   return parent[v]=find(parent[v]);

}

void Union(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x!=y){
        if(size[x]<size[y]) swap(a,b);
        parent[y]=x;
        size[a]+=size[b];
    }
}

int main(){



    return 0;
}

// Time Complexity - O(alfa(N)) - amortrized 