#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int ret=0;
struct node
{
int info;
struct node *next;	
};
struct node*start=NULL;
struct node*ptr=NULL;
struct node *temp=NULL;
struct node *cpy;
struct node *part1;
struct node *part2;
struct node *reverselist=NULL;

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


void display(struct node *ptr)
{
	struct node *t=ptr;
	if(t==NULL)
	{
		printf("NULL");
		
	}
	else
	{
	
	while(t!=NULL)
	{
		printf("%d-",t->info);
		t=t->next;
	}
	}
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
	printf("THE VALUE IS NOT FOUND\n");}
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

void random()
{
	srand(time(0));
	int i,no,val;
	printf("ENTER the no of elements in the List:  ");
	scanf("%d",&no);
	struct node*temp;
	for(i=1;i<=no;i++)
	{
		struct node*ptr;
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->next=NULL;
		ptr->info=rand();
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

int length=0,total=0;
int bintodec(struct node *ptr)
{
	if(ptr!=NULL)
	{
		total=bintodec(ptr->next);	
		return(total+(pow(2,length++)*ptr->info));
	}
	else
	{
		return(0);
	}
}

struct node *reverseno(struct node *ptr)
{
	struct node *templast=NULL,*last=NULL;
	if(ptr==NULL)
	{
		printf("NO linked list here");
	}
	else
	{
		if(last==NULL)
		{
			temp=ptr;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			last=temp;
		}
		
			while(ptr!=last)
			{
			temp=ptr;
			ptr=ptr->next;
			last->next=temp;
			temp->next=templast;
			templast=temp;
			}
	}
	return ptr;
}

struct node *reverse(struct node *ptr)         //START OF STACK
{
	struct node *top=NULL;
	if(ptr==NULL)
	{
		printf("The stack is EMPTY \n");
		top=NULL;
		return top;
	}
	else
	{	
		while(ptr!=NULL)
		{
		struct node *cptr=(struct  node *)malloc(sizeof(struct node));
		cptr->info=ptr->info;
		cptr->next=NULL;
		if(top==NULL)
		{
			top=cptr;
		}
		else
		{
			temp=top;
			top=cptr;
			cptr->next=temp;
		}
			ptr=ptr->next;
		}
			return top;
	}
}				 //END OF STACK
         
         
void split(struct node *ptr,int pos)
{
	if(ptr==NULL)
	{
		printf("THERE is no list");
	}
	else
	{
		int i;
		struct node*pre=NULL;
		temp=ptr->next;
		pre=ptr;
		for(i=1;i<=pos-1;i++)
		{
			pre=pre->next;
			temp=temp->next;
		}
		pre->next=NULL;
		part1=ptr;
		part2=temp;
	}
}


struct node *copy(struct node *ptr)
{
	struct node *cpyt=NULL;
	struct node *cptr=NULL;
	if(ptr==NULL)
	{
		return cpyt;	
	}
	else
	{
		while(ptr!=NULL)
		{
			
			cptr=(struct node*)malloc(sizeof(struct node));
			cptr->info=ptr->info;
			cptr->next=NULL;
			if(cpyt==NULL)
			{
				cpyt=cptr;
				temp=cptr;
			}
			else
			{
				temp->next=cptr;
				temp=cptr;
			}
			ptr=ptr->next;
		}
	}
	return cpyt;		
}


int count(struct node *ptr)
{
	int a=0;
	if(ptr==NULL)
	{
		return -1;
	}
	else
	{
		while(ptr!=NULL)
		{
			a++;
			ptr=ptr->next;
		}	
	}
	return a;
}

struct node* freelist(struct  node *ptr)
{
	if(ptr==NULL)
	{
		return ptr;
	}
	else
	{
		while(ptr!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
			free(temp);	
		}
		return  ptr;	
	}

}

void switchdefault(struct node *ptr,struct node *ptr2)
{
	printf("LIST NOW Switched\n");
	start=ptr2;
	part2=ptr;
	printf("THE DEFAULT LIST NOW IS :");
	display(start);	
}


int main()
{
	int sel,pos,a;
    char opt;
    printf("Singly linked list");
   while(sel!=-1)
   {
   	 printf("\nmenu\n");	
    printf("\n1.CREATE\n2.SEARCH\n3.Concatinate\n4.SPLIT AT\n5.SWITCH DEFAULT \n6.Insertat\n7.Deleteat\n8.DELETE BY VALUE\n9.COPY \n10.COUNT\n11.SORT\n12.BINARY TO DECIMAL\n13.REVERSE ORIGINAL\n14.REVERSE AND STORE\n15.DISPLAY ALL \n16.RANDOM\n17.EXIT\nENTER your choice:   ");
	scanf("%d",&sel);
	switch(sel)
	{
		case 1:create();
				printf("THE LIST  : ");display(start);
				break;
		case 2:printf("Enter the value to be searched");
		       	scanf("%d",&pos);	
        	 	search(pos);
			   	break;
		case 3:concatinate();
				printf("THE ELEMENTS OF THE LIST NOW ARE : ");display(start);
				break;		
		case 4: printf("Enter the posititon you want to split the list  ");
				scanf("%d",&a);
				split(start,a);
		    	printf("\nTHE FRONT PART : ");display(part1);
			    printf("\nTHE REAR PART : ");display(part2);
				break;
		case 5:switchdefault(start,part2);
				break;
		case 6:printf("enter the position where you want to INSERT the value");
				scanf("%d",&pos);
				insertat(pos);
				printf("THE ELEMENTS OF THE LIST NOW ARE : ");display(start);
				break;			
		case 7:printf("enter the position where you want to DELETE the value");
				scanf("%d",&pos);
				deleteat(pos);
				printf("THE ELEMENTS OF THE LIST NOW ARE : ");display(start);
				break;
		case 8: printf("ENter the value is to be Deleted ");
		       	scanf("%d",&pos);	
        	 	deleteval(pos);
			   	printf("THE ELEMENTS OF THE LIST NOW ARE : ");display(start);
				break;
		case 9:	cpy=copy(start);
				printf("THE copied list is\n");
				printf("THE LIST  : ");display(cpy);
				break;				
		case 10:a=count(start);
				printf("THE NO OF ELEMENTS IN THE LIST ARE %d",a);
				break;	
		case 11:sort();
				printf("THE SORTED ELEMENTS ARE\n");	
				printf("THE LIST  : ");display(start);   
				break;	
		case 12:a=bintodec(start);
				printf("\nThe Decimal Equivalent is: %d\n",a);
				break;
		case 13:start=reverseno(start);
				printf("THE LIST  : ");display(start);
				break;	
		case 14:reverselist=freelist(reverselist);
				reverselist=reverse(start);
				printf("THE reversed list is : ");
				display(reverselist);
				break;
		case 15:printf("\nTHE ORIGINAL LIST : ");display(start);
			    printf("\nTHE REVERSE LIST : ");display(reverselist);
			    printf("\nTHE FRONT PART : ");display(part1);
			    printf("\nTHE REAR PART : ");display(part2);
			    printf("\nTHE COPIED LIST : ");display(cpy);
			    break;
		case 16:random();
				display(start);
				break;									
		case 17:start=freelist(start);
				cpy=freelist(cpy);
				ptr=freelist(ptr);
				part1=freelist(part1);
				part2=freelist(part2);
				temp=freelist(temp);
				reverselist=freelist(reverselist);
				exit(0);
			   	
	}
   }

}	
