#include <stdio.h>
#include <stdlib.h>

int size;

struct student{
    char name[30];
    int reg;
    int marks[3];
    float avg;
};

void read(struct student *st){
    int n=0;
    printf("Enter the size : ");
    scanf("%d",&n);
    if(n>size){
        printf("List is Short Reallocating Memory");
        st = (struct student *)realloc(st,(n-size)*sizeof(struct student));
        printf("Allocating Successfully");
        size=n;
    }
    for(int i=0;i<size;i++){
        printf("Enter the Student name and Reg : ");
        scanf("%s",&((st+i)->name));
        scanf("%d",&(st+i)->reg);
        printf("Enter the marks of 3 subs : ");
        for(int j=0;j<3;j++){
            scanf("%d",&(st+i)->marks[j]);
        }
    }
}

void display(struct student *st){
    if(size==0)
        {
        printf("List is Empty!");
        return;
    }

    printf("reg\tname\tm1\tm2\tm3\tavg\n");
    for (int i = 0; i < size; i++) {
    printf("%d\t%s\t%d\t%d\t%d\t%.2f\n", 
           (st + i)->reg, (st + i)->name, 
           (st + i)->marks[0], (st + i)->marks[1], (st + i)->marks[2], 
           (st + i)->avg);
    }

}

void avg(struct student *st){
    int  temp;
    for(int i=0;i<size;i++){
        for (int j=0;j<3;j++){
            for(int k=0;k<3-j-1;k++){
                if((st+i)->marks[k]>(st+i)->marks[k+1]){
                    temp =(st+i)->marks[k];
                    (st+i)->marks[k]=(st+i)->marks[k+1];
                    (st+i)->marks[k+1]=temp;      
                }
            }
        }
        (st+i)->avg=((st+i)->marks[1]+(st+i)->marks[2])/2.0;
    }
}

void sort(struct student *st){
    struct student temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if((st+j)->reg>(st+j+1)->reg){
                temp = *(st+j);
                *(st+j)=*(st+j+1);
                *(st+j+1) = temp;
            }
        }
    }
}
void main(){
    printf("Enter the size : ");
    scanf("%d",&size);
    struct student *st=(struct student *)malloc(size*sizeof(struct student));

    read(st);
    avg(st);
    display(st);
    sort(st);
    display(st);
}