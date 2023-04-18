
#include<stdio.h>
#define MAX 15
int i,j,k,m[MAX][MAX],a[MAX][MAX],t[MAX][MAX],p,q,l;
int main() 
{
	
	printf("Please input the column and the row of the first and the second matrix:\n");
	scanf("%d %d %d",&p,&q,&l);
	printf("Please input the numbers of the firse matrix:\n");
	for(i=1;i<=p;i++)
	{
		for(j=1;j<=q;j++)
		{
		   scanf("%d",&m[i][j]);
	    }
	}
	printf("Please input the numbers of the second matrix:\n");
	for(j=1;j<=q;j++)
	{
		for(k=1;k<=l;k++)
		{
		   scanf("%d",&a[j][k]);
	    }
	}
	
	
	
	
	for(i=1;i<=p;i++)
    {
	    for(j=1;j<=q;j++)
	  {
		   printf("%5d",m[i][j]);
	  }
 	    printf("\n");
    }
    
    
    
    
    for(j=1;j<=q;j++)
    {
	    for(k=1;k<=l;k++)
	  {
		   printf("%5d",a[j][k]);
	  }
 	    printf("\n");
    }
	
	
	
	
	
	
	
	
    for(i=1;i<=p;i++)
    {
    	for(k=1;k<=l;k++)
    	{
           for(j=1;j<=q;j++)
    	   t[i][k]=t[i][k]+m[i][j]*a[j][k];
        }
    }
    for(i=1;i<=p;i++)
    {
	    for(k=1;k<=l;k++)
	  {
		   printf("%5d",t[i][k]);
	  }
 	    printf("\n");
    }
} 
