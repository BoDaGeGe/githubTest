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

	// ���������룺123456
	// ���浽�ַ�����pwd��'1' '2' '3' '4' '5' '6' '\0'
	while (1)
	{ 
		c = getch(); // �������
		if (c == '\r') // ��������س����� ����'\r'
		{
			pwd[i] = 0; // '0'
			break;
		}
		pwd[i++] = c;
		std::cout << '*';
	}
	//std::cout << std::endl; // printf("\n");
}

// ���ض����ܵĴ����װ��һ�����������ܣ�
// �Ժ�����Ҫ�������ʱ����ֱ�ӵ����������
void login(void)
{
	std::string name;
	char pwd[32];

	while (1)
	{
		system("cls");

		std::cout << "�������˺ţ�";
		std::cin >> name;

		std::cout << "���������룺";
		//std::cin >> pwd;

		// ʵ����������
		inputPwd(pwd, sizeof(pwd));

		if (name == "54hk" && !strcmp(pwd, "123456"))
		{
			break; // ���� return;
		}
		else
		{
			std::cout << "�û������������" << std::endl;
			system("pause");
		}
	}

}

void init(void)
{
	// �����ն˴��ڵĴ�С
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
		"1����վ404����",
		"2����վ�۸Ĺ���",
		"3����վ������¼",
		"4�������޸�",
		"5������Ƿ񹥻��ɹ�",
		"6���˳�"
	};

	// ����˵������󳤶�
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

	// �ϱ߿հ׸߶�
	int topSpace = (HEIGHT - menuCount) / 2;
	for (int i = 0; i < topSpace; i++)
	{
		std::cout << std::endl;
	}

	// ��ӡ����
	printMiddle("---�ڿ͹���ϵͳ---");

	// ��߿հ׿��
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
	// ���빦�ܱ��
	std::cout << "������ѡ�" << std::endl;
	int n = 0;
	while (1)
	{
		std::cin >> n;
		if (std::cin.fail())
		{
			std::cin.clear(); // �Ѵ��������
			std::cin.sync(); // �������
			std::cout << "��Ч���룬����������" << std::endl;
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
	char id[64]; // ��վ��ID
	char response[4096]; // �����󣬴ӷ��������صĽ��
	system("cls");

	printMiddle("---��վ404����---");
	std::cout << "������׼����������վID:��" << std::endl;

	scanf_s("%s", id, sizeof(id));

	std::cout << "����ִ��404����..." << std::endl;
	// ���𹥻�
	hk_404(id, response);
	std::string retstr = UTF8ToGBK(response);
	std::cout << retstr;

	system("pause");
}

void siteEdit(void)
{
	char id[64];
	char response[4096];
	char prar[64]; // �۸�����
	system("cls");

	printMiddle("---��վ�۸Ĺ���---");
	std::cout << "������׼���۸Ĺ�������վID:��" << std::endl;
	scanf_s("%s", id, sizeof(id));

	std::cout << "������׼���۸ĵ�����:��" << std::endl;
	scanf_s("%s", prar, sizeof(prar));

	std::cout << "����ִ����վ�۸Ĺ���..." << std::endl;

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

	printMiddle("---��վ������¼---");
	std::cout << "�������ѯ������¼����վID:��" << std::endl;

	scanf_s("%s", id, sizeof(id));

	std::cout << "���ڲ�ѯ������¼..." << std::endl;
	// ���𹥻�
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

	printMiddle("---��վ�޸�---");
	std::cout << "������׼���޸�����վ" << std::endl;

	scanf_s("%s", id, sizeof(id));

	std::cout << "�����޸���վ..." << std::endl;
	hk_restore(id, response);
	std::string retstr = UTF8ToGBK(response);
	std::cout << retstr;

	system("pause");
}

void attackCheck(void)
{
	char response[4096];
	system("cls");

	printMiddle("---����Ƿ񹥻��ɹ�---");
	std::cout << "���ڼ��..." << std::endl;

	bool ret = check_response(response);
	if (ret)
	{
		std::cout << "�����ɹ���" << std::endl;
	}
	else
	{
		std::cout << "����ʧ�ܣ�" << std::endl;
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
			std::cout << "��Ч���룬����������" << std::endl;
			system("pause");
			break;
		}

	}



	system("pause");
	return 0;
}