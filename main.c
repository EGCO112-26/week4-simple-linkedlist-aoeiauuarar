//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int c=5;
    struct node a,b,*head,d,e,f;
    a.value = c;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
    b.next=&d;
    d.value = 11;
    d.next=NULL;
    printf("%d\n", head ->next->next->value ); //11
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
     
*/
    e.value=2;
    e.next=&a;
    head=&e;
    printf("\n");
    printf("%d\n", head->value );//2
    printf("%d\n", head ->next->value );
    printf("%d\n", head ->next->next->value );
    printf("%d\n", head ->next->next->next->value );

// Exercise II.V add 7 in

    f.value=7;
    f.next=&b;
    a.next=&f;
    printf("\n");
    printf("%d\n", head->value );
    printf("%d\n", head ->next->value );
    printf("%d\n", head ->next->next->value );//7
    printf("%d\n", head ->next->next->next->value );
    printf("%d\n", head ->next->next->next->next->value );
    
    typedef struct node* NodePtr;
    NodePtr tmp=head; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    int i,n=5;
    printf("\nloop\n");
    for(i=0;i<n;i++){
        printf("%3d", tmp->value);
        tmp=tmp->next; // What is missing??? thissss
    }
    printf("\n");
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    tmp=head;
    printf("\nloop(NULL)\n");
    while(tmp!=NULL){ //while(tmp) is sameๆ naaa
        printf("%3d", tmp->value);
        tmp=tmp->next;// What is missing???
    }
    printf("\n");
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
    typedef struct node* nodePtr;
    nodePtr Head,temp;
    /*Head = (nodePtr)malloc(sizeof(struct node));
    temp=Head;
    Head->value =7;
    Head->next = (nodePtr)malloc(sizeof(struct node));
    Head->next->value =9;
    Head->next->next = (nodePtr)malloc(sizeof(struct node));
    Head->next->next->value =11;
    Head->next->next->next =NULL;

    printf("\nloop(NULL)(use malloc)\n");
    while(temp!=NULL){
        printf("%3d", temp->value);
        temp=temp->next;
    }
    printf("\n");

    free(Head);*/
    
    Head = (nodePtr)malloc(sizeof(struct node));
    temp=Head;
    n=4;
    printf("\nmalloc loop\n");
    for(i=0;i<n;i++){
        temp->value=7+i*2;
        temp->next = (nodePtr)malloc(sizeof(struct node));
        temp=temp->next;
    }
    temp->value=7+i*2;
    temp->next=NULL;

    temp=Head;
    while(temp!=NULL){ 
        printf("%3d", temp->value);
        temp=temp->next;
    }
    printf("\n");




    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */
    temp=Head;
    printf("\nFree loop\n");
    while(temp!=NULL){ 
        Head=Head->next;
        printf("Free %d\n",temp->value);
        free(temp);
        temp = Head;
    }
    
    return 0;
}
