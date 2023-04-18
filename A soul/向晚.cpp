#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int cnt;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=n;i>=1;--i){
		if(m>=i){
			v.push_back(i);
			m-=i;
			++cnt;
		}
	}
	if(!m){
		cout<<cnt<<endl;
		for(int i=0;i<cnt;++i)cout<<v[i]<<" ";
		cout<<endl;
	}
	else cout<<"It is raining!\n";
	return 0;
} 
