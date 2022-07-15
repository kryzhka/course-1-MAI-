#include <stdio.h>

int paw(int step)
{
	int chislo=1;
	while(step>0)
	{
		chislo*=2;
		--step;
	}
	return chislo;
}
int main()
{
	char c=' ';
	int answer=0,counter=0,number=0;
	while((c=getchar())!=EOF)
	{
		if(c=='1')
		{
			counter+=1;
			if(counter%4==0)
				number+=paw(0);
			else
				number+=paw(4-counter%4);
		}
		else if(c=='0')
		{
			counter+=1;
		}
		else
		{
			if(counter%4==0&&counter!=0)
			{
				answer+=1;
			}
			counter=0;
			number=0;
		}
		if(number>9)
		{
			number=0;
			counter=0;
		}
		if(counter%4==0&&counter!=0)
		{
			number=0;
		}
	}
	if(counter%4==0&&counter!=0)
		answer+=1;
	printf("Количество полнотетрадных двоичнокодированных десятичных чисел: %d\n",answer);
}