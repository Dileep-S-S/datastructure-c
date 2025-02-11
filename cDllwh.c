#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    struct node *prev;
    int data;
};
typedef struct node * Node;


Node getnode(int val){
    Node new = (Node)malloc(1*sizeof(Node));
    new->data=val;
    new->next=new->prev=new;
    return new;
}

Node insfr(Node head){
    Node first = head->next;int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    Node new = getnode(val);
    if(head->next==NULL){
        head->next=head->prev=new;
        new->prev=new->next=head;
        return head;
    }
    new->next=head->next;
    new->prev=head;
    first->prev=new;
    head->next=new;
    return head;
}

Node  insrear(Node head){
    Node last=head->prev;int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    Node new = getnode(val);
    if(head->next==NULL){
        head->next=head->prev=new;
        new->prev=new->next=head;
        return head;
    }
    new->prev=last;
    new->next=head;
    head->prev=new;
    last->next=new;
    return head;
}

Node delfr(Node head){
    if(head->next==head){
        printf("Empty list");
        return head;
    }
    Node temp= head->next;
    head->next=temp->next;
    temp->next->prev=head;
    free(temp);
    return head;
}
Node delrear(Node head){
    if(head->next==head){
        printf("Empty list");
        return head;
    }
    Node last=head->prev;
    last->prev->next=head;
    head->prev=last->prev;
    free(last);
    return head;
}
Node insbypos(Node head){
    int pos ,key;
    printf("Enter the key to insert : ");
    scanf("%d",&key);
    printf("Enter the position : ");
    scanf("%d",&pos);
    Node new=getnode(key);
    if(pos!=1&&head->next==NULL){
        printf("invalid position \n");
        return head;
    }
    else if(pos==1&&head->next==NULL){
        head->next=head->prev=new;
        new->prev=new->next=head;
        return head;
    }else{
        Node prev=head;
        Node cur=head->next;
        while(pos!=1&&cur!=head){
            prev=cur;
            cur=cur->next;
            pos--;
        }
        if(cur==head&&pos!=1){
            printf("invalid position \n");
        }else{
            prev->next=new;
            new->prev=prev;
            cur->prev=new;
            new->next=cur;
        }
        return head;
    }
}

Node delbypos(Node head){
    if(head->next==head){
        printf("Empty list");
        return head;
    }
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos!=1 && head->next==NULL){
        printf("invalid position");
    }else if (pos==1 && head->next!=NULL){
        return delfr(head);
    }else{
        Node par=head;
        Node cur=head->next;
        while(cur!=head&&pos!=1){
            par=cur;
            cur=par->next;
            pos--;
        }
        if(cur==head||pos!=1){
            printf("invalid pos");
        }
        else{
            par->next=cur->next;
            cur->next->prev=par;
            free(cur);
            return head;
        }
    }
    
}
void search(Node head){
    if(head->next==head){
        printf("Empty list\n");
        return;
    }
    Node temp=head->next;
    int pos=0,ele;
    printf("ENter the element to search : ");
    scanf("%d",&ele);
    while(temp!=head){
        pos++;
        if(temp->data==ele){
            printf("THe element %d is in position %d",ele,pos);
            return ;
        }
        temp=temp->next;
    }
    printf("Not found");
}
Node delbykey(Node head){
    if(head->next==head){
        printf("Empty list\n");
        return head;
    }
    int key;
    printf("Enter the value : ");
    scanf("%d",&key);
    Node prev=head;
    Node cur=head->next;
    while(cur!=head){
        if(cur->data==key){
            prev->next=cur->next;
            cur->next->prev=prev;
            free(cur);
            return head;
        }
        prev=cur;
        cur=cur->next;
    }
    printf("Not found");
    return head;
}
Node insbyord(Node head){
    if(head->next==head){
        return insfr(head);
    }
    int key;
    printf("Enter the value : ");
    scanf("%d",&key);
    Node new=getnode(key);
    Node prev=head;
    Node cur=head->next;
    while(cur!=head&&cur->data<key){
        prev=cur;
        cur=cur->next;
    }
    new->next=cur;
    new->prev=prev;
    prev->next=new;
    cur->prev=new;
    return head;
}
void display(Node head){
    if(head->next==head){
        printf("Empty list\n");
        return;
    }
    Node temp=head->next;
    while(temp!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void main(){
    int ch;
    Node head = getnode(0);
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
                head = insbypos(head);break;
            case 7:
                head = delbypos(head);break;
            case 8:
                search(head);break;
            case 9:
                head = delbykey(head);break;
            case 10:
                head = insbyord(head);break;
            case 11:
                exit(0);
        }
    }
}