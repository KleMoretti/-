#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"model.h"
#include"tool.h"
#include<string.h>
int qureycard(char* name, int* p, Card* pcard) {
	if (*p == 0)
		return 0;
	int i;
	for (i = 0; i < *p; i++)  //Ϊʲô����i<=*p:��Ϊ����Ԫ�ش�0��ʼ�����統p=1ʱ����ʾֻ��һ��Ԫ�أ���ʱi=0
	{
		if (strcmp(pcard[i].cname, name) == 0) {
			return i;
		}
	}
	return -1;
}

void query(Card cards[], int* pq) {
	int index;
	printf("׼ȷ��ѯ----0\n");
	printf("ģ����ѯ----1\n");
	printf("�������ѯ��ʽ��\n");
	scanf("%d", &index);
	switch(index){
	case 0:
	{
		int ppnum;
		char nname[6] = { 0 };
		char timeinnow[25] = { 0 };
		printf("������Ҫ��ѯ�Ŀ��ţ�");
		scanf("%6s", &nname);
		if (!(qureycard(nname, pq, cards)) ){
			printf("�Ѳ�ѯ������\n");
			ppnum = qureycard(nname, pq, cards);
		printf("\n%6s%10s%8s%8s%15s%15s\n", "����", "����", "״̬", "���", "ʹ�ô���", "����ʱ��");
		printf("-------------------------------------------------------------\n");
		printf("%6s", cards[ppnum].cname);
		printf("%10s", cards[ppnum].cpassword);
		printf("%10s", cards[ppnum].state == 0 ? "δ�ϻ�":"���ϻ�");
		printf("%8.2f", cards[ppnum].balance);
		printf("%6d", cards[ppnum].usenum);
		timetostring(cards[ppnum].start, timeinnow);
		printf("%25s\n", timeinnow);
         
		}
		else printf("���Ų�����\n");
		break;
	}
	case 1:
	{
		printf("\n%6s%10s%8s%8s%15s%15s\n", "����", "����", "״̬", "���", "ʹ�ô���", "����ʱ��");
		printf("-------------------------------------------------------------\n");
		char timeinnoww[25] = { 0 };
		for (int i = 0; i < *pq; i++) {
			printf("%6s",cards[i].cname);
			printf("%10s",cards[i].cpassword);
			printf("%10s",cards[i].state==0?"δ�ϻ�":"���ϻ�");
			printf("%8.2f",cards[i].balance);
			printf("%6d",cards[i].usenum);
			timetostring(cards[i].start, timeinnoww);
			printf("%25s\n", timeinnoww);
		}
		printf("\n");
	}
}
	return;
}

void timetostring(time_t t, char* pBuff) {
	struct tm* timeof;
	timeof = localtime(&t);
	strftime(pBuff, 25, "%Y-%m-%d-%a %H:%M", timeof);
}

void stringtotime(char* ptime) {
	struct tm qtime;
	time_t qqtime;
	sscanf(ptime, "%d-%d-%d-%d %d:%d", &qtime.tm_year, &qtime.tm_mon, &qtime.tm_mday, &qtime.tm_wday, &qtime.tm_hour, &qtime.tm_hour);

	qtime.tm_year -= 1900;
	qtime.tm_mon -= 1;
	
	qtime.tm_sec = 0;
	qtime.tm_isdst = -1;
	qqtime = mktime(&qtime);
	return qtime;
}
