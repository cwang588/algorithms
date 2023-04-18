#include<bits/stdc++.h>
using namespace std;
int sum[405][405],suma[605][605],sumb[605][605];
char a[505][595];
int calc(int X1,int X2,int Y1,int Y2){
	int re=0;
	re+=sum[X2-1][Y2-1]-sum[X2-1][Y1]-sum[X1][Y2-1]+sum[X1][Y1];
	re+=sumb[X2-1][Y1]-sumb[X1][Y1]+sumb[X2-1][Y2]-sumb[X1][Y2];
	re+=suma[X1][Y2-1]-suma[X1][Y1]+suma[X2][Y2-1]-suma[X2][Y1];
	return re;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				sum[i][j]=suma[i][j]=sumb[i][j]=0;
				int num=a[i][j]-'0';
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num;
				suma[i][j]=suma[i][j-1]+1-num;
				sumb[i][j]=sumb[i-1][j]+1-num;
			}
		}
		int ans=20;
		for(int i=1;i<=n;++i){
			for(int j=i+4;j<=n;++j){
//				if(j-i<=40){
//					for(int l=1;l<=m;++l){
//						for(int r=l+3;r<=m;++r)ans=min(ans,calc(i,j,l,r));
//					}
//				}
				//else{
					int last=0;
					for(int k=1;k<=m;++k){
						if(suma[j-1][k]-suma[i][k]<=20){
							if(last>0&&k-last>=3)ans=ans=min(ans,calc(i,j,last,k));
							last=k;
						}
					}
	//			}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
