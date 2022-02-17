#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct user_data
{
    char* username;
    double time_taken;
    int user_penalty;
};
typedef struct user_data user_data;
int game_count=0;
user_data* data;
void update_leaderboard(char* name,double time_taken,int penalty,user_data* data){
    //printf("name:")
    strcpy(data->username,name);
    //printf("username:%s",(data+game_count)->username);
    data->time_taken=time_taken;
    data->user_penalty=penalty;
}
int penalty(char* a,char* input){
    int i=0,p=0;
    while (a[i]!='\0')
    {
        if (a[i]!=input[i] || i>strlen(a))
        {
            p++;
        }
        i++;
    }
    return p;
}
void hold_screen(int time){
    while (time-->0)
    {
        Sleep(1000);
    }
}
void count_down(){
    system("color 3");

    for (int i = 5; i > 0; i--)
    {
        printf("your test starts in:%d\n",i);
        hold_screen(1);
    }
}
void start_test(){
    char name[50];
    system("cls");
    system("color 3");
    printf("enter your name:");
    scanf("%s",name);
    char sentance[]="hello world";
    char input[strlen(sentance)+1];
    printf("enter exact same sentance as given \n");
    count_down();
    printf("SENTANCE:"),puts(sentance);
    scanf("%c");
    clock_t t=clock();
    gets(input);
    t=clock()-t;
    printf("you completed the test in %lf seconds with %d penalty",(double)(t/CLOCKS_PER_SEC),penalty(sentance,input));
    (data+game_count)->username=malloc(50);
    update_leaderboard(name,(double)(t/CLOCKS_PER_SEC),penalty(sentance,input),data+game_count);
    game_count++;
    data=realloc(data,(game_count+1)*sizeof(user_data));
    getch();
}
void leaderboard(){
    system("cls");
    system("color 1");
    printf("\t\t\tLEADERBOARD\n");
    for (int i = 0; i < game_count; i++)
    {
        printf("name:%s\tpenalty:%d\ttime:%lf\n",(data+i)->username,(data+i)->user_penalty,(data+i)->time_taken);
    }
    
    getch();
}
int main_menu(){
    system("cls");
    system("color 2");
    int choice;
    printf("\t\t\t1.start test\n");
    printf("\t\t\t2.leaderboard\n");
    printf("\t\t\t3.quit\n");
    printf("\t\tenter the corresponding number of your choice:");
    scanf("%d",&choice);
    return choice;
}
int random_int(int range){
    srand(time(0));
    return rand()%(range+1);
}

void loop(){
    while (1)
    {
        system("cls");
    int choice=main_menu();
    switch (choice)
    {
    case 1:
        start_test();
        break;
    case 2:
        leaderboard();
        break;
    case 3:
        exit(0);
    default:
        printf("please enter valid choice sir!!!!\n");
        getch();
        break;
    }
    }
    
}
void main(){
    data=malloc(sizeof(user_data));
    loop();
}