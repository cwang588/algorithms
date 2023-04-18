#include<bits/stdc++.h>
using namespace std;
int a[100005];
void init(){
	for(int i=0;i*i<=200000;++i){
		for(int j=1;j<=100000;++j){
			if(j<=i*i&&i*i-j<=j)a[j]=i*i-j;
		}
	}
}
int main(){
	init();
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>ans;
		int now=n-1;
		while(now>=0){
			for(int i=a[now];i<=now;++i)ans.push_back(i);
			now=a[now]-1;
		}
		reverse(ans.begin(),ans.end());
		for(auto x:ans)cout<<x<<" ";
		cout<<"\n";
	}
	
	return 0;
}