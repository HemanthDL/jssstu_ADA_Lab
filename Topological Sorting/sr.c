#include<stdio.h>
#include<stdlib.h>
int q[20],r=-1,f=0,nq=0;
int n,v[15],indg[15],count=0;

void chechdir(int a[n][n])
{
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		if(a[i][j]&&a[j][i])
		{
			printf("Graph is undirected\nTopological sorting not possible\n");
			exit(0);
		}
	}
}
}

void calind(int a[n][n])
{
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		indg[i]=indg[i]+a[j][i];
	}
}
}

void topo(int a[n][n])
{
int i,j,num=n;
int flag=0;
int s;
while(num>0)
{
	for(i=0;i<n;i++)
	{
		count++;
		if(!indg[i]&&!v[i])
		{
			q[++r]=i;
			v[i]=1;	
			flag=1;
			nq++;
		}
	}
	if(nq==0||flag==0)
	{
		printf("Topological Sorting not possible\n");
		exit(0);
	}
	nq--;
	s=q[f++];
	printf("%d ",s+1);
	indg[s]=-1;
	num--;
	for(j=0;j<n;j++)
	{
		if(a[s][j]==1)
		{
			indg[j]--;
			a[s][j]=0;
		}
	}
}
}
	



void main()
{
int i,j;
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n][n];
printf("Enter the adjacency matrix: ");
for(i=0;i<n;i++)
{	v[i]=0;
	indg[i]=0;
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
chechdir(a);
calind(a);
printf("Topological sorting:\n");
topo(a);
printf("\nOperational Count: %d\n",count);
}

