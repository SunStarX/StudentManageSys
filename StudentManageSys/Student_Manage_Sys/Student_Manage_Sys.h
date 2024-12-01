#ifndef STUDENT_MANAGE_SYS_H
#define STUDENT_MANAGE_SYS_H

#include <stdio.h>
#include <stdlib.h>

#define	HH	printf("%-10s%-10s%-10s%-10s%-10s\n","语文","姓名","语文成绩","数学成绩","总分")

/*定义一个学生信息的结构体*/
struct student
{
	int id; /*学号*/
	char name[8];/*姓名*/
	int chinese;/*语文成绩*/
	int math; /*数学成绩*/
	int sum; /*总分*/
};	

static int n; //记录学生信息条数


void Menu();
void add(struct student stu[]);
void show(struct student stu[], int i);
void ShowALL(struct student stu[]);
void modify(struct student stu[]);
void del(struct student stu[]);
void Search(struct student stu[]);
void sort(struct student stu[]);

#endif

