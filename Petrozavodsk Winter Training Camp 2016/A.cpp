#include<bits/stdc++.h>
#define double long double
using namespace std;
const double eps=1e-2;
int solve(double a[][205],int n,int m){
	int rank=0, r=0;
	for(int i=0;i<m;++i){
		double mxv = eps;
		int mxcl = -1; 
		for(int j=r;j<n;++j){
			if(fabs(a[j][i])>mxv){
				mxcl = j;
			}
		}
		if(mxcl == -1){
			continue;
		} else {
			for (int k=i;k<m;++k)
				swap(a[mxcl][k], a[r][k]);
		}
		for(int j=0;j<n;++j){
			if(j!=r&&fabs(a[j][i])>eps){
				double tmp=a[j][i]/a[r][i];
				for(int k=i;k<=m;++k)a[j][k]-=tmp*a[r][k];
			}
		}
		++r;
		++rank;
	}
	return rank;
}
double a[205][205];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j)cin>>a[i][j];
	}
	cout<<solve(a,n,m); 
	return 0;
}
