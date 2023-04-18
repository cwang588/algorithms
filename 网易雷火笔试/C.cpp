#include<bits/stdc++.h>
using namespace std;
struct func{
	string name;
	int num;
	vector<int>cs;
};
unordered_map<int,func>id;
int trans(char x){
	if(x>='0'&&x<='9')return x-'0';
	else return 10+x-'A';
}
int calc(string s){
	int now=0;
	for(auto x:s){
		now=now*16;
		if(x>='0'&&x<='9')now+=x-'0';
		else now+=10+x-'A';
	}
	return now;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		string a,b;
		cin>>t>>a>>b;
		func tmp;
		tmp.name=a;
		tmp.num=0;
		tmp.cs.clear();
		for(auto c:b){
			if(c=='i')tmp.cs.push_back(0);
			else tmp.cs.push_back(1),++tmp.num;
		}
		id[t]=tmp;
	}
	string s;
	cin>>s;
	int now=0;
	while(now<s.length()){
		int nowid=trans(s[now++]);
		nowid=nowid*16+trans(s[now++]);
		cout<<id[nowid].name<<"(";
		queue<int>len;
		for(int i=1;i<=id[nowid].num;++i){
			int nowlen=trans(s[now++]);
			nowlen=nowlen*16+trans(s[now++]);
			len.push(nowlen);
		}
		for(int i=0;i<id[nowid].cs.size();++i){
			if(id[nowid].cs[i]==0){
				cout<<calc(s.substr(now,8));
				now+=8;
			}
			else{
				int nowlen=len.front();
				len.pop();
				cout<<"\""<<s.substr(now,nowlen*2)<<"\"";
				now+=nowlen*2;
			}
			if(i!=id[nowid].cs.size()-1)cout<<",";
		}
		cout<<")\n";
	}
	
	return 0;
}