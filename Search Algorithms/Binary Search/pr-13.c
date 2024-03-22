#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
#define z 10
int count;
FILE *fp1,*fp2;
void printfile(int*,int,int);
int binarysearch(int*,int,int,int);
void main()
{
    srand(0);
    int *a,key,j,pos;
    fp1=fopen("binarylist.txt","w");
    fp2=fopen("binarycount.txt","w");
    fprintf(fp2,"N B W A\n");
    for(int i=x;i<=y;i=i+z)
    {
    	count=0;
        a=(int*)malloc(i*sizeof(int));
        a[0]=(rand()+1)%1000;
        for(int j=1;j<i;j++)
        a[j]=a[j-1]+(rand()+1)%1000;
        fprintf(fp2,"%d ",i);
        key=a[(i-1)/2]; //best
        printfile(a,i,key);
        pos=binarysearch(a,key,0,i-1);
        fprintf(fp2,"%d ",count);
        count=0;
        key=9999; //worst
        printfile(a,i,key);
        pos=binarysearch(a,key,0,i-1);
        fprintf(fp2,"%d ",count);
        count=0;
        key=a[(i-1)/4]; //average
        printfile(a,i,key);
        pos=binarysearch(a,key,0,i-1);
        fprintf(fp2,"%d",count);
        fprintf(fp2,"\n");
    }
    fclose(fp1);
    fclose(fp2);
    system("gedit binarylist.txt");
    system("gedit binarycount.txt");
    FILE *g=fopen("plot.gnu","w");
    fprintf(g,"set yrange [0:*]\nset xlabel \"Input(N)->\"\nset ylabel \"output(count)->\"\nset term png\nset   output\"count.png\"\nplot \"binarycount.txt\" u 1:2 w l ti \"best\",\"binarycount.txt\" u 1:4 w l ti \"average\", \"binarycount.txt\" u 1:3 w l ti \"worst\"");
fclose(g);
system("gnuplot plot.gnu");
system("eog count.png");	
}
int binarysearch(int *a,int key,int beg,int end)
{
	count++;
	int mid=(beg+end)/2;
	if(a[mid]==key)
	return mid;
	if(beg>end)
	return -1;
	if(a[mid]>key)
	return binarysearch(a,key,beg,mid-1);
	else
	return binarysearch(a,key,mid+1,end);
}
void printfile(int *a,int n,int key)
{
    for(int j=0;j<n;j++)
        {
            fprintf(fp1,"%d\t",*(a+j));
        }
        fprintf(fp1,"\nSearch Key:%d\n",key);
}
