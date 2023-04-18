#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	int t;	
	scanf("%d",&t);
	while(t--){
		int n,p=0,q=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			if(!x)b[++q]=abs(y);
			else a[++p]=abs(x);
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		double ans=0.0;
		for(int i=1;i<=n;++i)
			ans+=sqrt((double)a[i]*a[i]+(double)b[i]*b[i]);
		printf("%.10f\n",ans);
	}
	return 0;
}
