#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "./Student_Manage_Sys/Student_Manage_Sys.h"

void main()
{
	struct student stu[50]; //用来保存学生记录，最多保存50条
	int select, quit = 0;
		while (1)
		{
			Menu();
			int result = scanf("%d", &select);//将用户输入的选择保存到select

			switch (select)
			{
			case 1:
				add(stu);  //添加记录
				break;
			case 2:
				ShowALL(stu);  //显示记录
				break;
			case 3:
				modify(stu);  //修改记录
				break;
			case 4:
				del(stu);  //删除记录
				break;
			case 5:
				Search(stu);  //查找记录
				break;
			case 6:
				sort(stu);  //排序记录
				break;
			case 0:
				quit = 1;;  //退出系统
				break;
			default:
				printf("请输入0-6之间的数字\n");
				break;
			}
			if (quit == 1)
				break;
			printf("将任意键返回主菜单!\n");
			getchar();  //提取缓冲区的回车键
			getchar();  //起到暂停的作用
		}
			
	printf("program stop!中文测试\n");
	system("pause");
}
