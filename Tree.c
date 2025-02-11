#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *lchild;
    int info;
    struct node *rchild;
};

typedef struct node* NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

NODE myinsert(NODE root){
    NODE prev,cur,temp;
    temp=getnode();
    temp->rchild=temp->lchild=NULL;
    int item;
    printf("Enter the Element : ");
    scanf("%d",&item);
    temp->info=item;
    if(root==NULL)
        return temp;
    cur=root;
    prev=NULL;
    while(cur!=NULL){
        prev=cur;
        if(cur->info<item){
            cur=cur->rchild;
        }else{
            cur=cur->lchild;
        }
    }
    if(prev->info<item){
        prev->rchild=temp;
    }else{
        prev->lchild=temp;
    }
    return root;
}


void inorder(NODE root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d ",root->info);
        inorder(root->rchild);
    }
}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d ",root->info);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->info);
    }
}

NODE search(int ele,NODE root,NODE parent){
    NODE cur=root;
    parent = NULL;
    if(root!=NULL){
        while(cur!=NULL && cur->info!=ele){
            parent=cur;
            if(cur->info>ele){
                cur=cur->lchild;
            }
            else{
                cur=cur->rchild;
            }
        }
    }
    return cur;
}
NODE min(NODE root){
    NODE temp=root;
    while (temp && temp->lchild==NULL){
        temp = temp->lchild;
    }
    return temp;
}
NODE deletefinale(int item,NODE root){
    if(root == NULL){
        return root;
    }
    if(root->info>item){
        root->lchild = deletefinale(item,root->lchild); 
    }else if(root->info<item){
        root->rchild = deletefinale(item,root->rchild);
    }else{
        if(root->lchild == NULL){
            NODE temp = root->rchild;
            free(root);
            return temp;
        }else if(root->rchild == NULL){
            NODE temp = root->lchild;
            free(root);
            return temp;
        }
        NODE temp = min(root);
        root->info = temp->info;
        root->rchild = deletefinale(temp->info, root->rchild);
    }
    return root;
}

NODE delete(int item,NODE root){
    NODE temp,parent,cur,suc;
    cur= search(item,root,parent);
    if(cur==NULL){
        printf("Element not found");
        return root;
    }
    if(cur->lchild!=NULL&&cur->rchild!=NULL){
        parent = cur;
        suc=cur->rchild;
        while(suc->lchild!=NULL){
            parent=suc;
            suc=suc->lchild;
        }
        cur->info = suc->info;
        cur = suc; 
    }
    if(cur->lchild!=NULL){
        temp=cur->lchild;
    }
    else{
        temp=cur->rchild;
    }
    if(parent==NULL){
        root=temp;
    }else if(parent->lchild==cur){
        parent->lchild=temp;
    }else{
        parent->rchild=temp;
    }
    free(cur);
    return root;
}

NODE delete_item(int item, NODE root) {
    NODE cur, parent, suc, temp;
    cur = search(item, root, parent);
    if (cur == NULL) {
        printf("Item not found\n");
        return root;
    }
    if (cur->lchild != NULL && cur->rchild != NULL) {
        parent = cur;
        suc = cur->rchild;
        while (suc->lchild != NULL) {
            parent = suc;
            suc = suc->lchild;
        }
        cur->info = suc->info;
        cur = suc;
    }
    temp = (cur->lchild != NULL) ? cur->lchild : cur->rchild;
    if (parent == NULL) root = temp;
    else if (parent->lchild == cur) parent->lchild = temp;
    else parent->rchild = temp;
    free(cur);
    return root;
}

int count(NODE root){
    if(root==NULL){
        return 0;
    }
    return 1+count(root->lchild)+count(root->rchild);
}
int height(NODE root){
    if(root==NULL) return 0;
    int left = height(root->lchild);
    int right = height(root->rchild);
    return 1+(left > right  ? left : right );
}

void max_node(NODE root){
    if(root==NULL){
        printf("Emty tree\n");
        return;
    }
    NODE parent=NULL,temp=root;
    while(temp->rchild!=NULL){
        parent=temp;
        temp=temp->rchild;
    }
    printf("max_NOde  %d\n",temp->info);
    if(parent!=NULL)
        printf("parent %d\n",parent->info);
    else  
        printf("parent not found\n");
    return;
}
void bfs(NODE root){
    if(root==NULL){
        printf("Emty tree\n");
        return;
    }
    NODE q[30];
    int front=0,rear=0;
    q[rear++]=root;
    NODE cur=NULL;
    while(front<rear){
        cur=q[front++];
        printf("%d ",cur->info);
        if(cur->lchild!=NULL){
            q[rear++]=cur->lchild;
        }
        if(cur ->rchild!=NULL){
            q[rear++]=cur->rchild;
        }
    }
    printf("\n");
}
// void bfs(NODE root) {
//     if (root == NULL) return;

//     NODE queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;

//     while (front < rear) {
//         NODE current = queue[front++];
//         printf("%d ", current->info);

//         if (current->lchild != NULL)
//             queue[rear++] = current->lchild;
//         if (current->rchild != NULL)
//             queue[rear++] = current->rchild;
//     }
// }

int main() {
    NODE root = NULL, temp, parent;
    int choice, item;
    printf("\n1: Insert  2: Preorder\n3: Postorder 4: Inorder\n5: Search 6: Delete\n7: Max Node\n8: Count Nodes\n9: Height\n10: Exit\n 11. BFS\n");
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: root = myinsert(root); break;
            case 2: preorder(root); printf("\n"); break;
            case 3: postorder(root); printf("\n"); break;
            case 4: inorder(root); printf("\n"); break;
            case 5: 
                printf("Enter item to search: ");
                scanf("%d", &item);
                temp = search(item, root, parent);
                if (temp)
                    if (parent != NULL)
                    printf("Found node: %d, Parent exists: %d\n", temp->info, parent->info);
                    else
                    printf("Found node: %d, No parent\n", temp->info);
                else
                    printf("Not found\n");
                break;
            case 6: 
                printf("Enter item to delete: ");
                scanf("%d", &item);
                root = deletefinale(item, root);
                break;
            case 7: max_node(root); break;
            case 8: printf("Total nodes: %d\n", count(root)); break;
            case 9: printf("Height: %d\n", height(root)); break;
            case 10: exit(0);
            case 11: bfs(root);
        }
    }
}