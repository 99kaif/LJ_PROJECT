#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct mcq
{
    int question_number;
    char* question;
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
void main(){
    mcq* mcq_set;
    mcq_set=malloc(10*sizeof(mcq));
    for (int i = 0; i < 10; i++)
    {
        mcq_set[i].question_number=i;
    }
    mcq_set->question="aman";
    int arr[]={0,1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(int);
    int i=1;
    while (size!=0)
    {
        int x=rand()%10;
        if (is_in_arr(arr,x,size))
        {
            printf("questin %d",mcq_set[x].question_number);
            del(arr,x,&size);
        }
        
    }
    puts(mcq_set->question);
}