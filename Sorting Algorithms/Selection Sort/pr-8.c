#include<stdio.h>
#include<stdlib.h>
int count=0;

void swap(int *a,int *b)
{
int t=*a;
*a=*b;
*b=t;
}

void selectionsort(int *a,int n)
{
int i,j;
for(i=0;i<n-1;i++)
{
	for(j=i+1;j<n;j++)
	{
		count++;
		if(a[i]>a[j])
			swap(&a[i],&a[j]);
	}
}
}

void display(int *a,int n,FILE *fp)
{
for(int i=0;i<n;i++)
fprintf(fp,"%d ",a[i]);
}

void main()
{
int i,j,*a;
srand(0);
FILE *fp1,*fp2;
fp1=fopen("arraylist.txt","w");
fp2=fopen("count.txt","w");
fprintf(fp2,"N Count\n");
for(i=10;i<=100;i=i+10)
{
count=0;
a=(int*)malloc(sizeof(int)*i);
for(j=0;j<i;j++)
a[j]=(rand()%1000)+1;
fprintf(fp1,"Array before sorting: ");
display(a,i,fp1);
selectionsort(a,i);
fprintf(fp1,"\nArray aftre sorting: ");
display(a,i,fp1);
fprintf(fp2,"%d %d\n",i,count);
fprintf(fp1,"\n\n");
}
fclose(fp1);
fclose(fp2);
system("gedit arraylist.txt");
system("gedit count.txt");
system("gnuplot plot.gnu");
system("eog count.png");
}






