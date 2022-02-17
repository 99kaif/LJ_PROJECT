#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
char words[2][20]={"hello","school"};
void start_game()
{
    srand(time(0));
    char c='y';
    while (c=='y')
    {
    int r=rand()%2;
    char str[100]="***";
    int found_word[strlen(words[r])];
    for (int i = 0; i < strlen(words[r]); i++)
    {
        found_word[i]=0;
    }
    printf("enter any word of %d size:\n",strlen(words[r]));
    while (strcmp(str,words[r])!=0)
    {
        printf("founded words:");
        for (int i = 0; i < strlen(words[r]); i++)
    {
        if(found_word[i]==0) printf("*");
        else printf("%c",words[r][i]);
    }
    printf("\n");
    scanf("%s",str);
    if (strcmp(str,words[r])==0)
    {
        printf("YOU WIN!!!!!");
        printf("enter y to play again n for quit:");
        fflush(stdin);
        scanf("%c",&c);
    }
    if(c=='y') continue;
    else return;
    for (int i = 0; i < strlen(words[0]); i++)
    {
        if (str[i]==words[0][i])
        {
            found_word[i]=1;
        }
    }
    printf("TRY AGAAIN!!!\n");
    }
    }
    
}
int main()
{
    srand(time(0));
    start_game();
}