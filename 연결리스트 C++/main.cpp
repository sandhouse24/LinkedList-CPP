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
			std::cout << "학번 입력 : ";
			std::cin >> sno;
			std::cout << "이름 입력 : ";
			std::cin >> name;
			std::cout << "학점 입력 : ";
			std::cin >> grade;
			Student* s = new Student(sno, name, grade);
			linkedList.InsertNode(s);
			break;
		}

		case 2:
		{
			int num;
			std::cout << "삭제할 학생의 학번 입력 : ";
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

