//The program is self explanatory if you see the code though :D
//Also my first github code 

#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *next;	
};
struct node*start=0;


void create()
{
	int i,no,val;
	printf("ENTER the no of elements in the list:  ");
	scanf("%d",&no);
	struct node*temp;
	for(i=1;i<=no;i++)
	{
		struct node*ptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=0;
		printf("ENTER THE VALUE OF THE ELEMENT:  ");
		scanf("%d",&ptr->info);
		if(i==1)
		{
			start=ptr;
			temp=ptr;
			continue;
		}
		else
		{
		temp->next=ptr;	
		temp=ptr;
		}
		
	}
}


void display()
{
	struct node *t=start;
	if(t==0)
	{
		printf("The list is empty\n");
		exit(0);
	}
	printf("The elements of the list are-> ");
	while(t!=0)
	{
		printf("%d-",t->info);
		t=t->next;
	};
}

void insert_end()
{
	int val;
	struct node*t;
	t=start;
	printf("\nenter the element to be inserted-> ");
	scanf("%d",&val);
	struct node*ptr=(struct node*)malloc(sizeof(struct node));
	ptr->info=val;
	ptr->next=0;
	if(t==0)
	{
		start=ptr;
	}
	else
	{
		while(t->next!=0)
		{
		t=t->next;
		}	
		t->next=ptr;
	}
}



void concatinate()
{
	int i,no,val;
	struct node*new;
	printf("ENTER the no of elements to be added to the list:  ");
	scanf("%d",&no);
	struct node*temp;
	for(i=1;i<=no;i++)
	{
		struct node*ptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=0;
		printf("ENTER THE VALUE OF THE ELEMENT:  ");
		scanf("%d",&ptr->info);
		if(i==1)
		{
			new=ptr;
			temp=ptr;
			continue;
		}
		else
		{
		temp->next=ptr;	
		temp=ptr;
		}
		
	}
	struct node*t;
	t=start;
		if(t==0)
	{
		start=new;
	}
	else
	{
		while(t->next!=0)
		{
		t=t->next;
		}	
		t->next=new;
	}
}



int main()
{
	int sel;
    char opt;
    printf("Singly linked list")
   while(sel!=-1)
   {
   	 printf("\nmenu\n");	
    printf("\n1.CREATE\n2.DISPLAY\n3.Insert AT End\n4.Concatinate\n5.EXIT\n\nENTER your choice:   ");
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:create();
				break;
		case 2:display();
				break;
		case 3:insert_end();
				break;
		case 4:concatinate();
				break;
		case 5: exit(0);				
	
	}
   }

}	

