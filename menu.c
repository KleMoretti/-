#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"model.h"  //�ṹ��
#include"menu.h"
/*�˵��������*/
void outputmenu() {
	printf("---------�˵�---------\n");
	printf("1.��ӿ�\n");
	printf("2.��ѯ��\n");
	printf("3.�ϻ�\n");
	printf("4.�»�\n");
	printf("5.��ֵ\n");
	printf("6.�˷�\n");
	printf("7.��ѯͳ��\n");
	printf("8.ע����\n");
	printf("0.�˳�\n");
	printf("��ѡ��˵���ţ�0~8��:");
}

/*��ӿ�����*/
void addcard(Card* cards) {

	char mname[6] = { 0 };
	char mpassword[10] = { 0 };

	Card* next;
	next = (Card*)malloc(sizeof(Card));
	//�½��ṹ�����¿�������ƽ��ṹ����

	while(next!=NULL)
	{
		printf("----------��ӿ�-----------\t\n");
		printf("�����뿨�ţ�����Ϊ5����");
		scanf("%6s", mname);
		if (strlen(mname) != 5) {
			printf("���ų��Ȳ�����\n");
			return;
		}
		if (!qureycard(mname, p, &cards)) {
			printf("�����Ѿ�����!\n");
			return;
		}
		/*if (mname != (int)mname) {
			printf("���������ֿ��ţ�\n");
			return;
		}*/
		strcpy(next->cname, mname);

		printf("�����뿨�����루����1-8����");
		scanf("%9s", mpassword);
		if (strlen(mpassword) >= 8) {
			printf("������������������¿�����\n");
			return;
		}
		strcpy(next->cpassword, mpassword);
		printf("�����뿪����RMB����");
		scanf("%lf", &next->balance);
		if (next->balance < 0) {
			printf("����Ŀ�������С��0��\n");
			return;
		}
		if (next->balance != (int)next->balance) {
			printf("������������\n");
			return;
		}
		next->useofmoney = next->balance;
		next->deletion = 0;
		next->state = 0;
		next->usenum = 0;
		next->start = next->end = next->lasttime = time(NULL);  //��ȡϵͳʱ�䣬��λΪ��;

		//C �⺯�� time_t time(time_t *seconds) �����Լ�Ԫ Epoch��1970-01-01 00:00:00 UTC���𾭹���ʱ�䣬����Ϊ��λ��
		// ��� seconds ��Ϊ�գ��򷵻�ֵҲ�洢�ڱ��� seconds �С�

		struct tm* endoftime;
		endoftime = localtime(&next->end);

		//C �⺯�� struct tm *localtime(const time_t *timer) ʹ�� timer ��ֵ����� tm �ṹ��
		// timer ��ֵ���ֽ�Ϊ tm �ṹ�����ñ���ʱ����ʾ��

		endoftime->tm_year = endoftime->tm_year + 2;//ÿ�ſ���Ч��2��
		next->end = mktime(endoftime);   
		cards = next;			//�������ṹ����
		next = cards->linkcard;
		printf("��ӿ�״̬�ɹ�!\n");
	}
}

void readCard(Card cards[], int* p) {
	*p = 0;
	FILE* fp = NULL;
	if ((fp = fopen("card.dat", "rb")) == NULL)
		//C �⺯�� FILE *fopen(const char *filename, const char *mode) ʹ�ø�����ģʽ mode �� filename ��ָ����ļ���
		//filename -- �ַ�������ʾҪ�򿪵��ļ����ơ�  mode -- �ַ�������ʾ�ļ��ķ���ģʽ
		//  ʹ�÷�ʽ	            ���� 	             ����ļ�������
		//"rb+"����д��	Ϊ�˶���д����һ���������ļ�	     ����
	{
		return;
	}
	while (!feof(fp))
		//feof()�Ǽ�����ϵ��ļ��������ĺ���������ļ��������򷵻ط�0ֵ�����򷵻�0
	{
		if (fread(&cards[*p], sizeof(Card), 1, fp) != 0)
			//C �⺯�� size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) 
			// �Ӹ����� stream ��ȡ���ݵ� ptr ��ָ��������С�
		{
			(*p)++;
		}
	}
	fclose(fp);
}

void saveCard(Card cards[], int* p) {
	FILE* fp = NULL;
	if ((fp = fopen("card.dat", "wb+")) == NULL) {
		return;
	}
	for (int i = 0; i < *p; i++) {
		fwrite(&cards[i], sizeof(Card), 1, fp);
	}
	fclose(fp);
}