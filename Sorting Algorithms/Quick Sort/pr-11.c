#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
int count;
void print(int *a,int n)
{
for(int i=0;i<n;i++)
	fprintf(fp1,"%d ",a[i]);
}

void averagecaseinput(int *a ,int n)
{
for(int i=0;i<n;i++)
a[i]=rand()%100;
}

void worstcaseinput(int *a,int n)
{
a[0]=rand()%100;
for(int i=1;i<n;i++)
a[i]=a[i-1]+rand()%100;
}

void bestcaseinput(int *a,int n)
{
a[0]=rand()%100;
for(int i=1;i<n;i++)
a[i]=a[0];
}

void swap(int *b,int i,int j)
{
int t;
t=b[i];
b[i]=b[j];
b[j]=t;
}

/*int partition(int *a,int l,int r)
{
int p,i,j;
p=a[l];
i=l;
j=r+1;
do
{
	do
	{
		i++;
		count++;
	}while(a[i]<=p);
	do
	{
		j--;
		count++;
	}while(a[j]>=p);
	swap(a,i,j);
}while(i<=j);
swap(a,i,j);
swap(a,l,j);
return j;
}*/
int partition(int *a,int l,int r)
{
	int p,i,j;
	p=a[l];
	i=l;
	j=r+1;
	do
	{
		//count++;
		do
		{
			i++;
			count++;
		}while(p>a[i]&&i<=r);
		do
		{
			j--;
			count++;
		}while(p<a[j]&&j>l);
			swap(a,i,j);
	}while(i<=j);
	swap(a,i,j);
	swap(a,l,j);
	return j;
}

void quicksort(int *b,int l,int r)
{
	if(l<r)
	{
		int s=partition(b,l,r);
		quicksort(b,l,s-1);
		quicksort(b,s+1,r);
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
count=0;
fprintf(fp2,"%d ",i);
a=(int*)malloc(sizeof(int)*i);
bestcaseinput(a,i);
fprintf(fp1,"Array before sorting: ");
print(a,i);
quicksort(a,0,i-1);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d ",count);

count=0;
averagecaseinput(a,i);
fprintf(fp1,"\n\nArray before sorting: ");
print(a,i);
quicksort(a,0,i-1);
fprintf(fp1,"\nArray after sorting: ");
print(a,i);
fprintf(fp2,"%d ",count);

count=0;
worstcaseinput(a,i);
fprintf(fp1,"\n\nArray before sorting: ");
print(a,i);
quicksort(a,0,i-1);
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
