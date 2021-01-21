#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#define MAX_SIZE 6
int visited[5]={0,0,0,0,0};
int graph[5][5]={ 
    {0,1,1,1,0},
    {1,0,1,0,0},
    {1,1,0,0,1},
    {1,0,0,0,0},
    {0,0,1,0,0}
};
int arr[MAX_SIZE];
int front=-1;
int rear=-1;
bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}
void enqueue(int x){
    if(((rear+1)%MAX_SIZE)==front){
        printf("overflow");
        return;
    }
    if(IsEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%MAX_SIZE;
        
    }
    arr[rear]=x;
}
int dequeue(){
    if(rear==front){
        
        front=-1;
        rear=-1;
        return;
        
    }
    else{
        int y=arr[front];
        front=(front+1)%MAX_SIZE;
        return y;
    }
}
void display(){
    int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
    for(int i=0;i<count;i++){
        int index = (front+i) % MAX_SIZE;
        printf("%d ",arr[index]);
    }
}
void bfs(int x){
    visited[x]=1;
    enqueue(x);
    while(front!=-1){
        int x=arr[front];
        printf("%d",arr[front]);
        dequeue();
        for(int i=0;i<5;i++){
            if(graph[x][i]==1){
                if (visited[i]!=1){
                    visited[i]=1;
                    enqueue(i);
                }
            }
        }
        
    }
    
}
int main(){
    bfs(0);
}

