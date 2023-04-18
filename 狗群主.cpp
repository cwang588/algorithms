#include<iostream>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<cstdio> 
#define max 17
using namespace std;
int main()
{
	int temp=0;
	string all[18]={"喵内","咕咕咕","咕","咕咕","今晚可有猛男","我要涩图","这个好","@全体成员","今晚鸽了","老子要手办","死鸽子","guna","有什么好的番推荐马","出来挨打","？？？","不敢吱声","wor","劳资发表睿智深刻的言论的时候的帅气话语都没得了?"};
	cout<<"press Enter key to start......";
	getchar();
	while(1){
		temp=rand()%18;
		cout<<"狗群主："<<all[temp]<<endl;
		Sleep(100);
	}
	return 0;
}
