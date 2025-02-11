#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE insfr(NODE head){
    NODE new=(NODE)malloc(1*sizeof(NODE));
    printf("Enter the element to insert : ");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL){ 
        return new;
    }
    new->next=head;
    return new;

}

NODE insrear(NODE head){
    NODE new=(NODE)malloc(1*sizeof(NODE));
    printf("Enter the element to insert : ");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL){ 
        return new;
    }
    NODE temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    return head;
}

NODE delfr(NODE head){
    if(head==NULL){
        printf("Empty list\n");
        return head;
    }
    NODE t=head;
    head=head->next;
    free(t);
    printf("Node Deleted\n");
    return head;
}
NODE delrear(NODE head){
    if(head==NULL){
        printf("Empty list\n");
        return  head;
    }
    NODE temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    NODE suc=temp->next;
    temp->next=NULL;
    free(suc);
    printf("Node Deleted\n");
    return head;
}

NODE inspos(NODE head){
    NODE new=(NODE)malloc(1*sizeof(NODE));
    int pos;
    printf("Enter the value : ");
    scanf("%d",&new->data);
    printf("Enter the position : ");
    scanf("%d",&pos);
    new->next=NULL;
    if(head==NULL&&pos!=1){
        printf("invalid position\n");
        return head;
    }
    else if(pos==1&&head==NULL){
        head=new;
        return head;
    }
    else if(pos==1&&head!=NULL){
        new->next=head;
        return new;
    }
    else{
        NODE temp=head;
        NODE prev=NULL;
        while(pos!=1&&temp!=NULL){
            prev=temp;
            temp=temp->next;
            pos--;
        }
        if(temp!=NULL){
        new->next=temp;
        prev->next=new;
        return head;}
    }
    printf("invalid position\n");
    return head;
}


NODE delpos(NODE head){
    if(head==NULL){
        printf("Empty list\n");
        return  head;
    }
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos==1){
        NODE s=head;
        head=head->next;
        free(s);
        return head;
    }
    NODE temp=head;
    NODE prev=NULL;
    while(pos!=1&&temp!=NULL){
        prev=temp;
        temp=temp->next;
        pos--;
    }
    if(temp!=NULL){
    prev->next=temp->next;
    free(temp);
    return head;}
    printf("invalid position \n");
    return head;
}
void search(NODE head){
    if(head==NULL){
        printf("Empty list\n");
        return ;
    }
    NODE temp= head;
    int flag=0,val,i=1,pos;
    printf("Enter the Element to found : ");
    scanf("%d",&val);
    do{
        if(temp->data==val){
            pos=i;
            flag=1;
            break;
        }
        i++;
        temp=temp->next;
    }while(temp->next!=NULL);
    if(flag==1){
        printf("the element %d found at pos %d\n",val,pos);
    }else{
        printf("Element not found\n");
    }
}

NODE delbykey(NODE head){
    int key;
    printf("Enter the Element to del : ");
    scanf("%d",&key);
    int flag=0;
    NODE prev,temp;
    prev=NULL;temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            flag=1;
            break;
        }else{
            prev=temp;
            temp=temp->next;
        }
    }
    if(flag==1){
        if(prev==NULL){
            head=head->next;
        }
        else{
            prev->next=temp->next;
        }
        free(temp);
    }else{
        printf("NOt found");
    }

    return head;
}


NODE order(NODE head){
    NODE temp,prev,new;
    prev=NULL;
    temp=head;
    new=(NODE)malloc(1*sizeof(NODE));
    printf("Enter the Value : ");
    scanf("%d",&new->data);
    new->next=NULL;
    if(head==NULL){
        head=new;
    }
    else{
        while(temp->data<new->data){
            prev=temp;
            temp=temp->next;
        }
        prev->next=new;
        new->next=temp;
    }
    return head;
}


void display(NODE head){
    if(head==NULL){
        printf("Empty list\n");
        return ;
    }
    NODE temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}


void main(){
    NODE head=NULL;
    int ch;
    printf("1 for display \n2 for insert\n3 for insrear\n4 for delfr\n5 for delrear\n6 for ins by pos\n7 for delpos\n8 search\n9 for delbykey \n10 for order\n11for exit\n");
    for(;;){
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                display(head);break;
            case 2:
                head = insfr(head);break;
            case 3:
                head = insrear(head);break;
            case 4:
                head = delfr(head);break;
            case 5:
                head = delrear(head);break;
            case 6:
                head = inspos(head);break;
            case 7:
                head = delpos(head);break;
            case 8:
                search(head);break;
            case 9:
                head = delbykey(head);break;
            case 10:
                head = order(head);break;
            case 11:
                exit(0);
        }

    }
    return;
}