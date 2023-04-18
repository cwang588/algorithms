#include<bits/stdc++.h>
using namespace std;
struct point{
	int id;
	char from,to;
}p[20005];
int cnt[35];
bool cmp1(point x,point y){
	return x.from<y.from;
}
bool cmp2(point x,point y){
	return x.id<y.id;
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		memset(cnt,0,sizeof(cnt));
		string s;
		cin>>s;
		for(int i=0;i<s.length();++i){
			++cnt[s[i]-'a'+1];
			p[i+1].id=i+1;
			p[i+1].from=s[i];
		}
		bool ky=true;
		for(int i=1;i<=26;++i){
			if(cnt[i]*2>s.length()){
				ky=false;
				break;
			}
		}
		printf("Case #%d: ",Case);
		if(!ky){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		sort(p+1,p+1+s.length(),cmp1);
		for(int i=1;i<=s.length()/2;++i){
			int l=i,r=i+(s.length()+1)/2;
			p[l].to=p[r].from;
			p[r].to=p[l].from;
		}
		if(s.length()%2){
			for(int i=1;i<=s.length();++i){
				if(p[i].from!=p[(s.length()+1)/2].from&&p[i].to!=p[(s.length()+1)/2].from){
					p[(s.length()+1)/2].to=p[i].to;
					p[i].to=p[(s.length()+1)/2].from;
					break;
				}
			}
		}
		sort(p+1,p+1+s.length(),cmp2);
		for(int i=1;i<=s.length();++i)cout<<p[i].to;
		cout<<"\n";
	}
	
	
	return 0;
}