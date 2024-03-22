#include<stdio.h>
#include<stdlib.h>
FILE *fp;
void gcdmodulo(int m,int n)
{
int count=0;
int temp;
while(n!=0)
{
count++;
temp=m%n;
m=n;
n=temp;
}
fprintf(fp,"%d ",m);
fprintf(fp,"%d ",count);
}
void gcdsub(int m,int n)
{
int count=0;
while(m!=n)
{
count++;
if(m>n)
m=m-n;
else
n=n-m;
}
fprintf(fp,"%d ",count);
}
void gcdcons(int m,int n)
{
int count=0;
int min=(m>n)?n:m;
while(min!=1)
{
count++;
if(m%min==0)
{
if(n%min==0)
break;
}
min--;
}
fprintf(fp,"%d\n",count);
}
void main()
{
fp=fopen("gcdlist.txt","w");
srand(0);
int m=0,n=0;
fprintf(fp,"m n gcd c1 c2 c3\n");
for(int i=1;i<=10;i++)
{
m=m+(rand()+1)%1000;
n=m+(rand()+1)%1000;
int min=(m<n)?m:n;
//fprintf(fp,"%d ",min);
fprintf(fp,"%d %d ",m,n);
gcdmodulo(m,n);
gcdsub(m,n);
gcdcons(m,n);
}
fclose(fp);
system("gedit gcdlist.txt");
system("gnuplot plot.gnu");
system("eog gcd.png");
}





