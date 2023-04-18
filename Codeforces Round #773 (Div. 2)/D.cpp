#include<bits/stdc++.h>
using namespace std;
int a[1005],tmp[1005];
struct op{
	int pos,c;
};
unsigned long long Hash[1005];
unsigned long long mod[2000005];
unsigned long long mi[2000005];
unsigned long long calc(int l,int r){
	return Hash[r]-Hash[l-1]*mi[r-l+1];
}
void init(){
	mi[0]=1;
	for(int i=1;i<=10000;++i)
		mi[i]=mi[i-1]*19260817;
}
int main(){
	int t;
	cin>>t;
	init();
	bkx:while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		stack<int>s;
		vector<op>ans;
		for(int i=1;i<=n;++i){
			if(s.empty())s.push(a[i]);
			else{
				if(s.top()==a[i])s.pop();
				else s.push(a[i]);
			}
		}
		int m=s.size();
		for(int i=m;i>=1;--i){
			tmp[i]=s.top();
			s.pop();
		}
		for(int i=1;i<=m;++i)Hash[i]=Hash[i-1]*19260817+tmp[i];
		for(int i=1;i<=m;){
			bool ky=false;
			for(int j=i+1;j*2-i-1<=m;++j){
				if(tmp[i]==tmp[j]&&calc(i,j-1)==calc(j,2*j-i-1)){
					ky=true;
					i=2*j-i;
					break;
				}
			}
			if(!ky){
				cout<<"-1\n";
				goto bkx;
			}
		}
		cout<<"nb\n";
	}
	
	
	return 0;
}