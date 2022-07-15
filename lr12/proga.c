#include <stdio.h>
int main()
{
	int number,copy,new_number=0,mnozhitel=1;
	scanf("%d",&number);
	copy=number;
	while(copy>0)
	{
		if(copy%2==0)
		{
			new_number+=(copy%10+1)*mnozhitel;
		}
		else
		{
			new_number+=(copy%10-1)*mnozhitel;
		}
		copy/=10;
		mnozhitel*=10;
		//printf("%d%s%d%s%d\n",new_number," ",copy," ",mnozhitel); Отладочная запись

	}
	printf("%d",new_number);
}