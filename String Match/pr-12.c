#include<stdio.h>
#include<stdlib.h>
FILE *fp;
int count;
void stringmatch(char *a,int n,char *p,int m)
{
int i,j;
for(i=0;i<=(n-m);i++)
{
for(j=0;j<m;j++)
{
count++;
if(p[j]!=a[i+j])
break;
}
if(j==m)
break;
}
}

void patstr(char *p,int m)
{
for(int i=0;i<m;i++)
p[i]='h';
}

void main()
{
char *a,*p;
int n,i,j;
fp=fopen("countlist.txt","w");
fprintf(fp,"N B A W\n");
int m;	
for(i=10;i<=100;i=i+10)
{
a=(char*)malloc(sizeof(char)*i);
m=i/2;
p=(char*)malloc(sizeof(char)*m);
for(j=0;j<i;j++)
a[j]='h';
count=0;
fprintf(fp,"%d ",i);
patstr(p,m);
stringmatch(a,i,p,m);
fprintf(fp,"%d ",count);
patstr(p,m);
p[(m-1)/2]='l';
count=0;
stringmatch(a,i,p,m);
fprintf(fp,"%d ",count);
patstr(p,m);
p[m-1]='l';
count=0;
stringmatch(a,i,p,m);
fprintf(fp,"%d ",count);
fprintf(fp,"\n");
}
fclose(fp);
system("gedit countlist.txt");
FILE *g=fopen("plot.gnu","w");
fprintf(g,"set yrange [0:*]\nset xlabel \"Input(N)->\"\nset ylabel \"output(count)->\"\nset term png\nset output\"count.png\"\nplot \"countlist.txt\" u 1:2 w l ti \"best\",\"countlist.txt\" u 1:3 w l ti \"average\",\"countlist.txt\" u 1:4 w l ti \"worst\"");
fclose(g);
system("gnuplot plot.gnu");
system("eog count.png");
}







