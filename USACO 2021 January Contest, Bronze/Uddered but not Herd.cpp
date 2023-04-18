#include<bits/stdc++.h>
using namespace std;
char a[55],b[10005];
int mm[55];
int main(){
	cin>>a>>b;
	int n=strlen(a),m=strlen(b),ans=1;
	for(int i=0;i<n;++i)
		mm[a[i]-'a']=i;
	for(int i=1;i<m;++i)if(mm[a[i]-'a']<=mm[a[i-1]-'a'])++ans;
	printf("%d\n",ans);
	return 0;
}
