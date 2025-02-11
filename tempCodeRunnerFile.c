void pushfront(int val){
//     if(Q.rear=size-1){
//         printf("reallocating Memory\n");
//         size *= 2;
//         Q.queue=(int *)realloc(Q.queue,size*(sizeof(int)));
//     }
//     if(Q.front ==-1){
//         Q.front=Q.rear=0;
//         Q.queue[Q.front]=val;
//     }else {
//         for(int i=Q.rear;i>=Q.front;i--){
//             Q.queue[i+1]=Q.queue[i];
//         }
//         Q.queue[Q.front]=val;
//         Q.rear++;
//     }
// }