//Bubble sort analysis for Best case, average case and worst case
#include<stdio.h>
#include<stdlib.h>
FILE *f1, *f2;
int count;
void bestcaseinput(int *a,int n)
{
    int i;
    a[0]=rand()%100;
    for(int i=1;i<n;i++)
        {
            a[i]=a[i-1]+rand()%100;
        }
}
void worstcaseinput(int *a,int n)
{
    int i;
    a[n-1]=rand()%100;
    for(i=n-2;i>=0;i--)
    a[i]=a[i+1]+rand()%100;
}
void averagecaseinput(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    a[i]=rand()%100;
}
void bubblesort(int *a,int n)
{
    int flag,temp;
    for(int i=0;i<n-1;i++)
        {
       
            flag=0;
            for(int j=0;j<n-i-1;j++)
            {
            	count++;
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    flag=1;
                }
            }
            if(flag==0)
                    break;
        }
        
}
void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        {
            fprintf(f1,"%d\t",a[i]);
        }
}
void main()
{
    int *a;
    int n;
    f1=fopen("bubblesortlist.txt","w");
    f2=fopen("bubblesortcount.txt","w");
    srand(0);
    fprintf(f2,"N B W A\n");
    for(n=10;n<=100;n=n+10)
    {
        fprintf(f2,"%d ",n);
        a=(int*)malloc(n*sizeof(int));
        bestcaseinput(a,n);
        fprintf(f1,"Array beforing sortingB: ");
        print(a,n);
        count=0;
        bubblesort(a,n);
        fprintf(f1,"\nArray after sortingB: ");
        print(a,n);
        fprintf(f2,"%d ",count);
        fprintf(f1,"\n");
        count=0;
        fprintf(f1,"Array beforing sortingW: ");
        worstcaseinput(a,n);
        print(a,n);
        bubblesort(a,n);
        fprintf(f1,"\nArray after sortingW: ");
        print(a,n);
        fprintf(f2,"%d ",count);
        fprintf(f1,"\n");
        count=0;
        fprintf(f1,"Array beforing sortingA: ");
        averagecaseinput(a,n);
        print(a,n);
        bubblesort(a,n);
        fprintf(f1,"\nArray after sortingA: ");
        print(a,n);
        fprintf(f2,"%d ",count);
        fprintf(f1,"\n\n");
        fprintf(f2,"\n"); 
    }
    fclose(f1);
    fclose(f2);
    system("gedit bubblesortcount.txt");
    FILE *g=fopen("plotbubble.gnu","w");
    fprintf(g,"set yrange [0:*]\nset xlabel \"Input\"\nset ylabel \"output\"\nset term png\nset output\"bubble.png\"\nplot \"bubblesortcount.txt\" u 1:2 w l ti \"best\",\"bubblesortcount.txt\" u 1:3 w l ti \"average\",\"bubblesortcount.txt\" u 1:4 w l ti \"worst\"\nset term x11");
    fclose(g);
    system("gnuplot plotbubble.gnu");
    system("eog bubble.png");
    printf("enter the number of elements:");
    scanf("%d",&n);
    int b[n];
    printf("enter:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&b[i]);
    count=0;
    bubblesort(b,n);
    printf("sorted\n");
     for(int i=0;i<n;i++)
    printf("%d ",b[i]);
    printf("\ncount=%d\n",count);
    
}

