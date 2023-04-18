#include<bits/stdc++.h>
using namespace std;
vector<int>to[15];
int a[15];
int country[15],league[15],team[15];
map<string,int>id1,id2,id3;
int cnt1,cnt2,cnt3;
bool check(int id){
	int now=a[id],tot=0;
	for(const auto &x:to[id]){
		int t=a[x];
		if(team[now]==team[t]&&country[now]==country[t])tot+=3;
		else if(league[now]==league[t]&&country[now]==country[t])tot+=2;
		else if(team[now]==team[t])tot+=2;
		else if(league[now]==league[t])tot+=1;
		else if(country[now]==country[t])tot+=1;
		else;
	}
	return to[id].size()<=tot;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		to[x+1].push_back(y+1);
		to[y+1].push_back(x+1);	
	}
	for(int i=1;i<=10;++i){
		string tmp,t1,t2,t3;
		cin>>tmp>>t1>>t2>>t3;
		if(!id1[t1])id1[t1]=++cnt1;
		if(!id2[t2])id2[t2]=++cnt2;
		if(!id3[t3])id3[t3]=++cnt3;
		country[i]=id1[t1];
		league[i]=id2[t2];
		team[i]=id3[t3];
	}
	for(int i=1;i<=10;++i)a[i]=i;
	bool ky=false;
	do{
		bool can=true;
		for(int i=1;i<=10;++i){
			if(!check(i)){
				can=false;
				break;
			}
		}
		if(can){
			ky=true;
			break;
		}
	}while(next_permutation(a+1,a+11));
	if(ky)cout<<"yes\n";
	else cout<<"no\n";
	return 0;
}