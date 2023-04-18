#include<bits/stdc++.h>
using namespace std;
int a[200005],tmp[200005],value[105];
int main(){
	int now=1;
	value[0]=0,value[1]=1;
	for(int i=2;i<=25;++i)value[i]=value[i-1]*2;
	for(int i=0;i<=200000;++i){
		tmp[i]=now-i;
		if(now==i)now<<=1;
	}
	int t;
	cin>>t;
	while(true){
		int n=rand()%10+1;
		//cin>>n;
//		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)a[i]=rand()%n+1;
		sort(a+1,a+1+n);
		vector<int>num,sum;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i]!=a[i-1]){
				num.push_back(cnt);
				cnt=1;
			}
			else ++cnt;
		}
		num.push_back(cnt);
		sum.push_back(num[0]);
		int m=num.size();
		for(int i=1;i<m;++i)sum.push_back(sum[i-1]+num[i]);
		int ans=2147483647;
		for(int i=0;i<m;++i){
			int Min=2147483647;
			for(int j=0;j<=25;++j){
				int pos=lower_bound(sum.begin()+i+1,sum.end(),sum[i]+value[j])-sum.begin(); 
				if(pos==sum.end()-sum.begin())--pos;
				Min=min(Min,tmp[sum[pos]-sum[i]]+tmp[n-sum[pos]]);
			}
			ans=min(ans,Min+tmp[sum[i]]);
		}
		//cout<<ans<<"\n";
		int dpans=2147483647;
		for(int i=0;i<m;++i){
			for(int j=i;j<m;++j)dpans=min(dpans,tmp[sum[i]]+tmp[sum[j]-sum[i]]+tmp[n-sum[j]]);
		}
		if(ans==dpans)cout<<"AC\n";
		else{
			cout<<"sb!\n"<<n<<"\n";
			for(int i=1;i<=n;++i)cout<<a[i]<<" ";
			cout<<"\n"<<ans<<" "<<dpans<<"\n";
			break;
		}
	}
	
	return 0;
}