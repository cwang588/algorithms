#include<bits/stdc++.h>
using namespace std;
vector<int>a[105];
void work(string &s,int id){
	s+="v";
	a[id].clear();
	int n=s.length(),num=0;
	bool neg=false;
	for(const auto &c:s){
		if(c=='~'){
			neg=true;
		}else if(c>='0'&&c<='9'){
			num=num*10+c-'0';	
		}else if(c=='v'){
			int now=2*num;
			if(neg)--now;
			a[id].push_back(now);
			neg=false,num=0;
		}else;
	}
}
int state[25],n,m;
bool check(){
	for(int i=1;i<=m;++i){
		bool ky=false;
		for(const auto &x:a[i]){
			if(state[(x+1)/2]!=x%2){
				ky=true;
				break;
			}
		}
		if(!ky)return false;
	}
	return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		getchar();
		string s;
		for(int i=1;i<=m;++i){
			getline(cin,s);
			work(s,i);		
		}
		bool ky=false;
		for(int i=0;i<(1<<n);++i){
			for(int j=0;j<n;++j){
				if(i&(1<<j))state[j+1]=1;
				else state[j+1]=0;
			}
			if(check()){
				ky=true;
				break;
			}
		}
		if(ky)cout<<"satisfiable\n";
		else cout<<"unsatisfiable\n";
	}
	
	return 0;
}