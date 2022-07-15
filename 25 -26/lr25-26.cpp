//Очередь слияние двух очередей упорядоченных по вощрастанию, с сохранением порядка сортировка слиянием
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include "queued.h"

queue mergeSort(queue &q)
{
    if(Empty(q)||Size(q)==1)
    {
        return q;
    }
    queue s ,f;
    int size = Size(q),i=1;
    Init(s); Init(f);
    while(!Empty(q))
    {
        if(i<=size/2)
        {
            Push(s,Pop(q));
            ++i;
        }
        else
            Push(f,Pop(q));
    }
    queue q1 = mergeSort(s);
    queue q2 = mergeSort(f);
    return merge(q1,q2);
}

int main()
{
    srand(time(0));
    queue q;
    Init(q);
    int in;
    while(1)
    {
        printf("Menu:\n");
        printf("1)Random queue\n");
        printf("2)Print queue\n");
        printf("3)Push value\n");
        printf("4)Pop value\n");
        printf("5)Sort queue\n");
        printf("0)Exit\n");
        scanf("%d",&in);
        switch(in){
            case 0:
            {
                return 0;
            }
            case 1:
            {
                printf("Please enter a size of queue:");
                scanf("%d",&in);
                while(in)
                {
                    Push(q,rand()%100);
                    in--;
                }
                break;
            }
            case 2:
            {
                Display(q);
                break;
            }
            case 3:
            {
                printf("Please enter a value:");
                scanf("%d",&in);
                Push(q,in);
                break;
            }
            case 4:
            {
                printf("%d\n",Pop(q));
                break;
            }
            case 5:
            {
                q=mergeSort(q);
                break;
            }

        }
    }
    
}