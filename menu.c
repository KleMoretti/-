#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"model.h"  //结构体
#include"menu.h"
/*菜单输出函数*/
void outputmenu() {
	printf("---------菜单---------\n");
	printf("1.添加卡\n");
	printf("2.查询卡\n");
	printf("3.上机\n");
	printf("4.下机\n");
	printf("5.充值\n");
	printf("6.退费\n");
	printf("7.查询统计\n");
	printf("8.注销卡\n");
	printf("0.退出\n");
	printf("请选择菜单编号（0~8）:");
}

/*添加卡函数*/
void addcard(Card* cards) {

	char mname[6] = { 0 };
	char mpassword[10] = { 0 };

	Card* next;
	next = (Card*)malloc(sizeof(Card));
	//新建结构体存放新卡，随后复制进结构体中

	while(next!=NULL)
	{
		printf("----------添加卡-----------\t\n");
		printf("请输入卡号（长度为5）：");
		scanf("%6s", mname);
		if (strlen(mname) != 5) {
			printf("卡号长度不符！\n");
			return;
		}
		if (!qureycard(mname, p, &cards)) {
			printf("卡号已经存在!\n");
			return;
		}
		/*if (mname != (int)mname) {
			printf("请输入数字卡号！\n");
			return;
		}*/
		strcpy(next->cname, mname);

		printf("请输入卡号密码（长度1-8）：");
		scanf("%9s", mpassword);
		if (strlen(mpassword) >= 8) {
			printf("卡号密码过长，请重新开卡！\n");
			return;
		}
		strcpy(next->cpassword, mpassword);
		printf("请输入开卡金额（RMB）：");
		scanf("%lf", &next->balance);
		if (next->balance < 0) {
			printf("输入的开卡金额不能小于0！\n");
			return;
		}
		if (next->balance != (int)next->balance) {
			printf("请输入整数金额！\n");
			return;
		}
		next->useofmoney = next->balance;
		next->deletion = 0;
		next->state = 0;
		next->usenum = 0;
		next->start = next->end = next->lasttime = time(NULL);  //获取系统时间，单位为秒;

		//C 库函数 time_t time(time_t *seconds) 返回自纪元 Epoch（1970-01-01 00:00:00 UTC）起经过的时间，以秒为单位。
		// 如果 seconds 不为空，则返回值也存储在变量 seconds 中。

		struct tm* endoftime;
		endoftime = localtime(&next->end);

		//C 库函数 struct tm *localtime(const time_t *timer) 使用 timer 的值来填充 tm 结构。
		// timer 的值被分解为 tm 结构，并用本地时区表示。

		endoftime->tm_year = endoftime->tm_year + 2;//每张卡有效期2年
		next->end = mktime(endoftime);   
		cards = next;			//保存至结构体中
		next = cards->linkcard;
		printf("添加卡状态成功!\n");
	}
}

void readCard(Card cards[], int* p) {
	*p = 0;
	FILE* fp = NULL;
	if ((fp = fopen("card.dat", "rb")) == NULL)
		//C 库函数 FILE *fopen(const char *filename, const char *mode) 使用给定的模式 mode 打开 filename 所指向的文件。
		//filename -- 字符串，表示要打开的文件名称。  mode -- 字符串，表示文件的访问模式
		//  使用方式	            作用 	             如果文件不存在
		//"rb+"（读写）	为了读和写，打开一个二进制文件	     出错
	{
		return;
	}
	while (!feof(fp))
		//feof()是检测流上的文件结束符的函数，如果文件结束，则返回非0值，否则返回0
	{
		if (fread(&cards[*p], sizeof(Card), 1, fp) != 0)
			//C 库函数 size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) 
			// 从给定流 stream 读取数据到 ptr 所指向的数组中。
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