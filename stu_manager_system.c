/********************************************************************
  > File Name: stu_manager_system.c
  > Author: xiening
  > Mail:  1606598696@qq.com  
  > Created Time: 2020年01月15日 星期三 16时38分55秒
 *******************************************************************/
#include "stusystem.h"





int main(int argc, char const *argv[])
{

	int num;
	char name[20] = {0};
	char number[20] = {0};

	//初始化链表：
	PStudent_Info head = init_dou_kel_nodelist();
	if(NULL == head)
	{
		return -1;		
	}
	pagram_init_outputlist(head);

	
Main:
	//打印主界面：
	printf("\033[2J");
	printf("\033[2;20H学生信息管理系统\n");
	printf("\033[4;17H1.学生用户登录\n");
	printf("\033[6;17H2.教师用户登录\n");
	printf("\033[8;17H3.管理员用户登录\n\n");
	printf("\033[10;17H4.学生用户注册\n\n");
	printf("\033[12;17H5.教师用户注册\n\n");
	printf("\033[14;17H6.退出系统\n\n");

	//判断用户身份：
	while(1)
	{
		printf("请输入数字：");
		scanf("%d", &num);
		switch(num)
		{
			case Student:
				goto StuLogin;
			case Teacher:
				goto TecLogin;
			case Administrator:
				goto AdminLogin;
			case ZhuceStudent:
				goto StuZhuce;
			case ZhuceTeacher:
				goto TecZhuce;
			case ExitSystem:
				goto SysExit;

			default:
				printf("请输入正确的数字\n");
		}

	}
	

StuLogin:
	printf("\033[2J");
	printf("\033[2;20H学生用户登录\n\n");
	printf("请输入您的姓名：\n");
	scanf("%s", name);
	printf("请输入您的学号：\n");
	scanf("%s", number);
	PStudent_Info stulogin = stu_find_data_nodelist(name, number, head);
	if(NULL == stulogin)
	{
		printf("\n不存在此学生用户\n");
		scanf("%s", number);
		goto Main;
	}
	
	while(1)
	{
		printf("\033[2J");
		printf("\033[2;20H学生用户登录成功: %s-%s\n", name, number);
		printf("\033[4;17H1.个人信息查询\n");
		printf("\033[6;17H2.个人成绩查询\n");
		printf("\033[8;17H3.个人信息修改\n");
		printf("\033[10;17H4.退出登录(其它数字)\n");

		printf("\n请输入数字：\n");
		scanf("%d", &num);
		if(1 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H1.个人信息查询\n");
			printf("\n");
			stu_show_data_nodelist(stulogin);
			scanf("%d", &num);
		}
		else if(2 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H2.个人成绩查询\n");
			printf("\n");
			stu_Performance_find_nodelist(name, number, head);
			scanf("%d", &num);
		}
		else if(3 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H3.个人信息修改\n");
			printf("\n");
			stu_change_data_nodelist(name, number, stulogin);
			scanf("%d", &num);
		}
		else 
		{
			break;
		}
	}


	goto Main;

StuZhuce:
	printf("\033[2J");
	printf("\033[2;20H学生用户注册\n\n");
	if(!stu_head_data_nodelist(create_dou_kel_nodelist(), head))
	{
		printf("\n学生用户注册失败\n");
		scanf("%s", number);
		goto Main;
	}
	printf("\n学生用户注册成功\n");
	scanf("%s", number);

	goto Main;


TecLogin:
	printf("\033[2J");
	printf("\033[2;20H教师用户登录\n\n");
	printf("请输入教师用户名：\n");
	scanf("%s", name);
	printf("请输入教师密码：\n");
	scanf("%s", number);
	PStudent_Info teclogin = tec_find_data_nodelist(name, number, head);
	if(NULL == teclogin)
	{
		printf("\n不存在此教师用户\n");
		scanf("%s", number);
		goto Main;
	}
	while(1)
	{
		printf("\033[2J");
		printf("\033[2;20H教师用户登录成功: %s\n", name);
		printf("\033[4;17H1.学生信息查询\n");
		printf("\033[6;17H2.学生成绩查询\n");
		printf("\033[8;17H3.学生成绩修改\n");
		printf("\033[10;17H4.教师个人信息查询\n");
		printf("\033[12;17H5.教师个人信息修改\n");
		printf("\033[14;17H6.退出登录(其它数字)\n");
		printf("\n请输入数字：\n");
		scanf("%d", &num);
		if(3 == num)
		{
			printf("\n");
			printf("\033[2J");
			printf("\033[2;20H3.学生成绩修改\n\n");
			printf("请输入学生的姓名：\n");
			scanf("%s", name);
			printf("请输入学生的学号：\n");
			scanf("%s", number);
			printf("\n");
			if(Performance_input_nodelist(name, number, head))
			{
				printf("\n成绩修改成功\n");
				scanf("%s", number);
			}
			else
			{
				printf("\n成绩修改失败\n");
				scanf("%s", number);
			}
		}
		else if(2 == num)
		{
			printf("\n");
			printf("\033[2J");
			printf("\033[2;20H2.学生成绩查询\n\n");
			if(!Performance_find_nodelist(head))
			{
				printf("学生成绩查询失败\n");
				
			}
			scanf("%s", number);

		}
		else if(1 == num)
		{
			printf("\n");
			printf("\033[2J");
			printf("\033[2;20H1.学生信息查询\n\n");
			printf("\n");
			if(!tec_stu_show_data_nodelist(head))
			{
				printf("学生成绩查询失败\n");
				
			}
			scanf("%s", number);
		}
		else if(5 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H5.教师个人信息修改\n");
			printf("\n");
			tec_change_data_nodelist(name, number, teclogin);
			scanf("%d", &num);
		}
		else if(4 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H4.教师个人信息查询\n");
			printf("\n");
			tec_show_data_nodelist(teclogin);
			scanf("%d", &num);
		}
		else
		{
			break;
		}
	}
	goto Main;

TecZhuce:
	printf("\033[2J");
	printf("\033[2;20H教师用户注册\n\n");
	if(!tec_head_data_nodelist(tec_create_dou_kel_nodelist(), head))
	{
		printf("\n教师用户注册失败\n");
		scanf("%s", number);
		goto Main;
	}
	printf("\n教师用户注册成功\n");
	scanf("%s", number);

	goto Main;

AdminLogin:
	printf("\033[2J");
	printf("\033[2;20H管理员用户登录\n\n");
	printf("请输入管理员用户名：\n");
	scanf("%s", name);
	printf("请输入管理员密码：\n");
	scanf("%s", number);
	if(0 != strcmp(name, admin) 
		&& 0 != strcmp(number, adminSecret))
	{
		printf("不存在此管理员用户\n");
		scanf("%s", number);
		goto Main;
	}
	while(1)
	{
		printf("\033[2J");
		printf("\033[2;20H管理员用户登录成功: %s\n", name);
		printf("\033[4;17H1.学生用户注销\n");
		printf("\033[6;17H2.教师用户注销\n");
		printf("\033[8;17H3.退出登录(其它数字)\n");
		printf("\n请输入数字：\n");
		scanf("%d", &num);
		if(1 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H1.学生用户注销   管理员用户\n\n");
			printf("请输入学生的姓名：\n");
			scanf("%s", name);
			printf("\n");
			PStudent_Info p = adm_find_data_nodelist(name, 1, head);
			if(!stu_delete_data_nodelist(p))
			{
				printf("不存在此学生用户\n\n");;
			}
			else
			{
				printf("已注销此学生用户\n");
			}
			scanf("%s", number);
		}
		else if(2 == num)
		{
			printf("\033[2J");
			printf("\033[2;20H1.教师用户注销   管理员用户\n\n");
			printf("请输入教师的姓名：\n");
			scanf("%s", name);
			printf("\n");
			PStudent_Info p = adm_find_data_nodelist(name, 2, head);
			if(!tec_delete_data_nodelist(p))
			{
				printf("不存在此教师用户\n\n");;
			}
			else
			{
				printf("已注销此教师用户\n");
			}
			scanf("%s", number);
		}
		else
		{
			break;
		}
	}
	goto Main;


SysExit:
	if(!pagram_exit_inputfile(head))
	{
		printf("保存文件失败\n");
		scanf("%s", number);
	}


	
	
	


    return 0 ;
}
