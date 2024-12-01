#define _CRT_SECURE_NO_WARNINGS
#include "Student_Manage_Sys.h"

/*显示开始菜单界面*/
void Menu()
{
	system("cls");//清空屏幕
	printf("\n");
	printf("\t\t -------------学生成绩管理系统--------------\n");
	printf("\t\t | \t\t 1. 添加记录 \t\t   | \n");
	printf("\t\t | \t\t 2. 显示记录 \t\t   | \n");
	printf("\t\t | \t\t 3. 修改记录 \t\t   | \n");
	printf("\t\t | \t\t 4. 删除记录 \t\t   | \n");
	printf("\t\t | \t\t 5. 查找记录 \t\t   | \n");
	printf("\t\t | \t\t 6. 排序记录 \t\t   | \n");
	printf("\t\t | \t\t 0. 退出系统 \t\t   | \n");
	printf("\t\t -------------------------------------------\n");
	printf("\t\t请选择(0-6):");
}


/*添加学生信息*/
void add(struct student stu[])
{
	int i, id = 0; //i作为循环变量，id用来保存新学号
	char quit; //保存"是否退出"的选择
	do
	{
		printf("学号:");
		int result = scanf("%d", &id);
		for (i = 0; i < n; i++)
		{
			if (id == stu[i].id)  //假如新学号等于数组中某生的学号
			{
				printf("此学号存在!\n");
				return;
			}
		}

		stu[i].id = id;
		printf("姓名：");
		result = scanf("%s",&stu[i].name);
		printf("语文成绩：");
		result = scanf("%d", &stu[i].chinese);
		printf("数学成绩:");
		result = scanf("%d",&stu[i].math);
		stu[i].sum = stu[i].chinese + stu[i].math; //计算总成绩
		n++;//记录条数加一
		printf("是否继续添加？(Y/N)");
		result = scanf("\t%c",&quit);
	} while (quit != 'N');

}


/*显示某个学生信息*/
void show(struct student stu[],int i)
{
	printf("%-10d",stu[i].id);
	printf("%-10s", stu[i].name);
	printf("%-10d", stu[i].chinese);
	printf("%-10d", stu[i].math);
	printf("%-10d\n", stu[i].sum);

}

/*显示全部学生信息*/
void ShowALL(struct student stu[])
{
	int i;
	HH;
	for (i=0;i<n;i++)
	{
		show(stu, i);
	}
}

/*修改信息*/
void modify(struct student stu[])
{
	char name[8], ch;  //name用来保存姓名，ch用来保存"是否退出"的选择
	int i;  //用来当作循环变量
	printf("修改学生的记录。\n");
	printf("请输入学生的姓名：");
	int result = scanf("%s", &name);
	for (i = 0; i < n; i++)
	{
		if (strcmp(name, stu[i].name) == 0)
		{
			getchar(); //提取并丢掉回车键
			printf("找到该生的记录，如下所示：\n");
			HH;  //显示记录的标题
			show(stu,i); //显示数组stu中的第i条记录
			printf("是否修改?(Y/N)");
			result = scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				getchar(); //提取并丢掉回车键
				printf("姓名");
				result = scanf("%s", &stu[i].name);
				printf("语文成绩: ");
				result = scanf("%d",&stu[i].chinese);
				printf("数学成绩：");
				result = scanf("%d", &stu[i].math);
				stu[i].sum= stu[i].chinese + stu[i].math;
				printf("修改完毕。\n");
			}
			return;
		}
	}
	printf("没有找到该生的记录");
}


/*删除学生的记录*/
void del(struct student stu[])
{
	int id, i; //id用来记录学号，i用来当作循环变量
	char ch;
	printf("删除学生的记录。\n");
	printf("请输入学号：");
	int result = scanf("%d",&id);
	for (i = 0; i < n; i++)
	{
		if (id == stu[i].id)
		{
			getchar();
			printf("找到改生的记录，如下所示：\n");
			HH;  //显示记录的主题
			show(stu,i); //显示数组stu中的第i条记录
			printf("是否删除？(Y/N)\n");
			int result = scanf("%c",&ch);
			if (ch == 'Y' || ch == 'y')
			{
				for (; i < n; i++)
					stu[i] = stu[i + 1]; //被删除记录后面的记录均前移一位
				n--;   //记录总条数减1
				printf("删除成功!");
			}
			return;
		}
	}
	printf("没有找到改生的记录!\n");
}


/*搜索学生信息*/
void Search(struct student stu[])
{
	char name[8]; //用来存放学生姓名
	int i; //用来当作循环变量
	printf("查找学生的记录。\n");
	printf("请输入学生的姓名：");
	int result = scanf("%s",&name);
	for (i = 0; i < n; i++)
	{
		if (strcmp(name,stu[i].name) == 0)
		{
			printf("找到改生的记录，如下所图：\n");
			HH;//显示记录的主题
			show(stu,i);//显示数组stu中的第i条记录
			return;
		}
	}
	printf("没有找到该生的记录。\n");
}

/*排序分类*/
void sort(struct student stu[])
{
	int i, j;
	struct student t;
	printf("按总成绩进行排序，");
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (stu[i].sum < stu[j].sum)
			{
				t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
			}
		}
	}

	printf("排序结果如下：\n");
	ShowALL(stu); //显示排序后的所有记录
}
