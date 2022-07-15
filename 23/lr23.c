
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef char tdata;
int i,r,q;
tdata m;

struct node ;

typedef node * link;

struct node 
{
    tdata data;
    link son;
    link brother;
};
void printtree(link t)
{
    static int l=0;
    if(t)
    {
        l++;
        printtree(t->brother);
        for(i=0;i<l;i++)
            printf("   ");
        printf("\\__%c\n",t->data);
        printtree(t->son);
        l--;
     }
}

link search(link tree, tdata c)
{
    if(tree)
    {
        if(tree->data==c)
            return tree;
        link t=search(tree->son,c);
        if(!t)
            t=search(tree->brother,c);
        return t;
    }
    return 0;
}

link searchfather(link tree, tdata c)
{
    link t;
    if(tree)
    {
        if(tree->son&&tree->son->data==c)
            return tree;
        t=tree->son; 
        while(t)
        {
            if(t->brother&&t->brother->data==c)
            return tree; 
            t=t->brother;
        }
        t=0;
        t=searchfather(tree->son,c); 
        if(!t)
            t=searchfather(tree->brother,c);
        return t;
    }
    return 0;
}


link searchbrother(link tree, tdata c)
{
    if(tree)
    {
        if(tree->brother&&tree->brother->data==c)
            return tree;
        link t=searchbrother(tree->brother,c);
        if(!t)
            t=searchbrother(tree->son,c);
        return t;
    }
    return 0;
}

void insertbrother(link &t,tdata v)
{
    if(!t)
    {
        t=new node;
        t->data=v;
	    t->son=0;
        t->brother=0;
	}
    else
        insertbrother(t->brother,v);
} 

void insertson(link &t,tdata v)
{
    if(!(t->son))
    {
        t->son=new node ;
        t->son->data=v;
	    t->son->son=0;
        t->son->brother=0;
	}
    else
        insertbrother(t->son,v);
}

void inserttree(link &t,tdata v)
{
    if(!t)
    {
        t=new node;
        t->data=v;
	    t->son=0; t->brother=0;
	}
    else
    {
        r=rand()%2;
	    if(r)
            inserttree(t->son,v);
	    else
            inserttree(t->brother,v);
	}
}

void action(link tree)
{
    link t=tree;
    while(t)
    {
        if(t->brother!=0)
            {
                printf("Tree is not a linel list\n");
                return;
            }
        t=t->son;        
    }
    printf("Tree is a linel list\n");
}

void mix(tdata *m, int n)
{
    int r; tdata s; 
    for(i=0;i<n;i++)
    {
        r=rand()%n;
        s=m[i];
        m[i]=m[r];
        m[r]=s;
    }
} 

int main()
{
    long a;
    srand(time(&a)); 
    int k=7,n;
    tdata *m, f, s;
    link tree=0,t;
    while(k)
    {
        if(k==7)
        {
            printf("Input from 0 to 7 actions:\n"
            "0 - Exit\n"
            "1 - Add random tree\n"
            "2 - Print tree\n"
            "3 - Insert item\n"
            "4 - Delete item\n"
            "5 - Delete tree\n"
            "6 - Main action\n"
            "7 - Print menu\n"
            );
        }
        else if(k==1)
        {
            printf("please enter a numper of nodes\n");
            scanf("%d",&n);
            m = new tdata[n];
            for(int i=0;i<n;++i)
            {
                m[i]=100+i;
            }
            mix(m,n);
            for(int i = 0; i<n;++i)
            {
                inserttree(tree,m[i]);
            }
        }
        else if(k==2)
        {
            if(!tree)
                printf("Tree is empty\n");
            else
                printtree(tree);


        }
        else if(k==3)
        {
            printf("\nInput value of root ==>");
            scanf(" %c",&f);
	        t=new node ;
            t->data=f;
	        t->son=0;
            t->brother=0;
	        if(!tree)
                tree=t;
	        else
            {
                t->son=tree;
                tree=t; 
            }
        }
        else if(k==4)
        {
            printf("\nInput value of node ==>");
            scanf(" %c",&f);
	        if(tree->data==f)
                if(tree->brother==0)
                {
                    tree=0;
                    continue;
                }
			    else
                    tree=tree->brother;
	        else
            {
                t=searchbrother(tree,f);
		        if(t)
                    t->brother=t->brother->brother;
		        else
                {
                    t=searchfather(tree,f);
			        if(t)
                        if(t->son->brother)
                            t->son=t->son->brother;
				        else t->son=0;
			        else printf("\nNode not found\n");
			    }
		    }
        }
        else if(k==5)
        {
            tree=0;
        }
        else if(k==6)
        {
            action(tree);
        }
        printf("Input from 0 to 7 actions:\n");
        scanf("%d",&k);


    }
    return 0;
}


