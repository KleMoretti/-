#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
typedef struct CARD{
	char cname[6];      //����
	char cpassword[10]; //������
	int state;          //��״̬   0-δ�ϻ�  1-�����ϻ� 2-��ע��
	double useofmoney;  //ʹ�ý��
	int usenum;         //ʹ�ô���
	double balance;     //���
	time_t start;       //�ϻ�ʱ��
	time_t end;         //�»�ʱ��
	time_t lasttime;    //���ʹ��ʱ��
	int deletion;       //ɾ�����  0-δע��  1-ע��
	struct Card* linkcard;
}Card;