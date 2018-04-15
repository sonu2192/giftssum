#include<stdio.h>
#include<conio.h>
#include<string.h>
struct process
{
	char s_name[10];
	int at;
	int r;
	int totalbill;
	int giftnum;
	struct gname
	{
		char name[30];
		int value;
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
		s[i].totalbill=0;
	}
	for(i=0;i<n;i++)
	{
		printf("\nEnter the name of the student:");
		scanf("%s",&s[i].s_name);
		printf("\nEnter the arrival time of the student:");
		scanf("%d",&s[i].at);
		printf("\nEnter the number of the gifts:");
		scanf("%d",&s[i].giftnum);
		s[i].r=s[i].r;
		for(j=0;j<s[i].giftnum;j++)
		{
			printf("\nEnter the gift name::");
			fflush(stdin);
			scanf("%s",&s[i].g[j].name);
			printf("\nEnter the price of the gift::");
			scanf("%d",&s[i].g[j].value);
		}
		for(j=0;j<s[i].giftnum;j++)
		{
			s[i].totalbill=s[i].totalbill+s[i].g[j].value;    //total bill 
		}
	}
	for(k=0;k<n-1;k++)  //bubble sort
	{
		for(m=0;m<n-k-1;m++)
		{
			if(s[m].at>s[m+1].at)  //sorting according to the arrival time
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
			if((s[m].giftnum<s[m+1].at)&&(s[m].at==s[m+1].at))     //sorting of the structures with respect to number of gifts and arrival time
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
		printf("\n%s",&s[i].s_name);
		printf("\n\tTotal Bill:%d",s[i].totalbill);  //total bill for the items buyed by each students
	}
}
