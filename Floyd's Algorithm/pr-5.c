#include<stdio.h>
#include<stdlib.h>
int count=0;
int min(int a,int b)
{
int t=(a>b)?b:a;
return t;
}
void floyd(int n,int a[n][n])
{
int i,j,k,d[n][n];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		d[i][j]=a[i][j];
}
for(k=0;k<n;k++)
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			count++;
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
}
printf("Shortest Path Matrix\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		printf("%d ",d[i][j]);
	printf("\n");
}
}
void main()
{
int i,j,n;
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n][n];
printf("Enter the weight matrix(enter 99 for infinity):\n");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
floyd(n,a);
printf("\nOperational Count: %d\n",count);
}


