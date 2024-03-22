#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int count,countb;

void print(int *a,int n)
{
for(int i=0;i<n;i++)
fprintf(fp1,"%d ",a[i]);
}

void bestcaseinput(int *a,int n)
{
a[0]=rand()%100;
for(int i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
}

void averagecaseinput(int *a,int n)
{
for(int i=0;i<n;i++)
a[i]=rand()%100;
}

void worstcaseinput(int *a,int n)
{
a[n-1]=rand()%100;
for(int i=n-2;i>=0;i--)
a[i]=a[i+1]+rand()%100;
}

void insertionsort(int *a,int n)
{
int i,j,temp;
for(i=1;i<n;i++)
{
countb++;
j=i-1;
temp=a[i];
while(j>=0&&a[j]>temp)
{
count++;
a[j+1]=a[j];
j--;
}
a[j+1]=temp;
}
}


void main()
{
int i,j,k,*a;
srand(0);
fp1=fopen("list.txt","w");
fp2=fopen("count.txt","w");
fprintf(fp2,"N B A W\n");
for(i=10;i<=100;i=i+10)
{
countb=0;
fprintf(fp2,"%d ",i);
a=(int*)malloc(sizeof(int)*i);
bestcaseinput(a,i);
fprintf(fp1,"Array before sorting: ");
print(a,i);
insertionsort(a,i);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d ",countb);

count=0;
averagecaseinput(a,i);
fprintf(fp1,"\n\nArray before sorting: ");
print(a,i);
insertionsort(a,i);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d ",count);

count=0;
worstcaseinput(a,i);
fprintf(fp1,"\n\nArray before sorting: ");
print(a,i);
insertionsort(a,i);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d\n",count);
fprintf(fp1,"\n\n\n");
}
fclose(fp1);
fclose(fp2);
system("gedit list.txt");
system("gedit count.txt");
system("gnuplot plot.gnu");
system("eog count.png");
}
