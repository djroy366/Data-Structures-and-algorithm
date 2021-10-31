#include<stdio.h>
#include <stdlib.h>

struct QNode{
	int data;
	struct QNode* next;
};

struct Queue{
	struct QNode* front;
	struct QNode* rear;
};

struct Queue * CreatQueue(){
	struct Queue* temp_queue;
	struct QNode* temp;
	temp_queue=(struct Queue*)malloc(sizeof(struct Queue));
	temp=(struct QNode*)malloc(sizeof(struct QNode));
	temp_queue->front=temp_queue->rear=NULL;
	return temp_queue;
}

void Insert_element(struct Queue* Q, int data){
	struct QNode* new;
	new=(struct QNode*)malloc(sizeof(struct QNode));
	new->data=data;
	new->next=NULL;
	if(Q->rear)Q->rear->next=new;
	Q->rear=new;
	if(Q->front==NULL)Q->front=Q->rear;
}


void Delete_Queue(struct Queue* Q){
	struct QNode* temp;
	while(Q){
		temp=Q->front;
		temp=temp->next;
		free(temp);
	}
	free(Q);
}

void frontPrint(struct Queue* Q){
	if(Q->front)printf("Front Element Is: %d \n",Q->front->data);
	else printf("Queue is Empty\n");
}

void rearPrint(struct Queue* Q){
	if(Q->rear)printf("Rear Element is:%d \n",Q->rear->data);
	else printf("Queue is Empty\n");
}


void max_value(struct Queue* Q){
	if(Q->front){
		struct QNode* new=Q->front;
		int k;
		while(!new){
			k=k+new->data;
			new=new->next;
		}
	printf("Max value:%d\n",k);
	}
}

int main(){
	struct Queue* Q=CreatQueue();
	Insert_element(Q,2);
	Insert_element(Q,3);
	Insert_element(Q,4);
	frontPrint(Q);
	rearPrint(Q);
	max_value(Q);
}
