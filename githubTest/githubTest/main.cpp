#include <iostream>
#include <Windows.h>
#include <string>

/*
1����վ404����
2����վ�۸Ĺ���
3����վ������¼
4��DNS����
5����������������
*/


int main(void)
{
	std::string name;
	std::string pwd;

	while (1)
	{
		std::cout << "�������˺ţ�";
		std::cin >> name;

		std::cout << "���������룺";
		std::cin >> pwd;

		if (name == "54hk" && pwd == "123456")
		{
			break;
		}
		else
		{
			std::cout << "�û������������" << std::endl;
		}
	}

	std::cout << "1����վ404����" << std::endl;
	std::cout << "2����վ�۸Ĺ���" << std::endl;
	std::cout << "3����վ������¼" << std::endl;
	std::cout << "4��DNS����" << std::endl;
	std::cout << "5����������������" << std::endl;

	system("pause");
	return 0;
}