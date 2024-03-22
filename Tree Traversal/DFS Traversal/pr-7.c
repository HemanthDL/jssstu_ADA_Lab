/*
DFS Traversal

dfs()-to traverse graph in dfs order

connectivity()-- connectivity and check

checkdir()-- check whether graph is directed or undirected

cyclicity()-- for undirected--	ucyc()
	    	   for directed--	dcyc()

*/
#include<stdio.h>
#include<stdlib.h>

int count=0,n,s,cyc=0;

void dfs(int w,int a[n][n],int v[n])
{
v[w]=1;
printf("%d ",w+1);
for(int i=0;i<n;i++)
{
	count++;
	if(a[w][i]&&!v[i])
		dfs(i,a,v);
}
}

int check(int v[n])
{
for(int i=0;i<n;i++)
{
	if(v[i]==0)
	{
		s=i;
		return 1;
	}
}
return 0;
}

void connectivity(int a[n][n],int v[n],int w)
{
int flag,i,k;
flag=check(v);
if(!flag)
	printf("\nGraph is connected\n");
else
{
	printf("\nGraph is Disconnected\n");
	printf("Connected Components:");
	for(i=0;i<n;i++)
	v[i]=0;
	s=w;
	k=0;
	count=0;
	do
	{
		printf("\nComponent-%d: ",k+1);
		dfs(s,a,v);
		flag=check(v);
		k++;
	}while(flag);
	printf("\nNumber of Connected Components: %d\n",k);
}
}

int checkdir(int a[n][n])
{
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		if(a[i][j]&&a[j][i])
			return 1;
	}
}
return 0;
}
	
void ucyc(int a[n][n],int v[n],int w,int p)
{
v[w]=1;
for(int i=0;i<n;i++)
{
	if(a[w][i])
	{
		if(!v[i])
			ucyc(a,v,i,w);
		else if(p!=i)
			cyc=1;
	}
}
}

void dcyc(int a[n][n])
{
int i,j,k,r[n][n];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		r[i][j]=a[i][j];
}
for(k=0;k<n;k++)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			r[i][j]=(r[i][j]||(r[i][k]&&r[k][j]));
	}
}
for(i=0;i<n;i++)
{
	if(r[i][i])
	{
		printf("\nGraph is cyclic\n");
		return;
	}
}
printf("\nGraph is acyclic\n");
}

void main()
{
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n][n],i,j;
int v[n];
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
{	v[i]=0;
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
printf("Enter the source vertex: ");
int s;
scanf("%d",&s);
printf("DFS Traversal:\n");
dfs(s-1,a,v);
printf("\n");
connectivity(a,v,s-1);
if(checkdir(a))
{
	for(i=0;i<n;i++)
		v[i]=0;
	for(i=0;i<n;i++)
	{
		if(!v[i])
			ucyc(a,v,i,-1);
	}
	if(cyc)
		printf("Graph is Cyclic\n");
	else
		printf("Graph is Acyclic\n");	
}
else
	dcyc(a);
printf("\nOperational Count: %d\n",count);
}


