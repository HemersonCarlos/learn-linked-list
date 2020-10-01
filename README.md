#include<stdio.h> 
#include<stdlib.h>

void create();
void display();


struct node
{
	int data;
	struct node *next;
	
};

struct node *head=NULL;
 int count=0;
int main()
{
	create();
	display();
	printf("\n The number of elements in the linked list is %d",count);
	return 0;
}
void create()
{
    	int m ,ch;
	    struct node *temp ,*ptr;
	    
	    do {
 
	  printf("\n enter the data you want to enter ");
	  scanf("%d",&m);
	  temp=(struct node*)malloc(sizeof(struct node));
	  temp->data=m;
	  temp->next=NULL;
	  if(head==NULL)	
	  {
	  	head = temp;
	  }
		else
		{
		    ptr=head;
	    	while(ptr->next!=NULL)
	    	ptr=ptr->next;
	    	ptr->next=temp;	
	    }
	        printf("\n to insert more type 1");
	    	scanf("%d",&ch)	;
		
  } while(ch==1);
}
 void display()
 {
 	struct node *ptr;
 	ptr=head;
 	 while(ptr!=NULL)
 	{
 		printf("%d->",ptr->data);
 		count++;
 		ptr=ptr->next;
	 }
	 
 }  
