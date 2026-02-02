#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "std_node.h"

int main(int argc, const char * argv[]) {
    int i,n;
    nodePtr head,temp;
    head=(nodePtr)malloc(sizeof(node));
    temp=head;
    if(argc<2) return 0;
    n=(argc-1)/2;

    for(i=0;i<n-1;i++){
        temp->id=atoi(argv[i * 2 + 1]);
        strcpy(temp->name, argv[i * 2 + 2]);
        temp->next=(nodePtr)malloc(sizeof(node));
        temp=temp->next;
    }
    temp->id=atoi(argv[i * 2 + 1]);
    strcpy(temp->name, argv[i * 2 + 2]);
    temp->next= NULL;
    
    temp=head;
    while (temp) {
        printf("%d %s\n", temp->id, temp->name);
        temp = temp->next;
    }

    temp=head;
    while(temp){
        head=head -> next;
        free(temp);
        temp=head;
    }
    return 0;
}