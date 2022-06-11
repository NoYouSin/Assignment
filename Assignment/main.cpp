#include <stdio.h>
#include "head.h"
#define _CRT_SECURE_NO_WARNINGS

// 코로나 확진자 성별, 연령별 현황 정보를 확인하는 프로그램

struct people {
	float infp; //확진자
	float deap; //사망자
	float fatp; //치사율
};
//구조체

int main(void)
{

	//정보 열람
	char age[40];
	FILE *fp;
	//파일 입출력
	char *s;
	//포인터

	struct people p;

	//출처-코로나 공식 홈페이지
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
	
	//배열

	printf("코로나 확진자 연령별 현황(6.8 00시 기준, 단위 : 명)\n1. 0~9살\n");
	for (int i = 1; i < 8; i++)
	{
		printf("%d. %d대\n", i+1, age_len[i]);
	}
	printf("9. %d대 이상\n", age_len[8]);
	printf("확인할 연령대의 번호를 입력하세요:  ");
	gets_s(age, 40);

	fopen_s(&fp, age, "r");

	if (fp == NULL)
	{
		printf("오류발생");
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
	printf("[확진자 수 / 사망자 수]\n");
	printf("[%s]\n", age);

	//치사율 계산
	float inf;
	float dea;
	int aa;
	printf("1. 치사율을 계산\n2. 종료하기\n번호를 입력하세요:  ");
	scanf_s("%d", &aa, sizeof(aa));

	if (aa == 1)
	{
		printf("확진자의 수를 입력하세요 :  ");
		scanf_s("%d", &inf, sizeof(inf));
		printf("사망자의 수를 입력하세요 :  ");
		scanf_s("%d", &dea, sizeof(dea));
		printf("치사율 : %.6f%%\n\n", fatality(inf, dea));
		//함수 사용, 다중소스 파일

		p.infp = inf;
		p.deap = dea;
		p.fatp = fatality(inf, dea);
		printf("확진자는 %d명, 사망자는 %d명, 치사율은 %.6f%%입니다.\n\n", p.infp, p.deap, p.fatp);
	}
	else if (aa == 2)
	{
		return 0;
	}

	int a1;
	printf("성별에 따른 확진자 정보를 확인하시겠습니까?\n");
	printf("1. 예\n2. 아니오\n");
	scanf_s("%d", &a1, sizeof(a1));

	//남 확진자, 사망자 : 8,549,227 , 11,831  
	//여 확진자, 사망자 : 9,638,973 , 12,474 
	int n1=8549227, n2=11831, n3=9638973, n4=12474;
	int *ID[4] = { &n1, &n2, &n3, &n4 };
	//포인터 활용

	if (a1 == 1)
	{
		int a2;
		printf("\n1. 남성\n2. 여성\n\n정보를 확인할 성별을 고르세요. :  \n");
		scanf_s("%d", &a2, sizeof(a2));
		if (a2 == 1)
		{
			printf("확진자는 %d명, 사망자는 %d명, 치사율은 %.6f%%입니다.\n", *ID[0], *ID[1], fatality(n1, n2));
			return 0;
		}
		else if (a2 == 2)
		{
			printf("확진자는 %d명, 사망자는 %d명, 치사율은 %.6f%%입니다.\n", *ID[2], *ID[3], fatality(n3, n4));
			return 0;
		}
	}
	else if (a1 == 2)
	{
		return 0;
	}

	return 0;
}