#define _CRT_SECURE_NO_WARNINGS 1
#include<time.h>
typedef struct CARD{
	char cname[6];      //卡号
	char cpassword[10]; //卡密码
	int state;          //卡状态   0-未上机  1-正在上机 2-已注销
	double useofmoney;  //使用金额
	int usenum;         //使用次数
	double balance;     //余额
	time_t start;       //上机时间
	time_t end;         //下机时间
	time_t lasttime;    //最后使用时间
	int deletion;       //删除标记  0-未注销  1-注销
	struct Card* linkcard;
}Card;