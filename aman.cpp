#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int ab,ba=0;
    string x;
    cout << "enter string :";
    getline(cin,x);
    for(int i=0;i<x.length()-1;i++){
        if(x[i]=='a' && x[i+1]=='b'){
            ab++;
        }
        else if (x[i]=='b' && x[i+1]=='a')
        {
            ba++;
        }
        
    }
    while (ab!=ba)
    {
        int i=1;
        cout << "step :" << i;
        if(ab>ba){
            x[0]='b';
        }
        else{
            ba--;
        }
        ab,ba=0;
        for(int j=0;j<x.length()-1;j++){
        if(x[j]=='a' && x[j+1]=='b'){
            ab++;
        }
        else if (x[j]=='b' && x[j+1]=='a')
        {
            ba++;
        }
        
    }
        i++;
        
    }
        
    }
    
    
    

