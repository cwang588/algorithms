	#include<bits/stdc++.h>
	using namespace std;
	long long a[200005];
	unordered_map<long long,bool>m;
	int main(){
		int t;
		scanf("%d",&t);
		while(t--){
			int n;
			scanf("%d",&n);
			m.clear();
			for(int i=1;i<=2*n;++i)scanf("%I64d",&a[i]);
			sort(a+1,a+1+2*n);
			bool ky=true;
			for(int i=1;i<=n;++i){
				if(a[i*2]!=a[i*2-1]){
					ky=false;
					break;
				}
			}
			if(!ky){
				printf("NO\n");
				continue;
			}
			long long tot=0;
			for(long long i=2*n;i>0;i-=2){
				if(a[i]<=2*tot||(a[i]-2*tot)%(i)!=0||m[((a[i]-2*tot)/(i))]||((a[i]-2*tot)/(i))==0){
					ky=false;
					break;
				}
				else{
					m[abs((a[i]-2*tot)/(i))]=true;
					tot+=abs((a[i]-2*tot)/(i));
				}
			}
			if(!ky)printf("NO\n");
			else printf("YES\n");
		}
		
		return 0;
	}
