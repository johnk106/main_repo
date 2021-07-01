#include<stdio.h>
#include<stdli.h>

struct node{
	struct node *prev;
	struct node *next;
	int data;
};

struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();

void main(){
	int choice = 0;
	
	while(choice != 9){
		printf("WELCOME TO THE MAIN MENU")
		printf("CHOOSE ONE OPTION")
		printf("\n1.insert in begenning\2.insert at last\n3.insert at rendom location\n4.delete from beginning\n5.delete from last\6.delete node after taking in data\n7.search\n8.show\n9.exit");
		prinf("enter your choice:");
		scanf("\n%d",&choice);
		switch(choice){
			case 1:
				insertion_beginning();
				break;
			case 2:
				insertion_last();
				break;
			case 3:
				insertion_specified();
				break;
			case 4:
				deletion_beginning();
				break;
			case 5:
				deletion_last();
				break;
			case 6:
				deletion_specified();
				break;
			case 7:
				search();
				break;
			case 8:
				display();
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("PLEASE ENTER A VALID CHOICE!")
		}
	}
}
void insertion_beginning(){
	struct node *ptr;
	int item;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("\nOVERFLOW");
	}
	else{
		printf("enter item value");
		scanf("%d",&item);
		
		
	if(head == NULL){
		ptr->next = NULL;
		ptr ->prev = NULL;
		ptr -> data = item;
		head = ptr;
	}
	else{
		ptr -> data=item;
		ptr -> prev = NULL;
		ptr -> next = head;
		head ->prev = ptr;
		head=ptr;
	}
	print("\nNode inserted\n");
		
	}
}

void insertion_last(){
	struct node *ptr,*temp;
	int item;
	ptr = (struct node*)malloc(sizeof(struct node));
	if (ptr == NULL){
		printf("\nOVERFLOW");
	}
	else{
		printf("\nEnter value");
		scanf("%d",&item);
		ptr -> data=item;
		if(head == NULL){
			ptr -> next = NULL;
			ptr -> prev = NULL;
			head = ptr;
		}
		else{
			temp = head;
			while(temp -> next!=NULL){
				temp = temp -> next;
			}
			temp -> next = ptr;
			ptr -> prev =temp;
			ptr -> next = NULL;
		}
	}
	prinf("\nNode inserted\n");
}

void insertion_specified(){
	
	struct node *ptr,*temp;
	int item,loc,i;
	ptr = (struct node*)malloc(sizeof(struct node));
	
	if(ptr == NULL){
		printf("\nOVERFLOW\n");
	}
	else{
		temp = head;
		printf("Enter the location");
		scanf("%d",&loc);
		for(i=0,i<loc,i++)
		{
			temp = temp->next;
			if(temp == NULL){
				printf("\nthere are less then %d elements",loc);
				return;
			}
			
		}
		printf("enter a value");
		scanf("%d",&item);
		ptr -> data = item;
		ptr -> next = temp -> next;
		ptr -> prev = temp;
		temp -> next = ptr;
		temp -> next -> prev = ptr;
		printf("\nnode inserted\n");
	}
}

void deletion_beginning(){
	struct node *ptr;
	if(head == NULL){
		printf("\nUNDERFLOW");
	}
	else if(head -> next == NULL){
		head = NULL;
		free(head);
		printf("\nnode deeted\n");
	}
	
else{
	ptr = head;
	head = head -> next;
	head = -> prev = NULL;
	free(ptr);
	printf("\nnode deleted\n");
}
}

void deletion_last(){
	struct node *ptr;
	if(head == NULL){
		printf("\nUNDERFLOW\n");
		
	}
	else if(head -> next == NULL){
	head = NULL;
	free(head);
	printf("\nnode deleted\n");
	
	}
	else{
		ptr = head;
		if(ptr -> next!=NULL){
			ptr = ptr -> next;
		}
		ptr -> prev -> next = NULL;
		free(ptr);
		printf("\nnode  deleted\n");
		
	}
}

void deletion_specified(){
	struct node *ptr,*temp;
	int val;
	printf("\n enter the data after which the node is to be deleted:");
	scanf("%d",&val);
	ptr = head;
	while(ptr -> data != val)
	
	ptr = ptr -> next;
	
	if(ptr -> next == NULL){
		printf("\ncant delete\n");
	}
	else if(ptr -> next == NULL){
		ptr -> next = NULL;
	}
	else{
		temp = ptr -> next;
		ptr -> next = temp -> next;
		temp -> next -> prev = ptr;
		free(temp);
		printf("\nnode deleted\n");
	}
}


void display(){
	struct node *ptr;
	printf("\nprinting values...\n");
	ptr = head;
	while(ptr!=NULL){
		printf("%d\n",ptr -> data);
		ptr = ptr->next;
	}

}

void search(){
	struct node *ptr;
	int item,i=0,flag;
	ptr = head;
	if(ptr == NULL){
		printf("\nempty list\n");
		
	}
	else{
		printf("enter the search query:");
		scanf("%d",&item);
		while(ptr!=NULL){
			if(ptr -> data == item)
			{
				printf("\n item found at location %d",i+1);
				flag =0;
				break;
			}
			else{
				flag = 1;
			}
			1++;
			ptr = ptr -> next;
		}
		if(flag == 1){
			printf("\nitem not found \n");
		}
	}
	
}























































