#include<bits/stdc++.h>
using namespace std;
vector<string>q[55],r[55];
int value[55],num[55];
bool check(int x,int y){
	memset(value,0,sizeof(value));
	for(int i=0;i<r[y].size();++i){
		for(auto s:q[x]){
			if(s==r[y][i]){
				value[i]=1;
				break;
			}
		}
	}
	stack<int>v,op;
	for(int i=0;i<r[y].size();++i){
		if(r[y][i]=="(")op.push(2);
		else if(r[y][i]==")"){
			while(!op.empty()&&op.top()!=2){
				int now=op.top();
				op.pop();
				int v1=v.top();
				v.pop();
				int v2=v.top();
				v.pop();
				if(now)v.push(v1&v2);
				else v.push(v1|v2);
			}
			op.pop();
		}
		else if(r[y][i]=="and")op.push(1);
		else if(r[y][i]=="or"){
			while(!op.empty()&&op.top()==1){
				op.pop();
				int v1=v.top();
				v.pop();
				int v2=v.top();
				v.pop();
				v.push(v1&v2);
			}
			op.push(0);
		}
		else v.push(value[i]);
	}
	while(!op.empty()){
		int now=op.top();
		op.pop();
		int v1=v.top();
		v.pop();
		int v2=v.top();
		v.pop();
		if(now)v.push(v1&v2);
		else v.push(v1|v2);
	}
	return v.top()==1;
}
int main(){
	int n,m;
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;++i){
		string tmp;
		getline(cin,tmp);
		int last=0;
		for(int j=0;j<=tmp.length();++j){
			if(j==tmp.length()||tmp[j]==' '){
				q[i].push_back(tmp.substr(last,j-last));
				last=j+1;
			}
		}
	}
	for(int i=1;i<=m;++i){
		string tmp;
		getline(cin,tmp);
		int last=0;
		for(int j=0;j<=tmp.length();++j){
			if(j==tmp.length()||tmp[j]==' '){
				string tmpnow=tmp.substr(last,j-last);
				if(tmpnow!="("&&tmpnow!=")"&&tmpnow!="and"&&tmpnow!="or")++num[i];
				r[i].push_back(tmpnow);
				last=j+1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		int Max=0,ans=0;
		for(int j=1;j<=m;++j){
			if(check(i,j)){
				if(Max<num[j]){
					Max=num[j];
					ans=j;
				}
			}
		}
		if(ans==0)cout<<"miss\n";
		else{
			for(auto s:r[ans])cout<<s<<" ";
			cout<<"\n";
		}
	}
	return 0;
}