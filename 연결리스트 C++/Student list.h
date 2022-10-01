#pragma once
#include <iostream>

class Student
{
	int sno;
	char* name;
	double grade;
	Student* link;

public:
	Student(int _sno, char* name, double _grade);
	int GetSno();
	Student* GetLink();
	void ModifyLink(Student* stu);
	void ShowStudentInfo();
	~Student();
};

class StudentList
{
	Student* head;

public:
	StudentList();
	void ShowMenu();
	void InsertNode(Student* stu);
	Student* SearchNode(int num);
	void DeleteNode(Student* stu);
	void PrintList();
	void FreeNode();
};
