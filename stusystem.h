/********************************************************************
  > File Name: stusystem.h
  > Author: xiening
  > Mail:  1606598696@qq.com  
  > Created Time: 2020年01月15日 星期三 17时09分25秒
 *******************************************************************/

#ifndef __stusystem_h__
#define __stusystem_h__ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define admin "admin"
#define adminSecret "123456"

typedef struct PERFORMANCE 
{
	int Math;
	int Maogai;
	int English;
	int C_languague;
}Performance, *PPerformance;

struct list_head
{
	struct list_head *prev;
	struct list_head *next;
};

typedef struct STUDENT_INFO
{
	char name[20];
	char number[20]; //学生用
	char secret[20]; //教师用
	char sex[10];
	char age[20];
	Performance result;
	struct list_head small_list1;
	struct list_head small_list2;
	struct list_head small_list3;

}Student_Info, *PStudent_Info;

enum user{
	Student = 1,
	Teacher,
	Administrator,
	ZhuceStudent,
	ZhuceTeacher,
	ExitSystem
};


//初始化双向内核链表
PStudent_Info init_dou_kel_nodelist();


//学生个人信息创建
PStudent_Info create_dou_kel_nodelist();

//教师个人信息创建
PStudent_Info tec_create_dou_kel_nodelist();

//学生个人信息头插入
bool stu_head_data_nodelist(PStudent_Info p, PStudent_Info head);

//教师个人信息头插入
bool tec_head_data_nodelist(PStudent_Info p, PStudent_Info head);

//查找学生是否存在(通过姓名及学号判断)
PStudent_Info stu_find_data_nodelist(char *name, char *number, PStudent_Info head);

//查找教师是否存在(通过姓名及密码判断)
PStudent_Info tec_find_data_nodelist(char *name, char *code, PStudent_Info head);

//学生个人信息显示
bool stu_show_data_nodelist(PStudent_Info p);

//教师个人信息显示
bool tec_show_data_nodelist(PStudent_Info p);

//学生个人信息显示（教师用）
bool tec_stu_show_data_nodelist(PStudent_Info p);

//学生个人信息修改
bool stu_change_data_nodelist(char *name, char *number, PStudent_Info p);

//教师个人信息修改
bool tec_change_data_nodelist(char *name, char *number, PStudent_Info p);

//小结构体转换为大结构体
PStudent_Info change_struct_nodelist(struct list_head *small_list, int num);


//学生成绩修改（教师用）(通过姓名及学号判断)
bool Performance_input_nodelist(char *name, char *number, PStudent_Info head);

//学生成绩查询（教师用）
bool Performance_find_nodelist(PStudent_Info head);

//学生个人成绩查询（学生用）
bool stu_Performance_find_nodelist(char *name, char *number, PStudent_Info head);


//程序结束后(将链表的内容输出到文件中)
bool pagram_exit_inputfile(PStudent_Info head);

//程序开始前（将文件内容放置链表中）
bool pagram_init_outputlist(PStudent_Info head);

//学生节点移除
bool stu_delete_data_nodelist(PStudent_Info p);

//教师节点移除
bool tec_delete_data_nodelist(PStudent_Info p);

//节点查找（管理员通过姓名）
PStudent_Info adm_find_data_nodelist(char *name, int num, PStudent_Info head);


#endif

