#include <stdio.h>
#include <stdbool.h>
#include<math.h>

bool isPrime(int x){
    if(x<=1)return false;
    if(x==2)return true;
    int count=0;
    for (int i=2;i<x;i++){
        if(x%i==0)return false;
    }
    
}

bool isCircularPrime(int y){
    int count=0;
    int temp=y;
    while(temp){
        count++;
        temp=temp/10;
    }
    int temp2=y;
    while(isPrime(temp2)){
        int remainder=temp2%10;
        int quotient=temp2/10;
        temp2=(pow(10,count-1))*remainder+quotient;
        if(temp2==y){
            return true;
        }
        
        
        
    }
    return false;
}

int main()
{
    if(isCircularPrime(11293)){printf("Prime");}
    else{
        printf("Not Prime");
    }
    
}