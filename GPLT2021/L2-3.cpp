#include<bits/stdc++.h>
using namespace std;
vector<int>v;
void work(int pos){
	int tmp=v[pos]*v[pos+1];
	if(tmp<10)v.push_back(tmp);
	else{
		v.push_back(tmp/10);
		v.push_back(tmp%10);
	}
}
int main(){
	int a,b,n;
	cin>>a>>b>>n;
	int now=0;
	v.push_back(a);
	v.push_back(b);
	while(v.size()<n){
		work(now++);
	}
	for(int i=0;i<n;++i){
		printf("%d",v[i]);
		if(i!=n-1)printf(" ");
	}
	return 0;
}
