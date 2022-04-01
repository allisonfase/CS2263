#include <stdio.h>
#include <stdlib.h>
#include "Point2D.h"

typedef struct pt2link {
    Point2D* payload;
    struct pt2link* next;
} PtLink, *pPtLink;



//create a PtLink pointer using given Point2D object
PtLink* createNode(Point2D point){
  PtLink* link=(PtLink*) malloc(sizeof(PtLink));
  link->payload=(Point2D*) malloc(sizeof(Point2D));
  link->payload->x=point.x;
  link->payload->y=point.y;   
  link->next=NULL;
  
  return link;
}

//free malloc of node 
void deleteNode(PtLink* node){      
  free(node->payload);
  free(node);
}


//part one: the stack
PtLink* push(PtLink* top, Point2D point){      
  PtLink* link=createNode(point);       
  link->next=top;
  return link;
}

//pop the top element
//return the new top node
PtLink* pop(PtLink* top){       
  if(top==NULL){
    return NULL;
  }       
  PtLink* link=top;      
  top=top->next;      
  deleteNode(link);       
  return top;
}

//return payload of top of stack without removing it
Point2D* peek(PtLink* top){
  if(top==NULL){
    return NULL; //empty stack
  }
  return top->payload;
}

//print the contents of a stack
void printStack(PtLink* top){
  printf("Stack (top-bottom):\n ");
  for(PtLink* n=top;n!=NULL;n=n->next){
    printf("(%.1f,%.1f) addr: %p, %p, %p \n",n->payload->x,n->payload->y, top, n->payload->x, n->next);
    if(n->next!=NULL){
      printf(" -> ");
      }
  }
  printf("\n");
}

//delete a stack
void deleteStack(PtLink* top){       
  while(top!=NULL){
    top=pop(top);
  }
}


//adds an element to the end of queue, returns the front node
PtLink* enqueue(PtLink* front, Point2D point){
  PtLink* link=createNode(point);
  if(front==NULL){
    return link;
  }
  PtLink* temp=front;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=link;
  return front;
}

//removes the front node and returns new front
PtLink* dequeue(PtLink* front){
  if(front==NULL){
    return NULL; //empty queue
  }
  PtLink* temp=front;
  front=front->next;
  deleteNode(temp);
  return front;
}

//returns the payload of front node in a queue, or NULL if queue is empty
Point2D* peekQueue(PtLink* front){
  if(front==NULL){
    return NULL;
  }
  return front->payload;
}

//prints the contents of a queue
void printQueue(PtLink* front){
  printf("Queue (front-rear):\n ");
  for(PtLink* n=front;n!=NULL;n=n->next){
    printf("(%.1f,%.1f)", n->payload->x, n->payload->y);
    printf("addr: (PtLink)%p, (next)%p, (payload)%p\n", n, n->next, n->payload);
    if(n->next!=NULL){
      printf(" -> ");
    }
  }
  printf("\n");
}

//deletes a queue
void deleteQueue(PtLink* top){
  while(top!=NULL){
    top=dequeue(top);
  }
}


int main(){
  PtLink* top=NULL;
  //choosing 5 as arbitrary stack size
  for(int i=1;i<=6;i++){
    Point2D p;
    p.x=i;
    p.y=i;
    top=push(top,p);
    printStack(top);
   }
  
   while(top!=NULL){
     top=pop(top);
     printStack(top);
   }
  
   printf("\n\n");
  
   //part two: the queue
   PtLink* front=NULL;
   //choosing 5 as arbitrary queue size
   for(int i=1;i<=5;i++){
       Point2D p;
       p.x=i;
       p.y=i;
       front=enqueue(front,p);
       printQueue(front);
   }
   while(front!=NULL){
       front=dequeue(front);
       printQueue(front);
   }

   return EXIT_SUCCESS;  
}
//testing
