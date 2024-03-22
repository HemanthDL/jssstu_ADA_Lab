#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int c=0;

void display(int *a,int n,FILE *fp)
{
for(int i=1;i<=n;i++)
fprintf(fp,"%d ",a[i]);
}

void heapifyheapsort(int *a,int n,int i)
{
bool heap;
int k=i,v=a[k],j;
heap=false;
c++;
while(!heap&&(2*k)<=n)
{
c++;
j=2*k;
if(j<=n)
{
	if((a[j]<a[j+1])&&((j+1)<=n))
		j=j+1;
	if(v>=a[j])
		heap=true;
	else
	{
		a[k]=a[j];
		k=j;
	}
}
a[k]=v;
}
}

void swap(int *a,int *b)
{
int t;
t=*a;
*a=*b;
*b=t;
}

void heapsort(int *a,int n)
{
int i,j;
for(i=(n/2);i>=1;i--)
heapifyheapsort(a,n,i);
for(i=n;i>1;i--)
{
swap(&a[i],&a[1]);
heapifyheapsort(a,i-1,1);
}
}


void main()
{
int *a,i,j;
FILE *fp,*lp;
fp=fopen("count.txt","w");
lp=fopen("list.txt","w");
srand(0);
fprintf(fp,"N B A W\n");
for(i=10;i<=100;i=i+10)
{
fprintf(fp,"%d ",i);
a=(int*)malloc(sizeof(int)*(i+1));
//best case
c=0;
for(j=1;j<=i;j++)
a[j]=(i+1)-j;
fprintf(lp,"Before SortingB: ");
display(a,i,lp);
heapsort(a,i);
fprintf(lp,"\nAfter SortingB: ");
display(a,i,lp);
fprintf(fp,"%d ",c);
//average case
c=0;
for(j=1;j<=i;j++)
a[j]=rand()%100;
fprintf(lp,"\nBefore SortingA: ");
display(a,i,lp);
heapsort(a,i);
fprintf(lp,"\nAfter SortingA: ");
display(a,i,lp);
fprintf(fp,"%d ",c);
//worst case
c=0;
for(j=1;j<=i;j++)
a[j]=j;
fprintf(lp,"\nBefore SortingW: ");
display(a,i,lp);
heapsort(a,i);
fprintf(lp,"\nAfter SortingW: ");
display(a,i,lp);
fprintf(fp,"%d\n",c);
fprintf(lp,"\n\n");
}
fclose(fp);
fclose(lp);
// system("gedit list.txt");
// system("gedit count.txt");
// system("gnuplot plot.gnu");
//system("eog count.png");
}
