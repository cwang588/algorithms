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
	string all[18]={"����","������","��","����","�����������","��Ҫɬͼ","�����","@ȫ���Ա","�������","����Ҫ�ְ�","������","guna","��ʲô�õķ��Ƽ���","��������","������","����֨��","wor","���ʷ��������̵����۵�ʱ���˧�����ﶼû����?"};
	cout<<"press Enter key to start......";
	getchar();
	while(1){
		temp=rand()%18;
		cout<<"��Ⱥ����"<<all[temp]<<endl;
		Sleep(100);
	}
	return 0;
}
