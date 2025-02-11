#include <stdio.h>
#include <stdlib.h>

int size;

struct Queue {
    int *queue;  // Array to store Queue
    int front;   // Front index
    int rear;    // Rear index
} Q;
void pushrear(int val){
    if(Q.rear==size-1){
        printf("reallocating Memory\n");
        size *= 2;
        Q.queue=(int *)realloc(Q.queue,size*(sizeof(int)));
    }
    else if(Q.front==-1)
        Q.front=0;
    Q.queue[++Q.rear]=val;
}
void pushfront(int val){
    if(Q.rear==size-1){
        printf("reallocating Memory\n");
        size *= 2;
        Q.queue=(int *)realloc(Q.queue,size*(sizeof(int)));
    }
    if(Q.front ==-1){
        Q.front=Q.rear=0;
        Q.queue[Q.front]=val;
    }else {
        if(Q.front==0){
        for(int i=Q.rear;i>=Q.front;i--)
            Q.queue[i+1]=Q.queue[i];
            Q.rear++;
        }
        else{
            Q.front--;
        }
        Q.queue[Q.front]=val;
    }
}
void popfront(){
    if(Q.front == -1){
        printf("List is empty");
        return;
    }
    if(Q.front == Q.rear ){
        Q.front=Q.rear=-1;
    }
    else{
        Q.front++;
    }
}
void poprear(){
    if(Q.front == -1){
        printf("List is empty");
        return;
    }
    if(Q.front == Q.rear ){
        Q.front=Q.rear=-1;
    }
    else{
        Q.rear--;
    }
}


void display() {
    if (Q.front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = Q.front; i <= Q.rear; i++)
        printf("%d ", Q.queue[i]);
    
    printf("\n");
}

int main() {
    Q.front = Q.rear = -1; 
    int val, choice;

    printf("Enter the Initial Size: ");
    scanf("%d", &size);
    Q.queue = (int *)malloc(size * sizeof(int)); 

    printf("\nMain Menu\n");
    printf("1. Push-Front\n");
    printf("2. Pop-Front\n");
    printf("3. Push-Rear\n");
    printf("4. Pop-Rear\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the Element to be Inserted: ");
                scanf("%d", &val);
                pushfront(val);
                break;
            case 2:
                popfront();
                break;
            case 3:
                printf("Enter the Element to be Inserted: ");
                scanf("%d", &val);
                pushrear(val);
                break;
            case 4:
                poprear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("!! THANK YOU !!\n");
                free(Q.queue); 
                exit(0);
            default:
                printf("Invalid Choice\nEnter Again\n");
        }
    }
    return 0;
}
