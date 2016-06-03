#include<iostream>
#include<cstring>

using namespace std;

const int NAME = 30;
const int MAX = 10;

class Student {
	char Name[NAME];
	char surname[NAME];
public:
	Student(const char * _name = "", const char * _surname = "")
	{
		strcpy_s(Name, _name);
		strcpy_s(surname, _surname);
	}
	void printStudnet() {
		cout << "Studnet's name" << Name << " " << surname << endl;
	}
};
class Group {
	Student students[MAX];
	char GroupName[NAME];
	int groupsLenght;
	int StudentsLength;
public:
	Group(const char * _GroupName = "") :groupsLenght(0), StudentsLength(0) {
		strcpy_s(GroupName, _GroupName);
	}
	void addStudent(Student & student, Group & group)
	{
		students[StudentsLength] = student;
		StudentsLength++;
	}
	void PrintGroup() {
		cout << "Group name : " << GroupName << endl;
		for (int i = 0; i < StudentsLength; i++)
		{
			students[i].printStudnet();
		}
	}
};
class Teacher {
	char name[NAME];
	char surname[NAME];
	Group groups[MAX];
	int groupsLenght;
public:
	Teacher(const char * _name = " ", const char * _surname = "") : groupsLenght(0) {
		strcpy_s(name, _name);
		strcpy_s(surname, _surname);
	}

	void teachGroup(Group & group)
	{
		groups[groupsLenght] = group;
		groupsLenght++;
	}
	void PrintTeacher() {
		cout << "Teacher's name" << name << surname << endl;
		for (int i = 0; i < groupsLenght; i++) {
			groups[i].PrintGroup();
		}
	}
};
class School {
	char name[NAME];
	Teacher teachers[MAX];
	int teachersLenght;
	Group groups[MAX];
	int groupsLenght;
	Student students[MAX];
	int StudentsLength;

public:

	School(const char * _name = "") : teachersLenght(0), groupsLenght(0), StudentsLength(0) {
		strcpy_s(name, _name);
	}
	void addStudent(Student & student, Group & group)
	{
		students[StudentsLength] = student;
		StudentsLength++;
		group.addStudent(student, group);
	}
	void addGroup(Group & group, Teacher & teacher)
	{
		groups[groupsLenght] = group;
		groupsLenght++;
		teacher.teachGroup(group);
	}
	void addTeacher(Teacher & teacher)
	{
		teachers[teachersLenght] = teacher;
		teachersLenght++;
	}
	void print() {
		cout << "School's Name" << name << endl;
		for (int i = 0; i < teachersLenght; i++) {
			teachers[i].PrintTeacher();
			cout << endl;
		}
	}
};
int main()
{
	School school("Svoboda");
	Group group("Angliiski ezik");
	Teacher teacher("Zdravko");
	school.addTeacher(teacher);
	Student student("Zdravko", "Chiflishki");
	school.addGroup(group, teacher);
	school.addStudent(student, group);
	school.print();
	system("pause");
	return 0;
}