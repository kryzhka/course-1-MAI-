#include <stdio.h> 
#ifndef QUEUEM_H
#define QUEUEM_H 

#define N 100
#define TypeValue int

struct queue
{
    int start, end, size;
    TypeValue value[N];
};

void Init(queue &q)
{
    q.start=q.size=0;
    q.end=-1;
}

int Empty(queue &q)
{
    return q.size==0;
}

void Push(queue &q, TypeValue v)
{
    if(q.size==N)
        printf("queue is overflow");
    else
        {
            q.value[++q.end%=N]=v;
            q.size++;
        }
    
}

TypeValue Pop(queue &q)
{
    if(Empty(q))
        printf("queue is empty\n");
    else
    {
        q.size--;
        int i = q.start++;
        q.start%=N;
        return q.value[i];
    }
    return 0;
}

TypeValue Top(queue &q)
{
    if(Empty(q))
        printf("queue is empty\n");
    else
        return q.value[q.start];
    return 0;
}

int Size(queue &q)
{
    return q.size;
}

void Display(queue q)
{
    printf("[");
    for(int i=q.start;i<q.start+q.size;i++)
        printf("%d ",q.value[i%N]);
    printf("]\n");
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
