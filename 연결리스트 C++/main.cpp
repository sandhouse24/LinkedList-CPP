#include "Student list.h"

int main(void)
{
	StudentList linkedList;
	int select;

	while (true)
	{
		linkedList.ShowMenu();
		std::cin >> select;

		switch (select)
		{
		case 1:
		{
			int sno;
			char name[15];
			double grade;
			std::cout << "�й� �Է� : ";
			std::cin >> sno;
			std::cout << "�̸� �Է� : ";
			std::cin >> name;
			std::cout << "���� �Է� : ";
			std::cin >> grade;
			Student* s = new Student(sno, name, grade);
			linkedList.InsertNode(s);
			break;
		}

		case 2:
		{
			int num;
			std::cout << "������ �л��� �й� �Է� : ";
			std::cin >> num;
			linkedList.DeleteNode(linkedList.SearchNode(num));
			break;
		}

		case 3:
			linkedList.PrintList();
			break;

		case 4:
			linkedList.FreeNode();
			exit(0);
		}
	}
	return 0;
}

