#include "stdio.h" 
#ifndef QUEUEd_H  
#define QUEUEd_H
#define N 100
#define TypeValue int
struct element{
    element *next;
    TypeValue value;
};

struct queue{
    element *start;
    element *end;
    int size;
};

void Init(queue &q)
{
    q.start=0;
    q.end=0;
    q.size=0;
}

int Empty(queue &q)
{
    return q.start==0;
}

void Push(queue &q, TypeValue value)
{
    if(q.size==N)
    {
        printf("Queue is overflow!\n");
        return;
    }
    else if(Empty(q))
    {
        q.end = new element;
        q.end->value = value;
        q.start=q.end;
    }
    else
    {
        element *tpr = new element;
        q.end->next=tpr;
        tpr->value=value;
        q.end = tpr;
        q.end->next=0;
    }
    q.size++;
}

TypeValue Pop(queue &q)
{
    if(Empty(q))
        printf("Queue is empty\n");
    else{
        TypeValue value = q.start->value;
        element *s=q.start;
        q.start=q.start->next;
        delete s;
        q.size--;
        return value;
    }
    return 0;
}

TypeValue Top(queue &q)
{
    if(Empty(q))
        printf("Queue is empty\n");
    else 
    {
        return q.start->value;
    }
    return 0;
}

int Size(queue &q)
{
    return q.size;
}
void Display(queue q)
{
    if(Empty(q))
        printf("Queue is empty\n");
    else
    {
        element *i=q.start;
        printf("[");
        while(i)
        {
            printf("%d ",i->value);
            i=i->next;
        }
        printf("]\n");
    }
}

queue merge(queue &q1, queue &q2)
{
    queue q;
    Init(q);
    while(!Empty(q1)&&!Empty(q2))
    {
        if(Top(q1)<Top(q2))
        {
            Push(q,Pop(q1));
        }
        else
        {
            Push(q,Pop(q2));
        }
    }
    while(!Empty(q1))
    {
        Push(q,Pop(q1));
    }
    while(!Empty(q2))
    {
        Push(q,Pop(q2));
    }
    return q;
}
#endif
