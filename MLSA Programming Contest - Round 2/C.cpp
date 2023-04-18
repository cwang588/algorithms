#include<bits/stdc++.h>
using namespace std;
char s[100005];
struct point{
	int num;
	char col;
}p[5006]; 
int main(){
	int n;
	cin>>n>>(s+1);
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(s[i]!=s[i-1]){
			++cnt;
			p[cnt].num=1;
			p[cnt].col=s[i];
		}
		else ++p[cnt].num;
	}
	long long ans=0;
	for(int i=1;i<=cnt;++i){
		int now=i;
		if(p[i].num<2)continue;
		long long tmp=p[i].num+1;
		for(int j=1;i>=j+1&&i+j<=n;++j){
			if(p[i-j].col!=p[i+j].col||p[i-j].num+p[i+j].num<3)break;
			tmp+=1ll*(j+1)*(p[i-j].num+p[i+j].num);
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
