#include<stdio.h>
#include<stdlib.h>
int count=0;
void warshall(int n,int a[n][n])
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
		{
			count++;
			r[i][j]=(r[i][j]||(r[i][k]&&r[k][j]));
		}
	}
}
printf("Transitive Closure Matrix\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		printf("%d ",r[i][j]);
	printf("\n");
}
}
void main()
{
int i,j,n;
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n][n];
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(a[i][j]&&a[j][i])
		{
			printf("Warshall is not possible as graph is undirected\n");
			exit(0);
		}
	}
}
warshall(n,a);
printf("\nOperational Count: %d\n",count);
}


