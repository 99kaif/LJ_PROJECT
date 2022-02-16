#include<stdio.h>
#include<string.h>
#include<windows.h>
char words[1][6]={"hello"};
void start_game()
{
    char str[100]="***";
    int found_word[strlen(words[0])];
    for (int i = 0; i < strlen(words[0]); i++)
    {
        found_word[i]=0;
    }
    printf("enter any word of %d size:\n",strlen(words[0]));
    while (strcmp(str,words[0])!=0)
    {
        printf("founded words:");
        for (int i = 0; i < strlen(words[0]); i++)
    {
        if(found_word[i]==0) printf("*");
        else printf("%c",words[0][i]);
    }
    printf("\n");
    scanf("%s",str);
    if (strcmp(str,words[0])==0)
    {
        printf("YOU WIN!!!!!");return;
    }
    
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
int main()
{
    start_game();
}