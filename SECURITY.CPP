#include<stdio.h>
#include<conio.h>
struct date
{
int day;
int month;
int year;
} ;
struct time
{
int hour;
int min;
int sec;
};
struct account
{
char name[100];
long int phone_number;
char v[100];
int x;
int y;
char r[100];
struct date checkin;
struct time checkout[3];
}security[100];
int k,t,r,q;
main()
{
clrscr();
FILE *fp;
int i,y,n;
printf("\twelcome to the security 360\n");

printf("\t*********************************\n");

printf("\tenter the number of visitor in the gokuldhaam society\n");
scanf("%d",&n);

fp=fopen("security","w");
for(i=0;i<n;i++)
{
printf("\n\tenter the %d visitor's name\n",i+1);
scanf("%s",security[i].name);

printf("\tenter the phone number \n");
scanf("%ld",&security[i].phone_number);

printf("\tenter the person whom u want to visit \n");
scanf("%s",security[i].v);

printf("\tenter the buliding number\n");
scanf("%d",&security[i].x);

printf("\tenter the flat number\n");
scanf("%d",&security[i].y);

printf("\tenter the  check in date[dd/mm/yyyy]\n");
scanf("%d%d%d",&security[i].checkin.day,&security[i].checkin.month,&security[i].checkin.year);

printf("\tenter the checkin time  [hh/mm/ss]\n");
scanf("%d%d%d",&security[i].checkout[1].hour,&security[i].checkout[1].min,&security[i].checkout[1].sec);

printf("\tenter the checkout time  [hh/mm/ss]\n");
scanf("%d%d%d",&security[i].checkout[2].hour,&security[i].checkout[2].min,&security[i].checkout[2].sec);

fprintf(fp,"%s%ld %s %d %d %d %d %d %d %d %d %d %d %d",security[i].name,security[i].phone_number,security[i].v,security[i].x,security[i].y,security[i].checkin.day,security[i].checkin.month,security[i].checkin.year,security[i].checkout[1].hour,security[i].checkout[1].min,security[i].checkout[1].sec,security[i].checkout[2].hour,security[i].checkout[2].min,security[i].checkout[2].sec);
}
fclose(fp);
fp=fopen("security","w");
for(i=0;i<n;i++)
{
fscanf(fp," %d %d %d %d %d %d",&security[i].checkout[1].hour,&security[i].checkout[1].min,&security[i].checkout[1].sec,&security[i].checkout[2].hour,&security[i].checkout[2].min,&security[i].checkout[2].sec);

q=security[i].checkout[1].hour*3600+security[i].checkout[1].min*60+security[i].checkout[1].sec;

r=security[i].checkout[2].hour*3600+security[i].checkout[2].min*60+security[i].checkout[2].sec;

k=r-q;

security[i].checkout[3].hour=k/3600;
t=k%3600;

security[i].checkout[3].min=t/60;

security[i].checkout[3].sec=t%60;

fprintf(fp," %d %d %d",security[i].checkout[3].hour,security[i].checkout[3].min,security[i].checkout[3].sec);
}

fclose(fp);

fp=fopen("security","r");

for(i=0;i<n;i++)
{
fscanf(fp,"%s %ld %s %d%d%d%d%d%d%d%d%d%d%d%d%d%d",security[i].name,&security[i].phone_number,security[i].v,&security[i].x,&security[i].y,&security[i].checkin.day,&security[i].checkin.month,&security[i].checkin.year,&security[i].checkout[1].hour,&security[i].checkout[1].min,&security[i].checkout[1].sec,&security[i].checkout[2].hour,&security[i].checkout[2].min,&security[i].checkout[2].sec,&security[i].checkout[3].hour,&security[i].checkout[3].min,&security[i].checkout[3].sec);

printf("\n\t*****************************\n");

printf(" \tvisitor name is [%s]\n \tphone number is [%ld]\n\t friend name is[%s] \n ",security[i].name,security[i].phone_number,security[i].v);

printf("\n\tbuilding number is %d\n\t  flat number is %d\n\t date is %d/%d/%d ",security[i].x,security[i].y,security[i].checkin.day,security[i].checkin.month,security[i].checkin.year);

printf("\n time in is %d/%d/%d\n\t",security[i].checkout[1].hour,security[i].checkout[1].min,security[i].checkout[1].sec);

printf("time out is %d/%d/%d\n",security[i].checkout[2].hour,security[i].checkout[2].min,security[i].checkout[2].sec);

printf("duration is %dhr /%d min /%dsec\n",security[i].checkout[3].hour,security[i].checkout[3].min,security[i].checkout[3].sec);

printf("\t****************************\n");
}
fclose(fp);
getch();}
