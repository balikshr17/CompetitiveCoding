#include <bits/stdc++.h>
using namespace std;

int main(){
	
	const int MAX=1000000;
	bool is_Prime[MAX+1];
	//memset(is_prime,true,sizeof(is_prime));
	for(int i=0;i<=MAX;i++) is_Prime[i]=true;
	is_Prime[0]=false;
	is_Prime[1]=false;
	for(int i=2;i*i<=MAX;i++){
		if(is_Prime[i]==true){
			for(int j=i*i;j<=MAX;j+=i)   is_Prime[j]=false;
		}
	} 
	//O(Nlog(logN))  
	
	vector<int> Tuples(MAX+1);
	Tuples[0]=Tuples[1]=Tuples[2]=Tuples[3]=0;
	for(int c=4;c<=MAX;c++){ //O(N);
		int b=c-2;
		Tuples[c]=Tuples[c-1];
		if(is_Prime[b]==true && is_Prime[c]==true){
Tuples[c]++;
}
	} 
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){  //O(t)
		int n;
		cin>>n;
		cout<<Tuples[n]<<endl; //O(1);
	}
	return 0;
}