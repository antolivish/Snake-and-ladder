#include<stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
int i,j,k,y,largest;
int a[50],b[50];
int s=0;
int l=0;
int x=0;
// board
int n=30;
int m=1;
int p=7;
//int a[n];
for(i=1;i<=n;i++)
{ 
	a[i]=0;
}
 
 //ladder
 a[2] = 22;
 a[4] = 8;
 a[10] = 26;
 a[19] = 29;
 
 // Snakes
 a[26] = 1;
 a[20] = 10;
 a[16] = 4;
 a[18] = 7;

//declaring other cells
for(i=1;i<=n;i++)
{
	if(a[i]==0)
 	{
		a[i]=i+1;
 	}
}
for(i=1;i<=n;i++)
{
	printf("%d  ",a[i]);
	k++;
	if(k==6)
	{
		k=0;
		printf("\n");
 	}
}

//Counting num of snakes and ladder
for(i=1;i<=n;i++)
{
	if(a[i]>i+1)
 	{
		l++;
 	}
 	else if(a[i]<i+1)
 	{
 		 s++;
	}	
}
printf("\n\nThe no. of snakes and ladder is %d and %d \n", s,l);
largest=a[0];
//while(i<n)
//{
//	i=largest;
//	for(j=1;j<7;j++)
//	{
//		b[i]=a[i]+j;
//	}
//	//largest = a[0];
//	for (k=1;k<7;k++)
  //      {
    //    	if(largest<b[k])
//		{
  //      		largest=b[k];
//			x++;
  //      	}
////	i++;
//	}
//	

//}
i=1;
x=0;
printf("Steps are \n\n");
while(k<=30)
{
        for (k=m;k<p;k++)
        {
        	if(largest<a[k])
                {
                	largest=a[k];
			y=k;
                }
        }
        b[x]=largest;
	k=y;
	p=y+6;
	x++;
	printf("%d\t",k);
	printf("%d\t",x);
}
		
        


printf("Minimum steps is %d\n",x);
}
