#include <stdio.h>
#include <stdlib.h>

int modul(int number)
{
	if (number < 0)
		return -number;
	return number;
}

int main(int argc, char *argv[])
{
	//finding n and m and count of not null values
	int parametr = 4;
	FILE *fin;
	fin = fopen(argv[1], "r");
	char value;
	int n = 0, m = 1;
	while (1)
	{
		fscanf(fin, "%c", &value);
		if (feof(fin))
			break;
		if ((n == 0) && (value == ' '))
		{
			m += 1;
		}
		if (value == '\n')
		{
			n += 1;
		}
	}//writing matrix to massive
	int **matrix = new int*[n];
	for (int i = 0; i <= n; ++i)
	{
		matrix[i] = new int[m];
	}
	fin = fopen(argv[1], "r");
	int count_nozero = 0, i_value;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			fscanf(fin, "%d", &i_value);
			if (i_value != 0)
				count_nozero += 1;
			matrix[i][j] = i_value;
		}
	}
	printf("n=%d m=%d count_nozero=%d\n", n, m, count_nozero);
	//full to mini
	int *cip = new int[n];
	int *pi = new int[count_nozero];
	int *ye = new int[count_nozero];
	int k = 0, zero;
	for (int i = 0; i < n; ++i)
	{
		cip[i] = k + 1;
		zero = 0;
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] != 0)
			{
				ye[k] = matrix[i][j];
				pi[k] = j + 1;
				k += 1;
				zero += 1;
			}
		}
		if (zero == 0)
			cip[i] = 0;
	}
	//preobrazovanie
	int min_diff;
	min_diff = modul(parametr - ye[0]);
	for (int i = 0; i < count_nozero; ++i)
	{
		if (modul(parametr - ye[i]) < min_diff)
			min_diff = modul(parametr - ye[i]);
	}

	printf("%d\n", min_diff);
	int d;
	for (int k = 0; k < count_nozero; ++k)
	{
		if (modul(parametr - ye[k]) == min_diff)
		{
			d=ye[k];
			for (int j = 0; j < count_nozero; ++j )
			{
				if (pi[j] == pi[k])
				{
					ye[j] = ye[j] / d;
					printf("%d %d %d %d\n",ye[j],pi[j],j,ye[k]);
				}
			}

			for (int i = 0; i < n - 1; ++i)// dont work(
			{
				if ((cip[i] < k) && (cip[i + 1] > k))
				{
					for (int t = cip[i]; t < cip[i + 1]; ++t)
					{
						ye[t] = ye[t] / d;
					}
				}
			}
		}
	}

//mini to full
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	int p, l;
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
			p = count_nozero + 1;
		else
			p = cip[i + 1];
		if (p == 0)
		{
			p = cip[i + 2];
		}
		l = cip[i];
		if (l != 0)
		{
			for (int j = l - 1; j < p - 1; ++j)
			{
				matrix[i][pi[j] - 1] = ye[j];
			}
		}
	}



//PRINTING
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", cip[i]);
	}
	printf("\n");
	for (int i = 0; i < count_nozero; ++i)
	{
		printf("%d ", pi[i]);
	}
	printf("\n");
	for (int i = 0; i < count_nozero; ++i)
	{
		printf("%d ", ye[i]);
	}
	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	delete[] cip;
	delete[] pi;
	delete[] ye;
	delete[] matrix;
	return 0;
}
printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣀⣀⣀⠄⠄⠄⠄⡀⠄⠄⡀⠠⣤⣄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠈⠉⢉⡏⠄⠄⠄⢸⡇⠄⣼⠇⠄⢀⡏⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⣸⣧⡤⣤⡀⠈⠓⠚⣿⠄⠄⣸⠳⠶⢶⡀⠄⠄\n");
	printf("⠄⠄⠄⠄⣀⡀⠄⠄⠄⠄⠄⠄⣿⠁⠄⣸⡇⣀⣠⡴⠟⠄⠄⣿⣀⣀⣼⠇⠄⠄\n");
	printf("⠄⣠⣶⣿⣿⣿⣿⠆⠄⠄⠄⠄⠻⠦⠶⠋⠄⠉⠄⠄⠄⠄⠄⠉⠉⠉⠁⠄⠄⠄\n");
	printf("⢰⣿⣿⡿⠛⠉⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⢸⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⠄⠄⢀⣀⣠⣤⣀⣀⠄⠄⠄⠄⢀⣀⣀⣀⡀⠄⠄\n");
	printf("⠄⢿⣿⣧⠄⠄⠄⠄⠄⠄⢀⣴⣿⣿⣿⣿⣿⣿⣿⣷⣄⠄⣼⣿⣿⣿⣿⣿⣦⠄\n");
	printf("⠄⠘⣿⣿⣧⡀⠄⠄⠄⢠⣾⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⡀⠹⠿⠛⠉⢹⣿⣿⡄\n");
	printf("⠄⠄⠈⢿⣿⣿⣄⠄⢠⣿⣿⣿⣇⣍⢹⣿⣯⣰⣼⣿⡿⠁⠄⠄⠄⢀⣾⣿⣿⠃\n");
	printf("⠄⠄⠄⠈⢿⣿⣿⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠁⠄⠄⢀⣴⣾⣿⡿⠃⠄\n");
	printf("⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣤⣶⣿⣿⣿⠟⠋⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠉⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⣿⠋⠉⠉⠉⠘⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⡏⠄⠄⠄⠄⠄⢹⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⡇⠄⠄⠄⠄⠄⠸⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⣿⣿⣿⣷⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⣿⣿⣿⡇⠄⠄⠄⠄⠄⠄⠄⢸⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⢰⣿⣿⣿⣄⠄⠄⠄⠄⠄⠄⠄⠈⣿⣿⣿⣿⣶⡄⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠈⠻⣿⣿⡟⠄⠄⠄⠄⠄⠄⠄⠄⢿⣿⣿⣿⠿⠃⠄⠄⠄⠄⠄⠄\n");
	printf("⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄\n");