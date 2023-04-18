#include<bits/stdc++.h>
using namespace std;
void* bkx(void*){
	long long ans=0;
	for(int i=1;i<=10000000;++i)ans+=i;
	return 0;
}
int main(){
	pthread_t tmp[10007];
	for(int i=1;i<=1000;++i){
		pthread_create(&tmp[i],NULL,bkx,NULL);
	}
	pthread_exit(NULL);
	
	return 0;
}