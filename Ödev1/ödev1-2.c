#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
   int x;
   struct node*next;
};

int main() {
    struct node*root=(struct node*)malloc(sizeof(struct node));
    root->next=NULL;
    struct node * iter= root;   
    int num;

    scanf("%d",&num);
    
  while (num!=-1){
        iter->x=num; 
        iter->next=(struct node*)malloc(sizeof(struct node));
        iter=iter->next;
        iter->next=NULL;
        scanf("%d",&num);
    }
   
    iter = root;
    while(iter->next!=NULL){ 
        if((iter->x) < (iter->next->x)){
        while((iter->x) < (iter->next->x)){
        	printf("%d ",iter->x);
        	if(iter->next!=NULL){        
        	iter=iter->next;
        	}
        } 
        printf("%d\n",iter->x);
        if(iter->next!=NULL)
        {        
        iter=iter->next;
        }
        }
        if((iter->x) > (iter->next->x)){
        while((iter->x) > (iter->next->x)){
        	printf("%d ",iter->x);
        	if(iter->next!=NULL){        
        	iter=iter->next;
        	}
        } 
        printf("%d\n",iter->x);
        if(iter->next!=NULL){        
        iter=iter->next;
        }   }               	
    }      
  return 0;   
}