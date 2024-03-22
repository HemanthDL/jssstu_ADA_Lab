#include<stdio.h>
#include<stdlib.h>
int count=0,stk[15],top=-1;

int min(int n,int d[n+1],int v[n+1])
{
int val=100,min;
for(int i=1;i<=n;i++)
{
	if(!v[i]&&d[i]<val)
	{
		min=i;
		val=d[i];
	}
}
return min;
}

void printdijkstra(int n,int d[n+1],int p[n+1],int s)
{
int i,j,q;
printf("\nSingle Source Shortest Paths are\n\n");
printf("source-destiney:   path\t\t: distance\n");
for(i=1;i<=n;i++)
{
	q=i;
	if(i!=s)
	{
		printf("  %d   -   %d    : %d - ",s,i,s);
		while(p[q]!=s)
		{
			stk[++top]=p[q];
			q=p[q];
		}
		while(top!=-1)
			printf("%d - ",stk[top--]);
		printf("%d \t: %d\n",i,d[i]);
	}
}
}


void dijkstra(int n,int a[n+1][n+1],int s)
{
int i,j,v[n+1],d[n+1],p[n+1],u;
for(i=1;i<=n;i++)
{
	v[i]=0;
	d[i]=99;
	p[i]=-1;
}
d[s]=0;
p[s]=-1;
for(i=1;i<=n;i++)
{
	u=min(n,d,v);
	v[u]=1;
	for(j=1;j<=n;j++)
	{
		count++;
		if(a[u][j]&&!v[j]&&d[u]+a[u][j]<d[j])
		{
			d[j]=d[u]+a[u][j];
			p[j]=u;
		}
	}
}
printdijkstra(n,d,p,s);
}


void main()
{
int n,s,i,j;
printf("Enter the number of vertices: ");
scanf("%d",&n);
int a[n+1][n+1];
printf("Enter the weight matrix(enter 99 for infinity):\n");
for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
		scanf("%d",&a[i][j]);
}
printf("Enter the source vertex: ");
scanf("%d",&s);
dijkstra(n,a,s);
printf("\nOperational Count: %d\n",count);
}



