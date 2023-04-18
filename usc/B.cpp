#include<bits/stdc++.h>
using namespace std;
int a[10005];
int getday(string s){
	int x=stoi(s.substr(0,2)),y=stoi(s.substr(3,2));
	int nowx=10,nowy=27,re=0;
	while(x!=nowx||y!=nowy){
		++re;
		++nowy;
		if(nowx==1||nowx==3||nowx==5||nowx==7||nowx==8||nowx==10||nowx==12){
			if(nowy==32){
				nowy=1;
				++nowx;
				if(nowx==13)nowx=1;
			}
		}else if(nowx==2){
			if(nowy==29){
				nowy=1;
				++nowx;
			}
		}else{
			if(nowy==31){
				nowy=1;
				++nowx;
			}
		}
	}
	return re;
}
string calc(int x){
	if(x<10){
		string re="0";
		re+=(char)(x+'0');
		return re;
	}
	return to_string(x);
}
string getdate(int re){
	if(re<0)re+=365;
	int nowx=10,nowy=27;
	while(re--){
		++nowy;
		if(nowx==1||nowx==3||nowx==5||nowx==7||nowx==8||nowx==10||nowx==12){
			if(nowy==32){
				nowy=1;
				++nowx;
				if(nowx==13)nowx=1;
			}
		}else if(nowx==2){
			if(nowy==29){
				nowy=1;
				++nowx;
			}
		}else{
			if(nowy==31){
				nowy=1;
				++nowx;
			}
		}
	}
	return calc(nowx)+"-"+calc(nowy);
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		string aa,bb;
		cin>>aa>>bb;
		a[i]=getday(bb);
	}
	sort(a+1,a+1+n);
	int ans=0,pos;
	for(int i=1;i<=364;++i){
		int Min=2147483647;
		for(int j=1;j<=n;++j){
			int now=(i-a[j]+365)%365;
			Min=min(Min,now);
		}
		if(Min>ans){
			ans=Min;
			pos=i;
		}
	}
	cout<<getdate(pos)<<"\n";
	return 0;
}