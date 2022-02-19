#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
char sentance[20000]={"The human brain loves a challenge, but only if it is within an optimal zone of difficulty. If you love tennis and try to play a serious match against a four-year-old, you will quickly become bored. Its too easy. You will win every point. In contrast, if you play a professional tennis player like Roger Federer or Serena Williams, you will quickly lose motivation because the match is too difficult.Now consider playing tennis against someone who is your equal. As the game progresses, you win a few points and you lose a few. You have a good chance of winning, but only if you really try. Your focus narrows, distractions fade away, and you find yourself fully invested in the task at hand. This is a challenge of just manageable difficulty and it is a prime example of the Goldilocks Rule.\0"};
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
    strcpy(data->username,name);
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
        switch (i)
        {
        case 5:
            Beep(2000,100);break;
        case 4:
            Beep(2500,100);break;
        case 3:
            Beep(3000,100);break;
        case 2:
            Beep(3500,100);break;
        case 1:
            Beep(4000,100);break;
        default:
            break;
        }
        printf("your test starts in:%d\n",i);
        hold_screen(1);
    }
}
void sort_leaderboard(user_data* data,int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (((data+i)->user_penalty)>(data+j)->user_penalty)
            {
                user_data temp=*(data+i);
                *(data+i)=*(data+j);
                *(data+j)=temp;
            }
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        while ((data+i)->user_penalty==(data+i+1)->user_penalty && i<size-1)
        {
            if ((data+i)->time_taken>(data+i+1)->time_taken)
            {
                int temp=(data+i)->time_taken;
                (data+i)->time_taken=(data+i+1)->time_taken;
                (data+i+1)->time_taken=temp;
            }
            i++;
        } 
    } 
}
void start_test(){
    char name[50];
    system("cls");
    system("color 3");
    printf("enter your name:");
    scanf("%s",name);
    char input[strlen(sentance)+1];
    printf("enter exact same sentance as given \n");
    //count_down();
    printf("SENTANCE:"),puts(sentance);
    scanf("%c");
    clock_t t=clock();
    gets(input);
    t=clock()-t;
    printf("you completed the test in %lf seconds with %d penalty",(double)(t*1.0/CLOCKS_PER_SEC),penalty(sentance,input));
    (data+game_count)->username=malloc(50);
    update_leaderboard(name,(double)(t/CLOCKS_PER_SEC),penalty(sentance,input),data+game_count);
    game_count++;
    //sort_leaderboard(data,game_count);
    data=realloc(data,(game_count+1)*sizeof(user_data));
    getch();
}
void leaderboard(){
    system("cls");
    if(game_count==0) 
    {
        printf("there is no player data!\n");
        printf("press any key to continue.....");
        getch();
        return;
    }
    system("color 1");
    printf("\t\t\tLEADERBOARD\n");
    for (int i = 0; i < game_count; i++)
    {
        printf("rank:%-5d\tname:%-20s\tpenalty:%-5d\ttime:%-5lf\n",i+1,(data+i)->username,(data+i)->user_penalty,(data+i)->time_taken);
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