#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include "model.h"  
//���忨�Ľṹ��
#include"menu.h" 
//�˵�������ӿ�����ѯ�����ϻ����»�����ֵ���˷ѣ���ѯͳ�ƣ�ע������
#include"tool.h"
#pragma once
//ʱ�乤��

#define MAXL 100

int main(void) {
	Card *cards;
	cards = (Card*)malloc(sizeof(Card));

	int indexcard = 0;

	readCard(cards, &indexcard);

	int serial = -1;  //�����û���������
	
	
	printf("��ӭ����Ʒѹ���ϵͳ\n");
	do {
		outputmenu();

		serial = -1;

		scanf("%d", &serial);

		switch (serial) {
			case 1: {
				addcard(cards);
				break;
				}
			case 2: {
				query(cards, &indexcard);
				break;
				}
			case 3: {
				printf("�ϻ�\n");
				//�ϻ� 
				break;
				}
			case 4: {
				printf("�»�\n");
				//�»� 
				break;
				}
			case 5: {
				printf("��ֵ\n");
				//��ֵ recharge
				break;
				}
			case 6: {
				printf("�˷�\n");
				//�˷� refund
				break;
				}
			case 7: {
				printf("��ѯͳ��\n");
				//��ѯͳ�� search
				break;
				}
			case 8: {
				printf("ע����\n");
				//ע���� logout
				break;
				}
			case 0: {
				saveCard(cards, &indexcard);
				break;
				}
			default: {
				printf("����˵������Ч��\n");
				break;
				}
			}
	} while (serial != 0);
	return 0;

}