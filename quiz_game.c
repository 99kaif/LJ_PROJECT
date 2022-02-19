#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
char start_stop='Y';
typedef enum option {A=65,B,C,D} option;
struct mcq
{
    int question_number;
    char question[200];
    char answers[4][200];
    option correct_option;
    option chosen_option;
};
typedef struct mcq mcq;


void del(int* arr,int n,int* size){
    int i=0;
    while (arr[i]!=n)
    {
        i++;
    }
    int loc=i,temp;
    int size1=*size;
    for (int i = loc; i < size1-1; i++)
    {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
    *size-=1;
    
}
int is_in_arr(int* arr,int element,int size){
    int i=0;
    while (i<size)
    {
        if (arr[i]==element)
        {
            return 1;
        }
        
        i++;
    }
    return 0;
}
void review(mcq mcq_set[10])
{
    for (int i = 0; i < 10; i++)
    {
        
    }
}
void main(char start_stop){
    system("cls");
    srand(time(0));
    int correct_question_number[10]={0};
    mcq mcq_set[10];
    for (int i = 0; i < 10; i++)
    {
        mcq_set[i].question_number=i+1;
    }
    strcpy(mcq_set[0].question,"which animal is know as the ship of the desert?");
    strcpy(mcq_set[0].answers[0],"lion");
    strcpy(mcq_set[0].answers[1],"camel");
    strcpy(mcq_set[0].answers[2],"cow");
    strcpy(mcq_set[0].answers[3],"elephant");
    strcpy(mcq_set[1].question,"in which direction does the sun rise?");
    strcpy(mcq_set[1].answers[0],"north");
    strcpy(mcq_set[1].answers[1],"south");
    strcpy(mcq_set[1].answers[2],"west");
    strcpy(mcq_set[1].answers[3],"east");
    strcpy(mcq_set[2].question,"which is the largest mammal?");
    strcpy(mcq_set[2].answers[0],"shark");
    strcpy(mcq_set[2].answers[1],"blue whale");
    strcpy(mcq_set[2].answers[2],"tuna");
    strcpy(mcq_set[2].answers[3],"jelly fish");
    strcpy(mcq_set[3].question,"india signed a lol on new and renewable energy trchnology with which country?");
    strcpy(mcq_set[3].answers[0],"israel");
    strcpy(mcq_set[3].answers[1],"australia");
    strcpy(mcq_set[3].answers[2],"usa");
    strcpy(mcq_set[3].answers[3],"new zealand");
    strcpy(mcq_set[4].question,"who wad the first prime minister of india?");
    strcpy(mcq_set[4].answers[0],"saradar patel");
    strcpy(mcq_set[4].answers[1],"mahatma ghandhi");
    strcpy(mcq_set[4].answers[2],"jawaharlal nehru");
    strcpy(mcq_set[4].answers[3],"shubhash chandra boze");
    strcpy(mcq_set[5].question,"which is the longest river on the earth ?");
    strcpy(mcq_set[5].answers[0],"nile");
    strcpy(mcq_set[5].answers[1],"amazone");
    strcpy(mcq_set[5].answers[2],"ganga");
    strcpy(mcq_set[5].answers[3],"indus");
    strcpy(mcq_set[6].question,"who among the following wrote sanskrit grammar?");
    strcpy(mcq_set[6].answers[0],"kalidasa");
    strcpy(mcq_set[6].answers[1],"charak");
    strcpy(mcq_set[6].answers[2],"panini");
    strcpy(mcq_set[6].answers[3],"aryabhatt");
    strcpy(mcq_set[7].question,"the metal whose salts are sensitive to light is?");
    strcpy(mcq_set[7].answers[0],"zinc");
    strcpy(mcq_set[7].answers[1],"silver");
    strcpy(mcq_set[7].answers[2],"copper");
    strcpy(mcq_set[7].answers[3],"aluminum");
    strcpy(mcq_set[8].question,"the country that has the highest in barley production?");
    strcpy(mcq_set[8].answers[0],"china");
    strcpy(mcq_set[8].answers[1],"india");
    strcpy(mcq_set[8].answers[2],"russia");
    strcpy(mcq_set[8].answers[3],"france");
    strcpy(mcq_set[9].question,"D.D.T. was invented by?");
    strcpy(mcq_set[9].answers[0],"mosley");
    strcpy(mcq_set[9].answers[1],"rudolf");
    strcpy(mcq_set[9].answers[2],"karl benz");
    strcpy(mcq_set[9].answers[3],"dalton");
    mcq_set[0].correct_option=B;
    mcq_set[1].correct_option=D;
    mcq_set[2].correct_option=B;
    mcq_set[3].correct_option=B;
    mcq_set[4].correct_option=C;
    mcq_set[5].correct_option=A;
    mcq_set[6].correct_option=C;
    mcq_set[7].correct_option=B;
    mcq_set[8].correct_option=C;
    mcq_set[9].correct_option=A;
    int remaining_question[]={0,1,2,3,4,5,6,7,8,9};
    int size=10;
    int i=1,score=0;
    while (size!=0)
    {
        system("cls");
        int x=rand()%10;
        printf("question %d:%s",i,mcq_set[x].question);
        printf("\noptions:\n");
        printf("\nA:%s\t\tB:%s\t\tC:%s\t\tD:%s\t\n",mcq_set[x].answers[0],mcq_set[x].answers[1],mcq_set[x].answers[2],mcq_set[x].answers[3]);
        char o;
        fflush(stdin);
        printf("enter your answer:");
        scanf("%c",&o);
        while(o<'A' || o>'D')
        {
            printf("\nenter valid choice:");
            fflush(stdin);
            scanf("%c",&o);
        }
        mcq_set[x].chosen_option=(int)o;
        if((int)o==mcq_set[x].correct_option)
        {
            score++;
        }
        del(remaining_question,x,&size);
        i++;
    }
    char want_review;
    printf("\n\n\n\t\t\tYOUR SCORE IS %d\n\n\n",score);
    printf("DO YOU WANT TO REVIEW YOUR TEST:");
    scanf("%c",&want_review);
    if(want_review=='Y') review(mcq_set);
}