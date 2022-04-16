#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h> 
#include "hacker.h"

#define WIDTH 70
#define HEIGHT 20


void inputPwd(char pwd[], int size)
{
	char c;
	int i = 0;

	// 请输入密码：123456
	// 保存到字符数组pwd：'1' '2' '3' '4' '5' '6' '\0'
	while (1)
	{ 
		c = getch(); // 不会回显
		if (c == '\r') // 如果读到回车符， 返回'\r'
		{
			pwd[i] = 0; // '0'
			break;
		}
		pwd[i++] = c;
		std::cout << '*';
	}
	//std::cout << std::endl; // printf("\n");
}

// 把特定功能的代码封装成一个函数（功能）
// 以后，在需要这个功能时，就直接调用这个函数
void login(void)
{
	std::string name;
	char pwd[32];

	while (1)
	{
		system("cls");

		std::cout << "请输入账号：";
		std::cin >> name;

		std::cout << "请输入密码：";
		//std::cin >> pwd;

		// 实现密码输入
		inputPwd(pwd, sizeof(pwd));

		if (name == "54hk" && !strcmp(pwd, "123456"))
		{
			break; // 或者 return;
		}
		else
		{
			std::cout << "用户名或密码错误" << std::endl;
			system("pause");
		}
	}

}

void init(void)
{
	// 设置终端窗口的大小
	// mode con cos = 40  lins = 5
	char cmd[128];

	sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);

}

void printMiddle(std::string msg)
{
	int leftSpace = (WIDTH - msg.length()) / 2;

	for (int i = 0; i < leftSpace; i++)
	{
		std::cout << " ";
	}
	std::cout << msg << std::endl;
}

void menuShow(void)
{
	std::string menu[] =
	{
		"1、网站404攻击",
		"2、网站篡改攻击",
		"3、网站攻击记录",
		"4、攻击修复",
		"5、检查是否攻击成功",
		"6、退出"
	};

	// 计算菜单项的最大长度
	int max = 0;
	int menuCount = sizeof(menu) / sizeof(menu[0]);
	for (int i = 0; i < menuCount; i++)
	{
		if (menu[i].length() > max)
		{
			max = menu[i].length();
		}
	}

	system("cls");

	// 上边空白高度
	int topSpace = (HEIGHT - menuCount) / 2;
	for (int i = 0; i < topSpace; i++)
	{
		std::cout << std::endl;
	}

	// 打印标题
	printMiddle("---黑客攻击系统---");

	// 左边空白宽度
	int leftSpace = (WIDTH - max) / 2;
	for (int i = 0; i < menuCount; i++)
	{
		for (int i = 0; i < leftSpace; i++)
		{
			std::cout << " ";
		}
		std::cout << menu[i] << std::endl;
	}

}


int menuChoise()
{
	// 输入功能编号
	std::cout << "请输入选项：" << std::endl;
	int n = 0;
	while (1)
	{
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear(); // 把错误标记清楚
			std::cin.sync(); // 清除缓存
			std::cout << "无效输入，请重新输入" << std::endl;
			system("pause");
		}
		else
		{
			break;
		}
	}

	return n;
}

void attack404(void)
{
	char id[64]; // 网站的ID
	char response[4096]; // 攻击后，从服务器返回的结果
	system("cls");

	printMiddle("---网站404攻击---");
	std::cout << "请输入准备攻击的网站ID:：" << std::endl;

	scanf_s("%s", id, sizeof(id));

	std::cout << "正在执行404攻击..." << std::endl;
	// 发起攻击
	hk_404(id, response);
	std::string retstr = UTF8ToGBK(response);
	std::cout << retstr;

	system("pause");
}

void siteEdit(void)
{
	char id[64];
	char response[4096];
	char prar[64]; // 篡改内容
	system("cls");

	printMiddle("---网站篡改攻击---");
	std::cout << "请输入准备篡改攻击的网站ID:：" << std::endl;
	scanf_s("%s", id, sizeof(id));

	std::cout << "请输入准备篡改的内容:：" << std::endl;
	scanf_s("%s", prar, sizeof(prar));

	std::cout << "正在执行网站篡改攻击..." << std::endl;

	hk_tamper(id, prar, response);
	std::string retstr = UTF8ToGBK(response);
	std::cout << retstr;

	system("pause");
}

void attackRecord(void)
{
	char id[64];
	char response[4096];
	system("cls");

	printMiddle("---网站攻击记录---");
	std::cout << "请输入查询攻击记录的网站ID:：" << std::endl;

	scanf_s("%s", id, sizeof(id));

	std::cout << "正在查询攻击记录..." << std::endl;
	// 发起攻击
	hk_record(id, response);
	std::string retstr = UTF8ToGBK(response);
	std::cout << retstr;

	system("pause");
}

void attackRepair(void)
{
	char id[64];
	char response[4096];
	system("cls");

	printMiddle("---网站修复---");
	std::cout << "请输入准备修复的网站" << std::endl;

	scanf_s("%s", id, sizeof(id));

	std::cout << "正在修复网站..." << std::endl;
	hk_restore(id, response);
	std::string retstr = UTF8ToGBK(response);
	std::cout << retstr;

	system("pause");
}

void attackCheck(void)
{
	char response[4096];
	system("cls");

	printMiddle("---检查是否攻击成功---");
	std::cout << "正在检查..." << std::endl;

	bool ret = check_response(response);
	if (ret)
	{
		std::cout << "攻击成功！" << std::endl;
	}
	else
	{
		std::cout << "攻击失败！" << std::endl;
	}

	//std::string retstr = UTF8ToGBK(response);
	//std::cout << retstr;

	system("pause");
}

int main(void)
{
	init();

	login();

	while (1)
	{
		menuShow();
		int n = menuChoise();

		switch (n)
		{
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			attackRecord();
			break;
		case 4:
			attackRepair();
			break;
		case 5:
			attackCheck();
			break;
		case 6:
			return 0;
		default:
			std::cout << "无效输入，请重新输入" << std::endl;
			system("pause");
			break;
		}

	}



	system("pause");
	return 0;
}