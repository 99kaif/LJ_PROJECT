#include<stdio.h>
struct count{
    int total_credit;
    int sum;
    float spi;
} c[8];
struct data {
    int roll_nomber;
    char name[20];
    float cpi;
    struct sub{
        char name[20];
        int credit;
        int grade_point;
        char grade[3];
        int marks;
    } s[8][6];
} s1;
int grade(struct sub s[8][6],int x)
{
    int i;
    for(i=0;i<6;i++)
    {
        if(85<=s[x-1][i].marks && s[x-1][i].marks<=100)
        {
            s[x-1][i].grade_point=10;
        }
        else if(74<=s[x-1][i].marks && s[x-1][i].marks<=85)
        {
            s[x-1][i].grade_point=9;
        }
        else if(65<=s[x-1][i].marks && s[x-1][i].marks<=74)
        {
            s[x-1][i].grade_point=8;
        }
        else if(55<=s[x-1][i].marks && s[i][x-1].marks<=64)
        {
            s[x-1][i].grade_point=7;
        }
        else if(45<=s[x-1][i].marks && s[x-1][i].marks<=54)
        {
            s[x-1][i].grade_point=6;
        }
        else if(40<=s[x-1][i].marks && s[x-1][i].marks<=44)
        {
            s[x-1][i].grade_point=5;
        }
        else if(35<=s[x-1][i].marks && s[x-1][i].marks<=39)
        {
            s[x-1][i].grade_point=4;
        }
        else if(s[x-1][i].marks<=35)
        {
            s[x-1][i].grade_point=0;
        }
    }
}
int cpi(int x)
{
    int i;
    int m=0;
    for(i=1;i<x;i++)
    {
        s1.cpi+=c[i-1].spi;
        m++;
    }
    s1.cpi=s1.cpi/m;
}
int spi(struct sub s[8][6],int x)
{
    int i;
    c[x-1].total_credit=0,c[x-1].sum=0;
    for(i=0;i<6;i++)
    {
        c[x-1].total_credit+=s[x-1][i].credit;
        c[x-1].sum+=s[x-1][i].grade_point*s[x-1][i].credit;
    }
    c[x-1].spi=c[x-1].sum*1.0/c[x-1].total_credit;
}
int main()
{
    int x=1;
    printf("enter roll nomber :");
    scanf("%d",&s1.roll_nomber);
    printf("enter name :");
    scanf("%s",&s1.name);
    here:
    printf("\t\t\t\t\t\t\t\t\tenter sem %d details:\n",x);
    int i;
    for(i=0;i<6;i++){
        printf("enter subject %d name :",i+1);
        scanf("%s",&s1.s[x-1][i].name);
        printf("enter %s credit point:",s1.s[x-1][i].name);
        scanf("%d",&s1.s[x-1][i].credit);
        printf("enter %s marks :",s1.s[x-1][i].name);
        scanf("%d",&s1.s[x-1][i].marks);
    }
    grade(s1.s,x);
    spi(s1.s,x);
    //printf("\n%d\n%d",c[x-1].sum,c[x-1].total_credit);
    printf("\nspi is %.2f",c[x-1].spi);
    int ans;
    printf("\nnext sem data y=1 or n=0:\t");
    scanf("%d",&ans);
    if(ans==1){
        x++;
        goto here;
    }
    else
    {
        cpi(x);
        printf("\ncpi is %.2f",s1.cpi);
    }
}