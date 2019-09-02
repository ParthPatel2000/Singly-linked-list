#include<stdio.h>
#include<stdlib.h>
int ret=0;
struct node
{
int info;
struct node *next;	
};
struct node*start=NULL;
struct node*ptr=NULL;
struct node *temp=NULL;

void create()
{
	int i,no,val;
	printf("ENTER the no of elements in the List:  ");
	scanf("%d",&no);
	struct node*temp;
	for(i=1;i<=no;i++)
	{
		struct node*ptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=NULL;
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
	if(t==NULL)
	{
		printf("The List is empty\n");
		exit(0);
	}
	printf("The elements of the List are-> ");
	while(t!=NULL)
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
	ptr->next=NULL;
	if(t==NULL)
	{
		start=ptr;
	}
	else
	{
		while(t->next!=NULL)
		{
		t=t->next;
		}	
		t->next=ptr;
	}
}
void insert_beg()
{
	int i,val;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=NULL;
		printf("Enter the value");
		scanf("%d",&ptr->info);
		
		if(start==NULL)
		{
			start=ptr;
		}
		else
		{
			ptr->next=start;
			start=ptr;
		}	
}


void concatinate()
{
	int i,no,val;
	struct node*new;
	printf("ENTER the no of elements to be added to the List:  ");
	scanf("%d",&no);
	struct node*temp;
	for(i=1;i<=no;i++)
	{
		struct node*ptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=NULL;
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
		if(t==NULL)
	{
		start=new;
	}
	else
	{
		while(t->next!=NULL)
		{
		t=t->next;
		}	
		t->next=new;
	}
}

void delete_end()
{
		struct node *pre,*post;
		if(start==NULL)
		{
			printf("There is no linked List ");
		}
		else
		{
			if(start->next==NULL)
			{
				printf("THE deleted element is %d",start->info);
				temp=start;
			}
			else
			{
			pre=start;
			post=start->next;
			while(post->next!=NULL)
			{
				pre=pre->next;
				post=post->next;
			}
			temp=post;
			pre->next=NULL;
			printf("THE Deleted value is %d\n",temp->info);
			}
			free(temp);
		}	
}

void delete_beg()
{
		if(start==NULL)
		{
			printf("There is no linked List");	
		}
		else
		{
		    temp=start;
			start=start->next;
			printf("THE Deleted value is %d\n",temp->info);
			free(temp);
		}	
}



void insertat(int pos)
{
	int i=1,val,flag=0;
	struct node *pre;
	struct node *post;
	ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=NULL;
		printf("Enter the value");
		scanf("%d",&ptr->info);
		
		if(start==NULL)
		{
			if(pos==1)
			{
			start=ptr;
			}
			else
			{
			free(ptr);
			printf("The linked List is not that long");
			}			
		}
		else
		{
			if(pos==1)
			{
				ptr->next=start;  //can also use insert_beg
				start=ptr;
			}
			else
			{
				pre=start;
				post=start->next;
				for(i=1;i<=pos-2;i++)
				{
					pre=pre->next;
					post=post->next;
					if(i!=pos-2&&pre==NULL)
					{
						printf("The linked List is not that long");
						break;
					}
					else
					{
						if(i==pos-2)
						{
							if(post!=NULL)
							{
								flag=1;	
							}		
							else
							{
								pre->next=ptr;
							}
						}	
					}
	  		}
	  		if(flag==1||pos==2)
	  		{
		  	pre->next=ptr;
			ptr->next=post;
		  	}
					
		}
	}
}


void deleteat(int pos)
{
	int flag=0,i;
	struct node *pre;
	struct node *post;
	if(start==NULL)
	{
	printf("NO linked list Here");
	}
	else
	{
		if(pos==1)
		{
			delete_beg();
		}
		else
		{
			pre=start;
			post=start->next;
			for(i=1;i<=pos-2;i++)
			{
				pre=pre->next;
				post=post->next;
				if(i!=pos-2&&pre->next==NULL)
				{
					printf("The linked list is not that long");
					break;	
				}
				else
				{
				 	if(i==pos-2)
			 		{
 						if(post!=NULL)
 						{
						 	flag=1;
						 }
						 else
						 {
 							delete_end();
 						}
 					}	
				}
			}
		}
		
		if(flag==1||pos==2)
		{
			temp=post;
			pre->next=post->next;
			printf("The Deleted value is %d ",temp->info);
			free(temp);
		}
	}
}

void search(int val)
{
     temp=start;
     int pos=1,flag=0;
     while(temp!=NULL)
     {
	  if(val==temp->info)
   	  {
       		printf("The value is found at %d\n",pos);
		flag=1;
		ret=pos;
		break;
    	  }
	else
        {  
        	temp=temp->next;
        }
	pos++;
     }
	if(flag==0)
	{
	printf("THE VALUE IS NOT FOUND\n");
	}
}

void deleteval(int val)
{
	search(val);
	if(ret!=0)
{
	deleteat(ret);
	ret=0;
}
}

void sort()
{	
	int i=1,tempcount=1;
	struct node *temphead,*small,*pretemp,*prehead=NULL,*presmall;
	temphead=start;
	pretemp=NULL;
	temp=start;
	small=start;
	while(temphead!=NULL)
	{
		while(temp!=NULL)
		{
			if(small->info>=temp->info)
			{
				presmall=pretemp;
				small=temp;
			}
			if(tempcount==1)
			{
				pretemp=temphead;
				temp=temp->next;
			}
			else
			{
				temp=temp->next;
				pretemp=pretemp->next;
			}
			tempcount++;
		}
		if(i==1)
		{
			if(temphead==small)
			{
				temphead=temphead->next;
				prehead=start;
			}
			else
			{
				presmall->next=small->next;
				small->next=start;
				start=small;
				prehead=start;
			}
		}
		else
		{
			if(temphead==small)
			{
				temphead=temphead->next;
				prehead=prehead->next;
				printf("flag7");
			}
			else
			{
				presmall->next=small->next;
				prehead->next=small;
				small->next=temphead;
				prehead=small;
			}
		}
		small=temphead;
		temp=temphead;
		pretemp=NULL;
		i++;
		tempcount=1;
		
	}
	
}


int main()
{
	int sel,pos;
    char opt;
    printf("Singly linked list");
   while(sel!=-1)
   {
   	 printf("\nmenu\n");	
    printf("\n1.CREATE\n2.SEARCH\n3.Concatinate\n4.Insert AT Start\n5.Insert AT End\n6.Insertat\n7.Delete AT Start\n8.Delete AT End\n9.Deleteat\n10.DELETE BY VALUE\n11.SORT\n12.EXIT\n\nENTER your choice:   ");
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:create();
				display();
				break;
		case 2:printf("Enter the value to be searched");
		       	scanf("%d",&pos);	
        	 	search(pos);
			   	display();
			   	break;
		case 3:concatinate();
				display();
				break;		
		case 4:insert_beg();
				display();
				break;
		case 5:insert_end();
				display();
				break;
		case 6:printf("enter the position where you want to INSERT the value");
				scanf("%d",&pos);
				insertat(pos);
				display();
				break;			
		case 7:delete_beg();
				display();
				break;
		case 8:delete_end();
				display();
				break;
		case 9:	printf("enter the position where you want to DELETE the value");
				scanf("%d",&pos);
				deleteat(pos);
				display();
				break;				
		case 10: printf("ENter the value is to be Deleted ");
		       	scanf("%d",&pos);	
        	 	deleteval(pos);
			   	display();
			   	break;
		case 11:sort();
				printf("THE SORTED ELEMENTS ARE");	
				display();   
				break;	
		case 12:exit(0);	   	
	}
   }

}	

