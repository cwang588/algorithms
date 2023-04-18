#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	while(x<0||x>100){
		printf("Error! Please reinput!\n");
		cin>>x;
	}
	switch(x/10){
		case 10:cout<<"A";break;
		case 9:cout<<"A";break;
		case 8:cout<<"B";break;
		case 7:cout<<"C";break;
		case 6:cout<<"D";break;
		default:cout<<"E";break;
	}
	return 0;
}

