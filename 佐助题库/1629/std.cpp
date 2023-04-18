#include<bits/stdc++.h>
using namespace std;
char s1[]=" .in",s2[]=" .out";
int a[1005],b[1005];
char db[]={'C','R','F'};
bool check(long long x){
	for(long long i=2;i*i<=x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	srand((unsigned)time(0));
	for(int i=0;i<=9;++i){
		s1[0]=s2[0]=(char)(i+'0');
		freopen(s1,"w",stdout);
		int n=rand()%100+3;
		printf("%d\n",n);
		int tot=0,tot1=0,tot2=0,tot3=0;
		for(int j=1;j<=n;++j){
			a[j]=rand()%15+1;
			b[j]=rand()%3;
			cout<<a[j]<<" "<<db[b[j]]<<"\n";
			tot+=a[j];
			if(b[j]==0)tot1+=a[j];
			if(b[j]==1)tot2+=a[j];
			if(b[j]==2)tot3+=a[j];
		}		
		freopen(s2,"w",stdout);
		printf("Total: %d animals\n",tot);
		printf("Total coneys: %d\n",tot1);
		printf("Total rats: %d\n",tot2);
		printf("Total frogs: %d\n",tot3);
		printf("Percentage of coneys: %.2f \%\n",(double)tot1/(double)tot*100.0);
		printf("Percentage of rats: %.2f \%\n",(double)tot2/(double)tot*100.0);
		printf("Percentage of frogs: %.2f \%\n",(double)tot3/(double)tot*100.0);

		
	}
	return 0;
}
