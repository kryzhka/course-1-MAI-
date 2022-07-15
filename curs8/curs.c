
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct ls;
typedef ls * link;
typedef enum{Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec,UNK} item;
char month[12][4]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug", "Sep","Oct","Nov","Dec"};
                
struct ls
{
	item body;
	link next;	
} *list, *young, *old, *jump, *f; 
item element;
void kryzhkas_random()
{
	long a = time(0);
	srand(a);
}

void addlast(item i)
{
    if(!list)
    {
        old = new ls;
        list = new ls;
        list->body=i;
        list->next=NULL;
        old=list;
    }
    else
    {
       	young=new ls;
       	young->body=i;
       	young->next=NULL;
        old->next=young;
        old=young;
    }
}
void addfirst(item i)
{
    if(!list)
    {
        list = new ls;
        list->body=i;
        list->next=NULL;
    }
    else
    {
       	young = new ls;
        young->next=list->next;
        list->next=young;
        young->body=list->body;
        list->body=i;
    }
    //printf("%s\n",month[i]);
}

void generate_list(int number)
{
    for(int i=0;i<number;++i)
    {
        element=item(rand()%12);
        addlast(element);
        // printf("%s\n",month[element]);
    }
}

void printlist()
{
    if(!list)
        printf("List is empty\n");
    else
    {
        jump=list;
        while(jump)
        {
           printf("%s\n",month[jump->body]);
           jump=jump->next;
        }   
    }
    
}

item read_val()
{
    char b[4];
    scanf("%s",b);
    for(int i=0;i<12;i++)
        if(!strcmp(b,month[i]))
            return item(i);
    return UNK;
}

void deleting(item m)
{ 
    if(list->body==m)
    {
        if(list->next==list)
            list=NULL;
        else
        {
            list=list->next;
        }
    }
    else
    { 
        jump=list;
        int c=0;
        do
        {
            if(jump->next->body==m)
                {
                    f=jump->next;
                    jump->next=f->next;
                    delete f;
                    c=1;
                    break;
                } 
            jump=jump->next;
        }while(jump->next);
        if(!c)
            printf("\nItem with this value not exists!\n");
        }
}

void insert(item m, item m1)
{
    jump=list;
    int c=0;
    do
    {
        if(jump->body==m)
        {
            young=new ls;
            young->body=m1;
            young->next=jump->next;
            jump->next=young;
            c=1;
            break; 
       } 
       jump=jump->next;
    }while(jump);
    if(!c)
        printf("\nItem with this value not exists!\n");
} 

void action(int k)
{
    int r=1;
    jump=list;
    while(jump->next)
    {
        if(r==k)
        {
            element=old->body;
            old->body=jump->next->body;
            jump->next->body=element;
            break;
        }
        else
        {
            ++r;
            old=jump;
            jump=jump->next;
            
        }
    }
}

int main()
{
    kryzhkas_random();
    int k=8,c;
    item n,m;
    while(k)
    {
        if(k==8)
        printf("Input from 0 to 10 actions:\n"
        "1.Generate list\n"
        "2.Add a new element to end of list\n"
        "3.Add a new element to begin of list\n"
        "4.Delete element from the list\n"
        "5.Inser element in list\n"
        "6.Print list\n"
        "7.Erase list\n"
        "8.Print this menu\n"
        "9.Main action\n"
        "0.Exit from the program\n\n"
        );
        
        else if(k==0)
            return 0;
        else if(k==1)
        {
            printf("Please enter lenth of list\n");
            scanf("%d",&c);
            generate_list(c);
        }
        else if(k==2)
        {
            printf("Please enter a new element\n");
            addlast(read_val());
        }
        else if(k==3)
        {
            printf("Please enter a new element\n");
            addfirst(read_val());
        }
        else if(k==4)
        {
            printf("Please enter value of deleting item\n");
            deleting(read_val());
        }
        else if(k==5)
        {
            printf("Please enter inserting item\n");
            m=read_val();
            printf("Please enter value item after which to insert\n");
            n=read_val();
            insert(n,m);
        }
        else if(k==6)
            printlist();
        else if(k==7)
        {
            jump=list;
            if(jump)
            do
            {
                young=jump;
                jump=jump->next;
                delete young;
            }while(jump!=list);
            list=0;
        }
        else if(k==9)
        {
            if(!list)
                {
                    printf("list is empty\n");
                    continue;
                }
            printf("Please enter k\n");
            scanf("%d",&c);
            action(c);
        }
        printf("Please choose action(8 for menu)\n");
        scanf("%d",&k);
    }
	return 0;
}