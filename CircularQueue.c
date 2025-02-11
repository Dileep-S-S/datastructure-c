#include <stdio.h>
#include <stdlib.h>
int n;
struct Q{
    int front;
    int rear;
    int *queue;
}Q;

void insert(){
    int ele;
    if(Q.front==0 && Q.rear==n-1){
        printf("Queue is full Reallocating Memory \n");
        n++;
        Q.queue=(int *)realloc(Q.queue,n*sizeof(int));
    }
    if(Q.front==-1&& Q.rear==-1){
        Q.front=0;
    }
    printf("Eneter the element : ");
    scanf("%d",&ele);
    Q.rear=(Q.rear+1)%n;
    *(Q.queue+Q.rear)=ele;
    printf("Insertion Successfull\n");
}
void display(){
    if(Q.front==-1&&Q.rear==-1){
        printf("List is Empty\n");
        return;
    }
    if(Q.rear>Q.front){
        for(int i=Q.front;i<=Q.rear;i++){
            printf("%d ",*(Q.queue+i));
        }
    }
    else{
        for(int i=Q.front;i<=n-1;i++){
            printf("%d ",*(Q.queue+i));
        }
        for(int i=0;i<=Q.rear;i++){
            printf("%d ",*(Q.queue+i));
        }
    }
    printf("\n");

}
void delete(){
    if(Q.front==-1&&Q.rear==-1){
        printf("List is Empty");
        return;
    }
    if(Q.front==Q.rear){
        printf("The deleted elemet is %d \n",*(Q.queue+Q.front));
        Q.front=Q.rear=-1;
    }
    else{
        printf("The deleted elemet is %d \n",*(Q.queue+Q.front));
        Q.front=(Q.front+1)%n;
    }
}
void main(){
    int ch;
    printf("Enter the legnth of Queue : ");
    scanf("%d",&n);
    Q.queue = (int *)malloc(n*sizeof(int));
    Q.front=Q.rear=-1;
    printf("\nmenu \n 1 for insert \n 2 for display\n 3 for delete \n 4 for exit\n");
    for(;;){
        printf("Enter the CHoice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();break;
            case 2:
                display();break;
            case 3:
                delete();break;
            case 4:
                exit(0);
        }
    }
}
