#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
bool usd[105];
int a[105];
void dfs(int pre,int n){
	if(pre==n){
		for(int i=1;i<=n;++i)printf("%d ",a[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;++i){
		if(!usd[i]){
			a[pre+1]=i;
			usd[i]=true;
			dfs(pre+1,n);
			usd[i]=false;
		}
	}
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		int n=i+1;
		freopen(s1,"w",stdout);
		cout<<n<<endl;
		freopen(s2,"w",stdout);
		memset(usd,0,sizeof(usd));
		dfs(0,n);
	}
	return 0;
}
