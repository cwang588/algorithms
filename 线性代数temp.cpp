#include <bits/stdc++.h>
using namespace std;

void zhuanzhi()
{
int a,b;
double **x,**p;
cout<<"����������������e79fa5e98193e58685e5aeb931333262383035��:";
cin>>a>>b;

x=new double *[a];
for(int i=0;i<a;i++)
x[i]=new double[b];
cout<<"�������ݣ�\n";
for(i=0;i<a;i++)
for(int j=0;j<b;j++)
cin>>x[i][j];
//////////////////////��ʼת�ã�
p=new double *[b];
for(i=0;i<b;i++)
p[i]=new double[a];

for(i=0;i<b;i++)
for(int j=0;j<a;j++)

//////////////////////////////���ת�þ���
for(i=0;i<b;i++)
{for(int j=0;j<a;j++)
cout<<p[i][j]<<'\t';
cout<<endl;
}
for(i=0;i<a;i++)

delete x;
delete p;
p=0;
x=0;

}
void jia()
{
int a1,b1,a2,b2;
double **x1,**x2;
cout<<"�����һ������������:";
cin>>a1>>b1;
cout<<"����ڶ�������������:";
cin>>a2>>b2;
if(a1!=a2 ||b1 !=b2) 
////x1[][]
x1=new double *[a1];
for(int i=0;i<a1;i++)
x1[i]=new double[b1];
cout<<"�����һ������\n";
for(i=0;i<a1;i++)
for(int j=0;j<b1;j++)
cin>>x1[i][j];
//////x2[][]
x2=new double *[a2];
for(i=0;i<a2;i++)
x2[i]=new double[b2];
cout<<"����ڶ�������\n";
for(i=0;i<a2;i++)
for(int j=0;j<b2;j++)
cin>>x2[i][j];
cout<<"��Ӻ�"<<endl;
for(i=0;i<a1;i++)
{
for(int j=0;j<b1;j++)
{
x1[i][j]+=x2[i][j];
cout<<x1[i][j]<<"\t";
}
cout<<endl;
}
for(i=0;i<a1;i++)

delete x1;x1=0;
delete x2;x2=0;
}
void jian()
{
int a1,b1,a2,b2;
double **x1,**x2;
cout<<"�����һ������������:";
cin>>a1>>b1;
cout<<"����ڶ�������������:";
cin>>a2>>b2;
if(a1!=a2 ||b1 !=b2) 
////x1[][]
x1=new double *[a1];
for(int i=0;i<a1;i++)
x1[i]=new double[b1];
cout<<"�����һ������\n";
for(i=0;i<a1;i++)
for(int j=0;j<b1;j++)
cin>>x1[i][j];
//////x2[][]
x2=new double *[a2];
for(i=0;i<a2;i++)
x2[i]=new double[b2];
cout<<"����ڶ�������\n";
for(i=0;i<a2;i++)
for(int j=0;j<b2;j++)
cin>>x2[i][j];
cout<<"�����"<<endl;
for(i=0;i<a1;i++)
{
for(int j=0;j<b1;j++)
{
x1[i][j]-=x2[i][j];
cout<<x1[i][j]<<"\t";
}
cout<<endl;
}
for(i=0;i<a1;i++)

delete x1;x1=0;
delete x2;x2=0;
}
void cheng()
{
int a1,b1,a2,b2;
double **x1,**x2;
cout<<"�����һ������������:";
cin>>a1>>b1;
cout<<"����ڶ�������������:";
cin>>a2>>b2;
if(b1!=a2) 
////x1[][]
x1=new double *[a1];
for(int i=0;i<a1;i++)
x1[i]=new double[b1];
cout<<"�����һ������\n";
for(i=0;i<a1;i++)
for(int j=0;j<b1;j++)
cin>>x1[i][j];
//////x2[][]
x2=new double *[a2];
for(i=0;i<a2;i++)
x2[i]=new double[b2];
cout<<"����ڶ�������\n";
for(i=0;i<a2;i++)
for(int j=0;j<b2;j++)
cin>>x2[i][j];
cout<<"��˺�"<<endl;
double **r=new double *[a1];
for(i=0;i<a1;i++)
r[i]=new double[b2];
////�˿�ʼ��
for(int q=0;q<a1;q++)
for(int w=0;w<b2;w++)
{
r[q][w]=0;
for(int j=0;j<b1;j++)
r[q][w]+=x1[q][j]*x2[j][w];
}
//���
for( q=0;q<a1;q++)
{
for(int w=0;w<b2;w++)
{
cout<<r[q][w]<<"\t"; 
}
cout<<endl;
}
for(i=0;i<a1;i++)

for(i=0;i<a2;i++)
delete []x2[i];
delete x1;x1=0;
delete x2;x2=0;
delete r;r=0;

}
int main()
{
int c=1;
while(c)
{
cout<<"*********************************************************\n";
cout<<"\t(1)ת��\n\t(2)����ӷ�\n\t(3)�������\n\t(4)����˷�\n\t(0)�˳�"<<endl;
cout<<"*********************************************************\n";
cin>>c;
switch(c)
{
case 0:break;
case 1:zhuanzhi();break;
case 2:jia();break;
case 3:jian();break;

case 4:cheng();break;
default:cout<<"Please retry!"<<endl;
}
}
return 0;
} 
