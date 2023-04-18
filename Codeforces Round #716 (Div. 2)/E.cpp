#include<bits/stdc++.h>
using namespace std;
int a[105],ans[1005][1005];
bool dp[105][105],dpp[105][105];
int cnt;
bool cmp(int x,int y){
//	if(x==y)return false;
//	if(ans[x][y]>-1)return ans[x][y]==1?true:false;
//	cout<<'1'<<" "<<x<<" "<<y<<"\n";
//	fflush(stdout);
//	int re;
//	cin>>re;
//	ans[x][y]=re;
//	++cnt;
	++cnt;
	return ans[x][y]==1?true:false;
}
int main(){
//	for(int i=0;i<=100;++i){
//		for(int j=i;j<=100;++j)ans[j][i]=1;
//	}
	int t;
	cin>>t;
	while(t--){
		cnt=0;
		memset(dp,0,sizeof(dp));
		int n;
		n=100;
		//scanf("%d",&n);
		for(int i=0;i<n;++i){
			dpp[i][i]=true;
			for(int j=0;j<n;++j){
				ans[i][j]=-1;
				if(ans[j][i]!=-1)ans[i][j]=1-ans[j][i];
				else ans[i][j]=rand()%2;
//				char tt;
//				cin>>tt;
//				ans[i][j]=tt-'0';
				if(ans[i][j]==1)dpp[i][j]=true;
			}
		}
		for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					dpp[i][j]|=(dpp[i][k]&dpp[k][j]);
				}
			}
		}
		for(int i=0;i<n;++i)a[i+1]=i;
		stable_sort(a+1,a+1+n,cmp);
		int now=n;
		if(cnt>9*n){
			cout<<"bkx!\n"; 
		} 
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j)dp[a[i]][a[j]]=true;
		}
	//	printf("%d\n",cnt);
		cnt=0;
		for(int i=n;i>=1;--i){
			now=min(i,now);
			if(now==1)break;
			for(int j=now-1;j>=1;--j){
		//		cout<<'2'<<" "<<a[i]<<" "<<j<<" ";
		//		for(int k=1;k<=j;++k)cout<<a[k]<<" ";
		//		cout<<"\n";
				fflush(stdout);
				++cnt;
				int tmp=0; 
			//	cin>>tmp;
				for(int k=1;k<=j;++k){
					if(ans[a[i]][a[k]]==1){
						tmp=1;
						break;
					}
				}
				if(cnt>2*n){
					cout<<"bkx!\n";  
				} 
				if(!tmp){
//					dp[a[i]][a[j+1]]=true;
//					now=j+1;
					break;
				}
				now=j;
				dp[a[i]][a[j]]=true;
			}
		}
		bkx:cnt=0;
	    for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					dp[i][j]|=(dp[i][k]&dp[k][j]);
				}
			}
		}
	//	printf("3\n");
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
		//		if(dp[i][j])printf("1");
		//		else printf("0");
			}
		//	printf("\n");
		}
		bool ky=true;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
		//		if(dpp[i][j])printf("1");
		//		else printf("0");
				if(dpp[i][j]!=dp[i][j]){
					ky=false;
				}
			}
		//	printf("\n");
		}
		if(!ky)printf("sb!\n");
		else printf("nb!\n");
		fflush(stdout);
	}
	return 0;
}
