#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

int isSort=0;
struct Key
{
    int real;
    int imaginary;
} key;

struct Row
{
    Key key;
    char *value = new char[100];
};

int countOfString(FILE *file)
{
    int count = 0;
    char c = '0';
    while (!feof(file))
    {
        if (c == '\n')
            ++count;
        fscanf(file, "%c", &c);
    }
    rewind(file);
    return count;
}

Row *makeTable(FILE *file, int size)
{
    Row *table = new Row[size];

    for (int i = 0; i < size; ++i)
    {
        fscanf(file, "%d %d", &table[i].key.real, &table[i].key.imaginary);
        fgets(table[i].value,100,file);
    }
    return table;
}

void printTable(Row *table, int size)
{
    printf("___________________________________________________________________\n");
    for (int i = 0; i < size; ++i)
    {
        printf(" %4d %4di | %s \n", table[i].key.real, table[i].key.imaginary, table[i].value);
    }
}

void swapString(Row *table, int a, int b)
{
    Row tpm = table[a];
    table[a] = table[b];
    table[b] = tpm;
}

int compareKey(Key a, Key b)
{
    if (a.real * a.real - a.imaginary * a.imaginary > b.real * b.real - b.imaginary * b.imaginary)
        return 1;
    else if(a.real * a.real - a.imaginary * a.imaginary == b.real * b.real - b.imaginary * b.imaginary)
        return 0;
    else 
        return -1;
}

void bubbleSort(Row *table, int size)
{
    isSort=1;
    for (int r = 1; r < size; ++r)
    {
        for (int i = 0; i < size - r; ++i)
        {
            if (compareKey(table[i].key, table[i + 1].key)==1)
            {
                swapString(table, i, i + 1);
            }
        }
    }
}
void reverseTable(Row *table, int size)
{
    Row tmp;
    for (int i = 0; i < size/2; ++i)
    {
        tmp = table[i];
        table[i]=table[size-i-1];
        table[size-i-1]=tmp;
    }
    isSort=0;
}
void mixTable(Row *table, int size)
{
    int a,b;
    for(int i =0; i< size;++i)
    {
        a=rand()%size;
        b=rand()%size;
        swapString(table,a,b);
    }
    isSort=0;
}

void randomize()
{
    int a = time(0);
    srand(a);
}

int binarySearch(Row *table, int size, Key key)
{
    int i=0, mid, end = size-1;
    while(i<=end)
    {
        mid=(i+end)/2;        
        if(compareKey(key,table[mid].key)==0)
        {
            return mid;
        }
        else if(compareKey(key,table[mid].key)==-1)
        {
            end = mid;
        }
        else if(compareKey(key,table[mid].key)==1)
        {
            i=mid+1;
        }
    }
    return -1;
}
int main(int argc, char *argv[])// i need a binary search 
{
    randomize();
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile)
    {
        printf("Can't open file\n");
        return 0;
    }
    int size = countOfString(inputFile);
    Row *table = makeTable(inputFile, size);
    printTable(table,size);
    int choise;
    while(1)
    {
        printf("Menu\n");
        printf("1)Print table\n");
        printf("2)Buble sort\n");
        printf("3)Binary search\n");
        printf("4)Mix table\n");
        printf("5)Revers table\n");
        printf("0)Exit\n");
        printf("Please choose an action:");
        scanf("%d",&choise);
        switch (choise)
        {
        case 1:
        {
            printTable(table,size);
            break;
        }
        case 2:
            bubbleSort(table, size);
            break;
        case 3:
        {
            if(isSort==1)
            {
                printf("Please enter the real and imagine value of key:");
                int real;
                scanf("%d",&real);
                int imagine;
                scanf("%d",&imagine);
                key.real = real;
                key.imaginary = imagine;
                int search = binarySearch(table,size,key);
                if(search==-1)
                {
                    printf("This element is not found\n");
                    break;
                }
                printf("Found the string:\n %s\n",table[search].value);
            }
            else
                printf("Table isn't sorted\n");
            break;
        }
        case 4:
        {
            mixTable(table,size);
            break;
        }
        case 5:
        {
            reverseTable(table,size);
            break;
        }
        case 0:
            return 0;
        }
    }
    return 0;
}