#include <stdio.h>
#include "head.h"
#define _CRT_SECURE_NO_WARNINGS

// �ڷγ� Ȯ���� ����, ���ɺ� ��Ȳ ������ Ȯ���ϴ� ���α׷�

struct people {
	float infp; //Ȯ����
	float deap; //�����
	float fatp; //ġ����
};
//����ü

int main(void)
{

	//���� ����
	char age[40];
	FILE *fp;
	//���� �����
	char *s;
	//������

	struct people p;

	//��ó-�ڷγ� ���� Ȩ������
	int age_len[9];

	age_len[0] = 0;
	age_len[1] = 10;
	age_len[2] = 20;
	age_len[3] = 30;
	age_len[4] = 40;
	age_len[5] = 50;
	age_len[6] = 60;
	age_len[7] = 70;
	age_len[8] = 80;
	
	//�迭

	printf("�ڷγ� Ȯ���� ���ɺ� ��Ȳ(6.8 00�� ����, ���� : ��)\n1. 0~9��\n");
	for (int i = 1; i < 8; i++)
	{
		printf("%d. %d��\n", i+1, age_len[i]);
	}
	printf("9. %d�� �̻�\n", age_len[8]);
	printf("Ȯ���� ���ɴ��� ��ȣ�� �Է��ϼ���:  ");
	gets_s(age, 40);

	fopen_s(&fp, age, "r");

	if (fp == NULL)
	{
		printf("�����߻�");
		return 1;
	}
	while (1)
	{
		s = fgets(age, sizeof(age), fp);
		if (s == NULL)
		{
			break;
		}
	}
	fclose(fp);
	printf("[Ȯ���� �� / ����� ��]\n");
	printf("[%s]\n", age);

	//ġ���� ���
	float inf;
	float dea;
	int aa;
	printf("1. ġ������ ���\n2. �����ϱ�\n��ȣ�� �Է��ϼ���:  ");
	scanf_s("%d", &aa, sizeof(aa));

	if (aa == 1)
	{
		printf("Ȯ������ ���� �Է��ϼ��� :  ");
		scanf_s("%d", &inf, sizeof(inf));
		printf("������� ���� �Է��ϼ��� :  ");
		scanf_s("%d", &dea, sizeof(dea));
		printf("ġ���� : %.6f%%\n\n", fatality(inf, dea));
		//�Լ� ���, ���߼ҽ� ����

		p.infp = inf;
		p.deap = dea;
		p.fatp = fatality(inf, dea);
		printf("Ȯ���ڴ� %d��, ����ڴ� %d��, ġ������ %.6f%%�Դϴ�.\n\n", p.infp, p.deap, p.fatp);
	}
	else if (aa == 2)
	{
		return 0;
	}

	int a1;
	printf("������ ���� Ȯ���� ������ Ȯ���Ͻðڽ��ϱ�?\n");
	printf("1. ��\n2. �ƴϿ�\n");
	scanf_s("%d", &a1, sizeof(a1));

	//�� Ȯ����, ����� : 8,549,227 , 11,831  
	//�� Ȯ����, ����� : 9,638,973 , 12,474 
	int n1=8549227, n2=11831, n3=9638973, n4=12474;
	int *ID[4] = { &n1, &n2, &n3, &n4 };
	//������ Ȱ��

	if (a1 == 1)
	{
		int a2;
		printf("\n1. ����\n2. ����\n\n������ Ȯ���� ������ ������. :  \n");
		scanf_s("%d", &a2, sizeof(a2));
		if (a2 == 1)
		{
			printf("Ȯ���ڴ� %d��, ����ڴ� %d��, ġ������ %.6f%%�Դϴ�.\n", *ID[0], *ID[1], fatality(n1, n2));
			return 0;
		}
		else if (a2 == 2)
		{
			printf("Ȯ���ڴ� %d��, ����ڴ� %d��, ġ������ %.6f%%�Դϴ�.\n", *ID[2], *ID[3], fatality(n3, n4));
			return 0;
		}
	}
	else if (a1 == 2)
	{
		return 0;
	}

	return 0;
}