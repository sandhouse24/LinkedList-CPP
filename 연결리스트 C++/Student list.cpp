#define _CRT_SECURE_NO_WARNINGS
#include "Student list.h"

Student::Student(int _sno, char* name, double _grade) : sno(_sno), grade(_grade), link(NULL)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Student::GetSno()
{
	return sno;
}

Student* Student::GetLink()
{
	return link;
}

void Student::ModifyLink(Student *stu)
{
	link = stu;
}

void Student::ShowStudentInfo()
{
	std::cout << "�й� : " << sno << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "���� : " << grade << std::endl;
}

Student::~Student()
{
	delete[]name;
}

StudentList::StudentList() : head(NULL) {}

void StudentList::ShowMenu()
{
	std::cout << "\n*****************MENU*****************" << std::endl;
	std::cout << "1. ��� ����" << std::endl;
	std::cout << "2. ��� ����" << std::endl;
	std::cout << "3. ��ü ��� ���" << std::endl;
	std::cout << "4. ����" << std::endl;
}

void StudentList::InsertNode(Student *stu)
{
	Student* p = head;

	if (head == NULL)
		head = stu;

	else
	{
		while (p->GetLink() != NULL)
			p = p->GetLink();
		p->ModifyLink(stu);
	}
}

Student* StudentList::SearchNode(int num)
{
	Student* p = head;

	while (p != NULL)
	{
		if (p->GetSno() == num)
			return p;
		p = p->GetLink();
	}

	return p;
}

void StudentList::DeleteNode(Student* stu)
{
	Student* p = head;

	if (stu == NULL)
	{
		std::cout << "�Է��� �й��� �л��� ���Ḯ��Ʈ �� �������� �ʽ��ϴ�." << std::endl;
		return;
	}

	while (p != NULL)
	{
		if (p->GetLink() == stu)
		{
			p->ModifyLink(stu->GetLink());
			std::cout << "���� �޷�" << std::endl;
			return;
		}
		p = p->GetLink();
	}
}

void StudentList::PrintList()
{
	Student* p = head;

	while (p != NULL)
	{
		p->ShowStudentInfo();
		p = p->GetLink();
		std::cout << "\n";
	}
}

void StudentList::FreeNode()
{
	Student* p;

	while (head != NULL)
	{
		p = head;
		head = head->GetLink();
		delete p;
		p = NULL;
	}
}

