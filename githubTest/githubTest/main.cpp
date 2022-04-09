#include <iostream>
#include <Windows.h>
#include <string>

/*
1¡¢ÍøÕ¾404¹¥»÷
2¡¢ÍøÕ¾´Û¸Ä¹¥»÷
3¡¢ÍøÕ¾¹¥»÷¼ÇÂ¼
4¡¢DNS¹¥»÷
5¡¢·şÎñÆ÷ÖØÆô¹¥»÷
*/


int main(void)
{
	std::string name;
	std::string pwd;

	while (1)
	{
		std::cout << "ÇëÊäÈëÕËºÅ£º";
		std::cin >> name;

		std::cout << "ÇëÊäÈëÃÜÂë£º";
		std::cin >> pwd;

		if (name == "54hk" && pwd == "123456")
		{
			break;
		}
		else
		{
			std::cout << "ÓÃ»§Ãû»òÃÜÂë´íÎó" << std::endl;
		}
	}

	std::cout << "1¡¢ÍøÕ¾404¹¥»÷" << std::endl;
	std::cout << "2¡¢ÍøÕ¾´Û¸Ä¹¥»÷" << std::endl;
	std::cout << "3¡¢ÍøÕ¾¹¥»÷¼ÇÂ¼" << std::endl;
	std::cout << "4¡¢DNS¹¥»÷" << std::endl;
	std::cout << "5¡¢·şÎñÆ÷ÖØÆô¹¥»÷" << std::endl;

	system("pause");
	return 0;
}