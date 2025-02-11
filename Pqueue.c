#include <stdio.h>
#include <stdlib.h>

int size;
struct Queue{
    int *a;
    int front;
    int rear;
}Q;

void insert() {
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);

    if (Q.front == -1) {
        Q.front = Q.rear = 0;
        Q.a[Q.rear] = ele;
        return;
    } else if (Q.rear == size - 1) {
        printf("Reallocating memory\n");
        size++;
        Q.a = (int *)realloc(Q.a, size * sizeof(int));
    } else {
        Q.rear++;
    }

    int i = Q.rear;
    while (i > Q.front && Q.a[i - 1] < ele) {
        Q.a[i] = Q.a[i - 1];
        i--;
    }
    Q.a[i] = ele;
}
void dequeue(){
    if(Q.front==-1){
        printf("Empty list");
        return;
    }
    else if(Q.front==Q.rear){
        printf("ele %d",*(Q.a+Q.front));
        Q.front=Q.rear=-1;
    }
    else{
        printf("ele %d",*(Q.a+Q.front));
        Q.front++;
    }
}
void display(){
    if(Q.front==-1){
        printf("Empty list");
        return;
    }
    for(int i=Q.front;i<=Q.rear;i++){
        printf("%d ",*(Q.a+i));
    }
}
void main(){
    printf("Enter the size of Queue : ");
    scanf("%d",&size);
    printf(" 1 ins 2 pop 3 display 4 exit\n");
    int ch;
    Q.rear=-1;
    Q.front =-1;
    Q.a=(int *)malloc(size*sizeof(int));
    for(;;){
        printf(" Enter choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
        default:
            break;
        }
    }
    return;
}