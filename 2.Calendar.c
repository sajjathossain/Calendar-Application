#include<stdio.h>
#include<stdlib.h>
int main()
{
    system("color f3");
    int year=0,month=0,day=0,week=0,i=0,starting_day=0;

    for(i=0;i=EOF;i++)
    {
    printf("\nEnter the year : \n");
    scanf("%d",&year);

    printf("\nEnter the month : \n");
    scanf("%d",&month);

    if(year==0 || month==0)
    {
        break;
    }

    else{

    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int month_size[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int t[]={0,3,3,6,1,4,6,2,5,0,3,5};

    //year
    int formula = year + year/4 - year/100 + year/400 + t[month-1] + 1 /*date number*/;

    if(year%400==0 && year%100!=0 || year%4==0)
    {
        month_size[1]=29;
        //for leap year we have to subtract 1 from the formula otherwise the formula won't work//
        formula = formula+1;
    }
    else
    {
    if(year<2000 || year>2000)
    {
     formula = formula+1;
    }
    }
    printf(" -----------:%s  %d:------------\n",months[month-1],year);
    printf("|  Fri  Sat  Sun  Mon  Tue  Wed  Thu |\n");

    //this counts from where the day of the week starts//
    /*
    sun=2;
    mon=3;
    tue=4;
    wed=5;
    thu=6;
    fri=0;
    sat=1;

    */
    starting_day = (formula)%7;

    for(week=0;week<starting_day;++week)
    {
        printf("     ");
    }
    for(day=1;day<=month_size[month-1];day++)
    {
        printf("%5d",day);
        if(++week>6)
        {
            printf("\n");
            week=0;
        }
        }

    }
    printf("\n\nIf you wanna quit enter 0\n");
    }
    return 0;
}
