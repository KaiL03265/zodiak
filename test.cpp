#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

struct Human
{
	std::string name;
	std::string zodiak;
	int birthDay[3];
};
void NewUser(std::vector<Human>& data);
void ShowAll(std::vector<Human>& data);
int NumberZodiak(std::string zodiak);
void Sort(std::vector<Human>& data);


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<Human>znak;
	for (int i = 0; i < 4; i++)
	{
		NewUser(znak);
	}
	std::cout << std::endl;
	ShowAll(znak);
	std::cout<<std::endl;
	Sort(znak);


	return 0;
}
void NewUser(std::vector<Human>& data)
{
	Human temp;
	std::cout << "������� ���: ";
	std::getline(std::cin, temp.name);
	std::cout << "������� ���� ��������: ";
	std::cin >> temp.birthDay[0];
	std::cout << "������� ����� ��������: ";
	std::cin >> temp.birthDay[1];
	std::cout << "������� ��� ��������: ";
	std::cin >> temp.birthDay[2];
	if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 3) ||
		(temp.birthDay[0] <= 19 && temp.birthDay[1] == 4))
	{
		temp.zodiak = "����";
	}
	else if ((temp.birthDay[0] >= 20 && temp.birthDay[1] == 4) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 5))
	{
		temp.zodiak = "�����";
	}
	else if((temp.birthDay[0] >= 21 && temp.birthDay[1] == 5)||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 6))
	{
		temp.zodiak = "��������";
	}
	else if ((temp.birthDay[0] >= 21 && temp.birthDay[1] == 6) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 7))
	{
		temp.zodiak = "���";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 7) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 8))
	{
		temp.zodiak = "���";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 8) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 9))
	{
		temp.zodiak = "����";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 9) ||
		(temp.birthDay[0] <= 22 && temp.birthDay[1] == 10))
	{
		temp.zodiak = "����";
	}
	else if ((temp.birthDay[0] >= 23 && temp.birthDay[1] == 10) ||
		(temp.birthDay[0] <= 21 && temp.birthDay[1] == 11))
	{
		temp.zodiak = "��������";
	}
	else if ((temp.birthDay[0] >= 22 && temp.birthDay[1] == 11) ||
		(temp.birthDay[0] <= 21 && temp.birthDay[1] == 12))
	{
		temp.zodiak = "�������";
	}
	else if ((temp.birthDay[0] >= 22 && temp.birthDay[1] == 12) ||
		(temp.birthDay[0] <= 19 && temp.birthDay[1] == 1))
	{
		temp.zodiak = "�������";
	}
	else if ((temp.birthDay[0] >= 20 && temp.birthDay[1] == 1) ||
		(temp.birthDay[0] <= 18 && temp.birthDay[1] == 2))
	{
		temp.zodiak = "�������";
	}
	else if ((temp.birthDay[0] >= 19 && temp.birthDay[1] == 2) ||
		(temp.birthDay[0] <= 20 && temp.birthDay[1] == 3))
	{
		temp.zodiak = "����";
	}
	else
	{
		std::cerr << "������ ������ �������";
		temp.zodiak = "Erorr";
	}
	std::cin.ignore();
	data.push_back(temp);
}
void ShowAll(std::vector<Human>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << "���: " << data.at(i).name << "\n";
		std::cout << "������: " << data.at(i).zodiak << "\n";
		std::cout << "���� ��������: " << data.at(i).birthDay[0]<<"." << data.at(i).birthDay[1]<<"." << data.at(i).birthDay[2] << "\n";
	}
}
int NumberZodiak(std::string zodiak)
{
	if (zodiak == "����")
	{
		return 1;
	}
	else if (zodiak == "�����")
	{
		return 2;
	}
	else if (zodiak == "��������")
	{
		return 3;
	}
	else if (zodiak == "���")
	{
		return 4;
	}
	else if (zodiak == "���")
	{
		return 5;
	}
	else if (zodiak == "����")
	{
		return 6;
	}
	else if (zodiak == "����")
	{
		return 7;
	}
	else if (zodiak == "��������")
	{
		return 8;
	}
	else if (zodiak == "�������")
	{
		return 9;
	}
	else if (zodiak == "�������")
	{
		return 10;
	}
	else if (zodiak == "�������")
	{
		return 11;
	}
	else if (zodiak == "����")
	{
		return 12;
	}
}
void Sort(std::vector<Human>& data)
{
	Human temp;
	for (int i = 0; i < data.size() - 1; i++)
	{
		for (int j = 0; j < data.size() - 1; j++)
		{
			if (NumberZodiak(data.at(j + 1).zodiak) < NumberZodiak(data.at(j).zodiak))
			 {
				temp = data.at(j + 1);
				data.at(j + 1) = data.at(j);
				data.at(j) = temp;
			}
		}
	}
	ShowAll(data);
}

