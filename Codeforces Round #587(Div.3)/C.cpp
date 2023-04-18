#include<bits/stdc++.h>
using namespace std;
int x[15],y[15];
int main(){
	for(int i=1;i<=6;++i)cin>>x[i]>>y[i];
	if(x[1]>=x[3]&&x[2]<=x[4]&&y[1]>=y[3]&&y[2]<=y[4])return !printf("NO\n");
	if(x[1]>=x[5]&&x[2]<=x[6]&&y[1]>=y[5]&&y[2]<=y[6])return !printf("NO\n");
	if(x[1]>=x[3]&&x[2]<=x[4]&&x[1]>=x[5]&&x[2]<=x[6]){
		if(y[1]>=y[3]&&y[4]>=y[5]&&y[2]<=y[6])return !printf("NO\n");
		else if(y[1]>=y[5]&&y[6]>=y[3]&&y[2]<=y[4])return !printf("NO\n");
		else return !printf("YES\n");
	}
	else if(y[1]>=y[3]&&y[2]<=y[4]&&y[1]>=y[5]&&y[2]<=y[6]){
		if(x[1]>=x[3]&&x[4]>=x[5]&&x[2]<=x[6])return !printf("NO\n");
		else if(x[1]>=x[5]&&x[6]>=x[3]&&x[2]<=x[4])return !printf("NO\n");
		else return !printf("YES\n");
	}
	else printf("YES\n");
	return 0;
}