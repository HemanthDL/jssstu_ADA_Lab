#include<stdio.h>
#include<stdlib.h>
int v[15],n,a[20][20];
int stk[20],top=-1;
int count=0;

void checkdir()
{
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		if(a[i][j]&&a[j][i])
		{
			printf("Graph is Undirected\nTopological sorting is not possible\n");
			exit(0);
		}
	}
}
}

void checkcyc()
{
int i,j,k;
int r[n][n];
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
			r[i][j]=r[i][j]||(r[i][k]&&r[k][j]);
	}
}
for(i=0;i<n;i++)
{
	if(r[i][i])
	{
		printf("Graph is cyclic\nTopological sorting is not possible\n");
		exit(0);
	}
}
}

void dfs(int w)
{
v[w]=1;
for(int i=0;i<n;i++)
{
	count++;
	if(a[w][i]&&!v[i])
		dfs(i);
}
stk[++top]=w;
}

void main()
{
int i,j;
printf("Enter the number of vertices: ");
scanf("%d",&n);
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
{
	v[i]=0;
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
checkdir();
checkcyc();
printf("\nTopological Sorting:\n");
for(i=0;i<n;i++)
{
	if(!v[i])
		dfs(i);
}
for(i=top;i>=0;i--)
printf("%d ",stk[i]+1);
printf("\n");
printf("\nOperational Count: %d\n",count);
}
