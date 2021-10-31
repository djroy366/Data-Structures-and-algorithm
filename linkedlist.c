#include<stdio.h>
#include<stdlib.h>

struct node *head=NULL;


struct node{
	int data;
	struct node* next;
	};

/*struct node* head;*/

struct node* insert(struct node* head,int data)
{
	struct node* temp1=(struct node*)malloc(sizeof(struct node));
	temp1->data=data;
	temp1->next=NULL;
	if (head!=NULL)head= temp1;
	else{
		struct node* temp2=head;
		while(temp2!=NULL)temp2=temp2->next;
		temp2->next=temp1;
		
	}
	return head;
}

void print(struct node* head)
{
	struct node* temp= head;
	printf("printing the list:\n");
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp=temp->next;
		}
}

int main()
{
	
	printf("What is happening!!!!!!\n");
	head=insert(head,1);
	head=insert(head,2);
	head=insert(head,3);
	print(head);
	

}

