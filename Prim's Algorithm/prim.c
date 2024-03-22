#include<stdio.h>
#include<stdlib.h>
int count=0;

int minwt(int n,int wt[n+1],int v[n+1])
{
int val=100,min;
for(int i=1;i<=n;i++)
{
	if(!v[i]&&wt[i]<val)
	{
		val=wt[i];
		min=i;
	}
}
return min;
}


void displayprim(int n,int wt[n+1],int p[n+1],int s)
{
int sum=0;
printf("Minimum Spanning Tree Edges is as follows:\n");
printf("Vertices\tWeight\n");
for(int i=1;i<=n;i++)
{
	if(wt[i]!=99&&i!=s)
	{
		sum=sum+wt[i];
		printf("%d--%d\t    :\t   %d\n",p[i],i,wt[i]);
	}
}
printf("\nSum of Weight of Minimum Spanning tree : %d \n",sum);
}



void prim(int n,int a[n+1][n+1],int s)
{
int i,j,v[n+1],wt[n+1],p[n+1],u;
for(i=1;i<=n;i++)
{
	v[i]=0;
	wt[i]=99;
}
wt[s]=0;
p[s]=-1;
for(i=1;i<=n;i++)
{
u=minwt(n,wt,v);
v[u]=1;
for(j=1;j<=n;j++)
{
	count++;
	if(a[u][j]&&!v[j]&&a[u][j]<wt[j])
	{
		wt[j]=a[u][j];
		p[j]=u;
	}
}
}		
displayprim(n,wt,p,s);
}


void main()
{
int n,i,j;
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n+1][n+1];
printf("Enter the weight matrix(enter 99 for infinity):\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
}
int s;
printf("Enter the source vertex: ");
scanf("%d",&s);
prim(n,a,s);
printf("\nOperational Count: %d\n",count);
}
