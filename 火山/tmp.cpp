#include<bits/stdc++.h>
using namespace std;
int Calendar2GpsTime (int nYear, int nMounth, int nDay, int nHour, int nMinute, double dSecond, double &WeekSecond)
{
	int DayofMonth = 0;
	int DayofYear = 0;
	int weekno = 0;
	int dayofweek;
	int m;
	if (nYear < 1980 || nMounth < 1 || nMounth > 12 || nDay < 1 || nDay > 31)  return -1;
	//�����1980�굽��ǰ��ǰһ�������
	for( m = 1980 ; m < nYear ; m++ )
	{
		if ( (m%4 == 0 && m%100 != 0) || (m%400 == 0) ) 
		{
			DayofYear += 366;
		}
		else
			DayofYear += 365;
	}
	//���㵱ǰһ���ڴ�Ԫ�µ���ǰǰһ�µ�����
	for( m = 1;m < nMounth; m++)
	{
		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			DayofMonth += 31;
		else if (m==4 || m==6 || m==9 || m==11) 
			DayofMonth += 30;
		else if (m ==2)
		{
			if ( (nYear%4 == 0 && nYear%100 != 0) || (nYear%400 == 0) )
				DayofMonth += 29;
			else 
				DayofMonth += 28;
				
		}
	}
	DayofMonth = DayofMonth + nDay - 6;//���ϵ�������/��ȥ1980��Ԫ�µ�6��		
	weekno = (DayofYear + DayofMonth) / 7;//����GPS��
	dayofweek = (DayofYear + DayofMonth) % 7;
	//����GPS ����ʱ��
	WeekSecond = 
		dayofweek*86400 + nHour*3600 + nMinute*60 + dSecond;
	return weekno;
}
int main(){
	double toe,t;
	Calendar2GpsTime(2018,1,23,4,0,0,toe);
	Calendar2GpsTime(2018,1,23,4,4,51,t);
	cout<<toe<<" "<<t;
}
