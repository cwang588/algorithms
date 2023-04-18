#include<bits/stdc++.h>
using namespace std;
int type[100005],pos[100005],a[100005],b[100005],c[100005];
string Hex[267];
void init(){
	for(int i=0;i<=15;++i){
		for(int j=0;j<=15;++j){
			int now=i*16+j;
			char tmp1,tmp2;
			if(i<10)tmp1='0'+i;
			else tmp1='A'+i-10;
			if(j<10)tmp2='0'+j;
			else tmp2='A'+j-10;
			string tmp;
			tmp.push_back(tmp1);
			tmp.push_back(tmp2);
		//	cout<<tmp;
			Hex[now]=tmp;
		//	cout<<now<<" "<<tmp<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.tie(0);
	init();
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int Max=0;
		for(int i=1;i<=n;++i){
			cin>>type[i];
			if(type[i]==1)Max=i;
			string s;
			cin>>s;
			if(s[0]>='A'&&s[0]<='Z')a[i]=s[0]-'A'+10;
			else a[i]=s[0]-'0';
			if(s[1]>='A'&&s[1]<='Z')a[i]=a[i]*16+s[1]-'A'+10;
			else a[i]=a[i]*16+s[1]-'0';
			if(s[2]>='A'&&s[2]<='Z')b[i]=s[2]-'A'+10;
			else b[i]=s[2]-'0';
			if(s[3]>='A'&&s[3]<='Z')b[i]=b[i]*16+s[3]-'A'+10;
			else b[i]=b[i]*16+s[3]-'0';
			if(s[4]>='A'&&s[4]<='Z')c[i]=s[4]-'A'+10;
			else c[i]=s[0]-'0';
			if(s[5]>='A'&&s[5]<='Z')c[i]=c[i]*16+s[5]-'A'+10;
			else c[i]=c[i]*16+s[5]-'0';
			a[i]+=a[i-1];
			b[i]+=b[i-1];
			c[i]+=c[i-1];
			pos[i]=Max;
		}
		for(int i=1;i<=m;++i){
			int l,r;
			cin>>l>>r;
			int nowpos=pos[r],tpos=max(nowpos,l-1);
			int toa=a[r]-a[tpos],tob=b[r]-b[tpos],toc=c[r]-c[tpos];
			if(l<=nowpos){
				toa+=a[nowpos]-a[nowpos-1];
				tob+=b[nowpos]-b[nowpos-1];
				toc+=c[nowpos]-c[nowpos-1];
			}
			toa=min(toa,255);
			tob=min(tob,255);
			toc=min(toc,255);
			cout<<Hex[toa]<<Hex[tob]<<Hex[toc]<<endl;
		}
	}
	return 0;
}
