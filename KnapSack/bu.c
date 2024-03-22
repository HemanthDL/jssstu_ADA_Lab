#include<stdio.h>
#include<stdlib.h>
int ocount=0,ccount=0;
int max(int a,int b)
{
int t=(a>b)?a:b;
return t;
}

int knapsack(int n,int wt,int v[n+1],int w[n+1],int a[n+1][wt+1])
{
int i,j;
for(i=0;i<=n;i++)
a[i][0]=0;
for(j=0;j<=wt;j++)
a[0][j]=0;
for(i=1;i<=n;i++)
{
	for(j=1;j<=wt;j++)
	{
		ocount++;
		if(j-w[i]>=0)
			a[i][j]=max(a[i-1][j],(v[i]+a[i-1][j-w[i]]));
		else
			a[i][j]=a[i-1][j];
	}
}
/*for(int i=0;i<=n;i++)
{
	for(int j=0;j<=wt;j++)
		printf("%d ",a[i][j]);
	printf("\n");
}*/
return a[n][wt];
}
		
void composition(int n,int wt,int v[n+1],int w[n+1],int a[n+1][wt+1])
{
int k;
int i,j;
k=0;
j=wt;
int c[n+1];
for(i=n;i>=1;i--)
{
	ccount++;
	if(a[i][j]!=a[i-1][j])
	{
		c[k]=i;
		k++;
		j=j-w[i];
	}
}
printf("2.Composition for Optimal Solution: [ ");
for(i=0;i<k;i++)
	printf("item %d ",c[i]);
printf("]\n");
}	


void main()
{
int n;
int wt;
printf("Enter the number of items:");
scanf("%d",&n);
printf("Enter the maximum Weight capacity:");
scanf("%d",&wt);
int v[n+1],w[n+1];
int a[n+1][wt+1];
w[0]=0;
v[0]=0;
printf("Enter the details for ");
for(int i=1;i<=n;i++)
{
printf("\nitem-%d:\n",i);
printf("Weight: ");
scanf("%d",&w[i]);
printf("Value: ");
scanf("%d",&v[i]);
}
printf("\nFor given Knapsack Problem\n");
int os=knapsack(n,wt,v,w,a);
printf("1.Optimal Solution : %d\n",os);
composition(n,wt,v,w,a);
printf("Count for Optimal Solution: %d\n",ocount);
printf("Count for Composition of Optimal Solution: %d\n",ccount);
}
