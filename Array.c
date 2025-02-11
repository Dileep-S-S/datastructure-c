#include <Stdio.h>
#include <stdlib.h>
int size;

void read(int *a){
    printf("enter the elements : ");
    for(int i=0;i<=size-1;i++){
        scanf("%d",(a+i));
    }
}

int * insbypos(int *a) {
    int pos,ele;
    printf("Enter the position : ");
    scanf("%d",&pos);
    printf("Enter the element : ");
    scanf("%d",&ele);
    size++;
    a=(int *)realloc(a,size*sizeof(int));
    if(pos<1||pos>size){
        printf("Invalid Position");
        return a;
    }
    for(int i=size-1;i>=pos-1;i--){
        *(a+i)=*(a+i-1);
    }
    *(a+pos-1)=ele;
    return a;
}

int * insbyoredr(int *a){
    int ele;
    printf("Enter the Element : ");
    scanf("%d",&ele);
    size++;
    a=a=(int *)realloc(a,size*sizeof(int));
    int i=size-1;
    while(i>=0 && ele < *(a+i)){
        *(a+i)=*(a+i-1);
        i--;
    }
    *(a+i+1)=ele;
    return a;
}
int * delbypos(int *a){
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos<1||pos>size){
        printf("Invalid POsition");
        return a;
    }
    int i=pos-1;
    while(i<size){
        *(a+i)=*(a+i+1);
        i++;
    }
    size--;
    return a;    
}
int * delbykey(int *a){
    int i=0;int ele;
    printf("Enter the element : ");
    scanf("%d",&ele);
    for(i=0;i<size && *(a+i)!=ele;i++);
    if(i==size){
        printf("Element not found to delete");
    }
    else{
        for(;i<size;i++){
            *(a+i)=*(a+i+1);
        }
        size--;
    }
    return a;
}
void display(int *a){
    if(size==0)
    {
        printf("Array empty\n");
        return;
    }

     printf("the elements are : ");
    for(int i=0;i<size;i++){
        printf("%d -> ",*(a+i));
    }
    printf("\n");
}

void searchbykey(int *a){
    int i=0;int ele;
    printf("Enter the element : ");
    scanf("%d",&ele);
    for(i=0;i<size && *(a+i)!=ele;i++);
    if(i==size){
        printf("Element not found");
    }
    else{
        printf("Element found at position %d \n",i+1);
    }
}

void srachbypos(int *a){
    int pos;
    printf("Enter the POistion to search : ");
    scanf("%d",&pos);
    if(pos<1||pos>size){
        printf("Invalid POsition");
        return;
    }
    printf("the element  at %d is %d\n",pos,*(a+pos-1));
}
int * reverse(int *a){
    int temp;
    for(int i=0;i<size/2;i++){
        temp=*(a+i);
        *(a+i)=*(a+size-i-1);
        *(a+size-i-1)=temp;
    }
    return a;
}
void main(){
    int *a;
    printf("Enter the size of array : ");
    scanf("%d",&size);
    a=(int *)malloc(size*sizeof(int));
    printf("menu \n1 read array\n2 display\n3 for insert by pos\n4 for insert by order\n5 for delbypos\n6 for delbykey\n7 for search by key\n8 for search by pos\n9 for reverse\n15 exit\n");
    int ch;
    for(;;){
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                read(a);break;
            case 2:
                display(a);break;
            case 3:
                a=insbypos(a);break;
            case 4:
                a=insbyoredr(a);break;
            case 5:
                a=delbypos(a);break;
            case 6:
                a=delbykey(a);break;
            case 7:
                searchbykey(a);break;
            case 8:
                srachbypos(a);break;
            case 9:
                reverse(a);break;
            case 15:
                exit(0);
        }
    }
    
}

