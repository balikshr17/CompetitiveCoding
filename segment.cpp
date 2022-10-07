#include<bits/stdc++.h>
using namespace std;
int a[100001],seg[400004];
void build(int ind,int low,int high){
    if(low==high){
        seg[ind]=a[low];
        return ;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
}
void sumsegmenttree(int indx,int low,int high){
    if(low==high){
        seg[indx]=a[low];
        return;
    }
    int mid=(low+high)>>1;
    sumsegmenttree(2*indx+1,low,mid);
    sumsegmenttree(2*indx+2,mid+1,high);
    seg[indx]=seg[2*indx+1]+seg[2*indx+2];
}
int update(int indx,int low,int high,int pos,int val){
    if(pos>high || pos<low) return seg[indx];
     if(low==high){
       return  seg[indx]=val;

     }
     int mid=(low+high)>>1;
     int left= update(2*indx+1,low,mid,pos,val);
     int right=update(2*indx+2,mid+1,high,pos,val);
     return left+right;
}
int sumquery(int indx,int low,int high,int l,int r){
    if(high<l || low>r) return 0;
    if(low==high) return seg[indx];
    int mid=(low+high)>>1;
   int left= sumquery(2*indx+1,low,mid,l,r);
    int right=sumquery(2*indx+2,mid+1,high,l,r);
  return left+right;
}
int query(int ind,int low,int high,int l,int r){
if(low>=l && high<=r){
    return seg[ind];
}
if(high<l || low>r) return INT_MIN;
int mid=(low+high)/2;
int left=query(2*ind+1,low,mid,l,r);   
int right=query(2*ind+2,mid+1,high,l,r);
return max(left,right);
}

int main(){
int n;
cin>>n;
for(int i=0;i<n;i++) cin>>a[i];

build(0,0,n-1);

// update(0,0,n-1,2,9);
// cout<<seg[2];
update(0,0,n-1,2,9);
int q;
cin>>q;
while(q--){
    int l,r;
    cin>>l>>r;
cout<<sumquery(0,0,n-1,l,r)<<endl;
}




    return 0;
}




