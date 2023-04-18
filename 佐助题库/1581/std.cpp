#include<bits/stdc++.h>
using namespace std;
char s[10005],s1[10005],s2[10005];
int main(){
	//freopen("15815.in","r",stdin);
	//freopen("15815.out","w",stdout);
	scanf("%s",s);
	int len=strlen(s),cnt=0,pos1=0,pos2=0;
	for(int i=0;i<len;++i){
		if(s[i]==','){
			++cnt;
			if(!pos1)pos1=i;
			else pos2=i;
			continue;
		}
		if(cnt==1)s1[i-pos1-1]=s[i];
		if(cnt==2)s2[i-pos2-1]=s[i];
	}
	int n=strlen(s1),m=strlen(s2);
	len-=n+m+2;
	int ans=0;
	for(int i=0;i+n+m-1<len;++i){
		bool ky=true; 
		for(int j=0;j<n;++j){
			if(s[i+j]!=s1[j]){
				ky=false;
				break;
			}
		}
		if(!ky)continue;
		for(int j=len-m;j>=i+n;--j){
			ky=true;
			for(int k=0;k<m;++k){
				if(s[j+k]!=s2[k]){
					ky=false;
					break;
				}
			}
			if(ky){
				ans=max(ans,j-(i+n));
				break;	
			}
		}
	} 
	if(!ans)printf("-1");
	else printf("%d\n",ans);
	return 0;
}
