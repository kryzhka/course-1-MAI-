#include <stdio.h>
#include "Set.h"
#define maxSizeOfWord 256
#define N 26

void CleenSet(char S[])
{ char c; int i;
  for(i=0;i<N;i++)S[i]=S[N+i]=0;
}

int main()
{	char Word[maxSizeOfWord],Word_with_max_repetition[maxSizeOfWord];
	char Repetition_Leters[N*2];
	char Used_Letters[N*2];
	char Letter_Set[N*2];
	int countOfrepetition=0,maxCountOfrepetition=0;
	int final=0;
	char c;
	int r=0;
	CleenSet(Used_Letters);
	CleenSet(Repetition_Leters);
	while(c!=EOF)
	{
		c=getchar();
		if(!Letter(c))
		{

			for(char i='a';i<='z';++i)
			{
				CleenSet(Letter_Set);
				InSet(i,Letter_Set);
				IntersSet(Repetition_Leters,Letter_Set,Letter_Set);
				if(!EmptySet(Letter_Set))
				countOfrepetition+=1;
			}
		
			if(countOfrepetition>0)
			{
				final+=1;
				if(maxCountOfrepetition<=countOfrepetition)
				{
					maxCountOfrepetition=countOfrepetition;
					for(int i=0;i<maxSizeOfWord;++i)
					{
						Word_with_max_repetition[i]=Word[i];
						Word[i]=0;
					}
				}
			}
			countOfrepetition=0;
			CleenSet(Used_Letters);
			CleenSet(Repetition_Leters);
			r=0;
			continue;
		
		}	
		Word[r]=c;
		if(c>='A'&&c<='Z')
			c=c-('A'-'a');
		CleenSet(Letter_Set);
		InSet(c,Letter_Set);
		IntersSet(Used_Letters,Letter_Set,Letter_Set);
		if(!EmptySet(Letter_Set))
		{
			InSet(c,Repetition_Leters);
			countOfrepetition+=1;
		}
		InSet(c,Used_Letters);
		++r;
	}
	printf("Максимальное количество повторений в одном слове %d\n",maxCountOfrepetition);
	printf("Слово с максимальным количеством повторений: %s\n",Word_with_max_repetition);
	printf("Всего слов с повторениями: %d\n",final);
}