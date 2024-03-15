#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include "model.h"  
//定义卡的结构体
#include"menu.h" 
//菜单栏：添加卡，查询卡，上机，下机，充值，退费，查询统计，注销函数
#include"tool.h"
#pragma once
//时间工具

#define MAXL 100

int main(void) {
	Card *cards;
	cards = (Card*)malloc(sizeof(Card));

	int indexcard = 0;

	readCard(cards, &indexcard);

	int serial = -1;  //定义用户输入的序号
	
	
	printf("欢迎进入计费管理系统\n");
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
				printf("上机\n");
				//上机 
				break;
				}
			case 4: {
				printf("下机\n");
				//下机 
				break;
				}
			case 5: {
				printf("充值\n");
				//充值 recharge
				break;
				}
			case 6: {
				printf("退费\n");
				//退费 refund
				break;
				}
			case 7: {
				printf("查询统计\n");
				//查询统计 search
				break;
				}
			case 8: {
				printf("注销卡\n");
				//注销卡 logout
				break;
				}
			case 0: {
				saveCard(cards, &indexcard);
				break;
				}
			default: {
				printf("输入菜单编号无效！\n");
				break;
				}
			}
	} while (serial != 0);
	return 0;

}