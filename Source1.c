#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void form(int M[20][10], int* m, int* n)//создаем функцию, где формируем массив
{
	printf("enter m from 2 to 20: ");//вводим количество строк (m)
	scanf("%d", m);
	printf("enter n from 1 to 10: ");
	scanf("%d", n); // вводим количество столбцов (n)

	for (int i = 0; i < *m; i++) { // вводим сами элементы массива 
		for (int j = 0; j < *n; j++) {
			printf("M[%d][%d] = ", i, j);
			scanf("%d", &M[i][j]);
		}
	}
}

void vivod(int M[20][10], int m, int n) //функция вывода массива на экран
{

	for (int i = 0; i < m; i++) // выводим массив на экран
	{
		for (int j = 0; j < n; j++) {
			printf("%5d ", M[i][j]);
		}
		printf("\n");
	}

}


int max(int M[20][10], int m, int n) //функция, где мы находим максимальное количество нечетных элементов
{
	int i, j, maxim, kol;
	maxim = -1;
	for (j = 0; j < n; j++)

	{
		kol = 0;
		for (i = 0; i < m; i++)
		{
			if (M[i][j] % 2 != 0)
			{
				kol++;
			}
		}
		if (kol > maxim)
		{
			maxim = kol;
		}
	}
	return(maxim);
}

double srar(int M[20][10], int m, int n, int maximum) //функция, где находим среднее ариметическое 
{
	int i, j, kol, nom, f;
	f = 0; //переменная, которая будет показывать, найдется ли хотя бы 1 нечетный элемент
	nom = 0;
	double sr, sum;

	for (i = 0; i < m; i++) //проверяем, найдется ли хотя бы 1 нечетный элемент 
		for (j = 0; j < n; j++)
		{
			if (M[i][j] % 2 != 0) f = 1;
		}
	if (f == 0) return(0); //если нет, то среднее арифметическое сразу равно 0
	else
	{
		sum = 0;
		for (j = 0; j < n; j++)
		{
			kol = 0;
			for (i = 0; i < m; i++)
			{
				if (M[i][j] % 2 != 0)
				{
					kol++;
				}
			}

			if (kol == maximum) //если нашли количество нечетных элементов, совпадающих с максимальным, то ищем сумму всех элементов
			{
				nom++;
				for (i = 0; i < m; i++)
				{
					sum = sum + M[i][j];
				}
			}
		}
		sr = sum / (m * nom); //считаем среднее арифметическое 
		return(sr);
	}
}

int main()
{
	printf("LAB WORK#5\nSpesivtseva Polina\n");
	int M[20][10];
	int m, n, maximum;
	double average;
	form(&M, &m, &n); //ввод массива
	vivod(&M, m, n); // вывод массива
	maximum = max(&M, m, n);//подсчет максимального количества нечетных элементов 
	average = srar(&M, m, n, maximum); //подсчет среднего арифметического
	printf("average = %lf", average);
	return 0;
}


