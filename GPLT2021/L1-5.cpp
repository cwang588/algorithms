#include<bits/stdc++.h>
using namespace std;
int a[35];
int main(){
	for(int i=1;i<=24;++i)cin>>a[i];
	int now;
	while(cin>>now){
		if(now<0||now>23)continue;
		++now;
		printf("%d ",a[now]);
		if(a[now]>50)printf("Yes\n");
		else printf("No\n");
	}
	
	return 0;
}
