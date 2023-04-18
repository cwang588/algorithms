#include<bits/stdc++.h>
using namespace std;
char a[10005],b[10005];
int main(){
	//freopen("15791.in","r",stdin);
	//freopen("15791.out","w",stdout);
	cin>>(a+1)>>(b+1);
	int n=strlen(a+1),m=strlen(b+1);
	if(n<m){
		swap(n,m);
		swap(a,b);
	}
	for(int i=1;i<=n;++i)a[i+n]=a[i];
	for(int i=1;i+m-1<=2*n;++i){
		bool ky=true;
		for(int j=1;j<=m;++j){
			if(b[j]!=a[j+i-1]){
				ky=false;
				break;
			}
		}
		if(ky)return !printf("true\n");
	}
	printf("false\n");
	return 0;
}
