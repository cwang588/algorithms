#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	cin>>c;
	double tot=0.0;
	for(int i=1;i<=12;++i)
		for(int j=1;j<=12;++j)
		{
			double t;
			cin>>t;
			if(i<j)tot+=t;
		}
	if(c=='M')tot/=66.0;
	printf("%.1f\n",tot);
	return 0;
} 
