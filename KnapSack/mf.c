#include<stdio.h>
#include<stdlib.h>
int n,wt;
int oc=0,cc=0;

int max(int a,int b)
{
int t=(a>b)?a:b;
return t;
}

int mfk(int i,int j,int n,int v[n+1],int w[wt+1],int wt,int a[n+1][wt+1])
{
if(a[i][j]==-1)
{
	oc++;
	int vl;
	if(j-w[i]>=0)
		vl=max(mfk(i-1,j,n,v,w,wt,a),v[i]+mfk(i-1,j-w[i],n,v,w,wt,a));
	else
		vl=mfk(i-1,j,n,v,w,wt,a);
	a[i][j]=vl;
	return a[i][j];
}
}

void composition(int v[n+1],int w[n+1],int a[n+1][wt+1])
{
int k=0;
int c[n+1];
int j=wt;
for(int i=n;i>=1;i--)
{
	cc++;
	if(a[i][j]!=a[i-1][j])
	{
		c[k++]=i;
		j=j-w[i];
	}
}
printf("2.Composition for Optimal Solution [ ");
for(int i=0;i<k;i++)
printf("item %d ",c[i]);
printf("]\n");
}

void main()
{
printf("Enter the number of items:");
scanf("%d",&n);
printf("Enter the maximum Weight capacity:");
scanf("%d",&wt);
int v[n+1],w[n+1],a[n+1][wt+1];
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
for(int i=0;i<=n;i++)
{
	for(int j=0;j<=wt;j++)
	{
		if(i==0||j==0)
		a[i][j]=0;
		else
		a[i][j]=-1;
	}
}
/*for(int i=0;i<=n;i++)
{
	//a[i]=(int*)malloc(sizeof(int)*(n+1));
	for(int j=0;j<=wt;j++)
	{
		printf("%d ",a[i][j]);
	}
	printf("\n");
}*/
//printf("%d\n",a[n][wt]);
printf("\nFor given Knapsack Problem\n");
printf("1.Optimal Solution : %d\n",mfk(n,wt,n,v,w,wt,a));
composition(v,w,a);
printf("Count for Optimal Solution: %d\n",oc);
printf("Count for Composition of Optimal Solution: %d\n",cc);
}



