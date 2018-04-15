#include<stdio.h>
#include<conio.h>
#include<string.h>
struct process
{
	char name[10];
	int atime;
	int r;
	int bill;
	int tgifts;
	struct gifts
	{
		char name[30];
		int cost;
	}g[10];
}s[10];
struct process temp;
void main()
{
	int i,n,k,r,f,t=0,m,size=0,j,h;
	printf("\nEnter the number of students");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		s[i].bill=0;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter Student Name:");
		scanf("%s",&s[i].name);
		printf("\nEnter the arrival time of the student:");
		scanf("%d",&s[i].atime);
		printf("\nEnter the number of the gifts:");
		scanf("%d",&s[i].tgifts);
		s[i].r=s[i].r;
		for(j=0;j<s[i].tgifts;j++)
		{
			printf("\nEnter the gift name::");
			fflush(stdin);
			scanf("%s",&s[i].g[j].name);
			printf("\nEnter the price of the gift::");
			scanf("%d",&s[i].g[j].cost);
		}
		for(j=0;j<s[i].tgifts;j++)
		{
			s[i].bill=s[i].bill+s[i].g[j].cost;    //total bill 
		}
	}
	for(k=0;k<n-1;k++)  //bubble sort
	{
		for(m=0;m<n-k-1;m++)
		{
			if(s[m].atime>s[m+1].atime)  //sorting according to the arrival time
			{
				temp=s[m];
				s[m]=s[m+1];
				s[m+1]=temp;
			}
		}
	}
	for(k=0;k<n-1;k++)   //bubble sort
	{
		for(m=0;m<n-k-1;m++)
		{
			if((s[m].tgifts<s[m+1].tgifts)&&(s[m].atime==s[m+1].atime))     //sorting of the structures with respect to number of gifts and arrival time
			{
				
				temp=s[m];
				s[m]=s[m+1];
				s[m+1]=temp;
			}
		}
	}
	printf("\nThe order of billing is:\n");
	for(i=0;i<n;i++)
	{
		printf("\nStudent name:");
		printf("\n%s",&s[i].name);
		printf("\n\tTotal Bill:%d",s[i].bill);  //total bill for the items buyed by each students
	}
}
