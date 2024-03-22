#include<stdio.h>
#include<stdlib.h>
FILE *fp1,*fp2;
void printfile(int*,int,int);
void linearsearch(int*,int,int);
void main()
{
    srand(0);
    int *a,key,j;
    fp1=fopen("linearlist.txt","w");
    fp2=fopen("linearcount.txt","w");
    fprintf(fp2,"N B W A\n");
    for(int i=10;i<=100;i=i+10)
    {
        a=(int*)malloc(i*sizeof(int));
        for(int j=0;j<i;j++)
        a[j]=rand()%100;
        fprintf(fp2,"%d ",i);
        key=*(a+0); //best
        printfile(a,i,key);
        fprintf(fp1,"\n");
        linearsearch(a,i,key);
        key=9999; //worst
        printfile(a,i,key);
        fprintf(fp1,"\n");
        linearsearch(a,i,key);
        key=a[(i-1)/2]; //average
        printfile(a,i,key);
        fprintf(fp1,"\n");
        linearsearch(a,i,key);
        fprintf(fp2,"\n");
    }
    fclose(fp1);
    fclose(fp2);
    system("gedit linearcount.txt");
    system("gedit linearlist.txt");
    system("gnuplot plotlinear.gnu");
    system("eog linear.png");

}
void linearsearch(int *a,int n,int key)
{
    int count=0;
    for(int j=0;j<n;j++)
        {
            count++;
            if(*(a+j)==key)
            break;
        }
        fprintf(fp2,"%d ",count);
}
void printfile(int *a,int n,int key)
{
    for(int j=0;j<n;j++)
        {
            fprintf(fp1,"%d\t",*(a+j));
        }
        fprintf(fp1,"\nSearch Key:%d\n",key);
}
