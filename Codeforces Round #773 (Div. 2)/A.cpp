##include<bits/stdc++.h>
using namespace std;
double x[5],y[5];
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=1;i<=3;++i)cin>>x[i]>>y[i];
		x[4]=x[1],y[4]=y[1];
		x[0]=x[3],y[0]=y[3];
		double ans=0.0;
		for(int i=1;i<=4;++i){
			if(y[i]!=y[i+1]);
			else{
				if(y[i-1]<y[i])ans+=sqrt((x[i]-x[i+1])*(x[i]-x[i+1])+(y[i]-y[i+1])*(y[i]-y[i+1]));
			}
		}
		printf("%.13lf\n",ans);
	}
	
	
	return 0;
}