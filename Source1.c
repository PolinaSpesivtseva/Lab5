#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

void form(int M[20][10], int* m, int* n)//������� �������, ��� ��������� ������
{
	printf("enter m from 2 to 20: ");//������ ���������� ����� (m)
	scanf("%d", m);
	printf("enter n from 1 to 10: ");
	scanf("%d", n); // ������ ���������� �������� (n)

	for (int i = 0; i < *m; i++) { // ������ ���� �������� ������� 
		for (int j = 0; j < *n; j++) {
			printf("M[%d][%d] = ", i, j);
			scanf("%d", &M[i][j]);
		}
	}
}

void vivod(int M[20][10], int m, int n) //������� ������ ������� �� �����
{

	for (int i = 0; i < m; i++) // ������� ������ �� �����
	{
		for (int j = 0; j < n; j++) {
			printf("%5d ", M[i][j]);
		}
		printf("\n");
	}

}


int max(int M[20][10], int m, int n) //�������, ��� �� ������� ������������ ���������� �������� ���������
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

double srar(int M[20][10], int m, int n, int maximum) //�������, ��� ������� ������� ������������� 
{
	int i, j, kol, nom, f;
	f = 0; //����������, ������� ����� ����������, �������� �� ���� �� 1 �������� �������
	nom = 0;
	double sr, sum;

	for (i = 0; i < m; i++) //���������, �������� �� ���� �� 1 �������� ������� 
		for (j = 0; j < n; j++)
		{
			if (M[i][j] % 2 != 0) f = 1;
		}
	if (f == 0) return(0); //���� ���, �� ������� �������������� ����� ����� 0
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

			if (kol == maximum) //���� ����� ���������� �������� ���������, ����������� � ������������, �� ���� ����� ���� ���������
			{
				nom++;
				for (i = 0; i < m; i++)
				{
					sum = sum + M[i][j];
				}
			}
		}
		sr = sum / (m * nom); //������� ������� �������������� 
		return(sr);
	}
}

int main()
{
	printf("LAB WORK#5\nSpesivtseva Polina\n");
	int M[20][10];
	int m, n, maximum;
	double average;
	form(&M, &m, &n); //���� �������
	vivod(&M, m, n); // ����� �������
	maximum = max(&M, m, n);//������� ������������� ���������� �������� ��������� 
	average = srar(&M, m, n, maximum); //������� �������� ���������������
	printf("average = %lf", average);
	return 0;
}


