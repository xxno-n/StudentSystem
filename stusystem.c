/********************************************************************
  > File Name: stusystem.c
  > Author: xiening
  > Mail:  1606598696@qq.com  
  > Created Time: 2020年01月15日 星期三 17时27分35秒
 *******************************************************************/

#include "stusystem.h"

//初始化双向内核链表
PStudent_Info init_dou_kel_nodelist()
{
	PStudent_Info head = calloc(1, sizeof(Student_Info));
	if(NULL == head)
	{
		printf("init error\n");
		return NULL;
	}

	//指针域自己指向自己
	head->small_list1.prev = &(head->small_list1);
	head->small_list1.next = &(head->small_list1);
	head->small_list2.prev = &(head->small_list2);
	head->small_list2.next = &(head->small_list2);
	head->small_list3.prev = &(head->small_list3);
	head->small_list3.next = &(head->small_list3);

	return head;

}
//教师个人信息创建
PStudent_Info tec_create_dou_kel_nodelist()
{
	PStudent_Info new_node = calloc(1, sizeof(Student_Info));
	if(NULL == new_node)
	{
		printf("create error\n");
		return NULL;
	}

	//指针域自己指向自己
	new_node->small_list2.prev = &(new_node->small_list2);
	new_node->small_list2.next = &(new_node->small_list2);

	//填写个人信息：
	char buf[128] = {0};
	printf("填写个人信息：\n姓名-性别-出生年月\r\n");
	scanf("%s", buf);
	sscanf(buf, "%[^-]-%[^-]-%[^-]", 
			new_node->name, new_node->sex, new_node->age);
	printf("\n填写登录密码：\n");
	scanf("%s", new_node->secret);
	return new_node;
}

//学生个人信息创建
PStudent_Info create_dou_kel_nodelist()
{
	PStudent_Info new_node = calloc(1, sizeof(Student_Info));
	if(NULL == new_node)
	{
		printf("create error\n");
		return NULL;
	}

	//指针域自己指向自己
	new_node->small_list1.prev = &(new_node->small_list1);
	new_node->small_list1.prev = &(new_node->small_list1);

	//填写个人信息：
	char buf[128] = {0};
	printf("填写个人信息：\n姓名-学号-性别-出生年月\r\n");
	scanf("%s", buf);
	sscanf(buf, "%[^-]-%[^-]-%[^-]-%[^ ]", 
			new_node->name, new_node->number, new_node->sex, new_node->age);
	return new_node;
}


//教师个人信息头插入
bool tec_head_data_nodelist(PStudent_Info p, PStudent_Info head)
{
	if(NULL == p || NULL == head)
	{
		printf("add data error\n");
		return false;
	}
	//第一次插入：
	if(head->small_list2.next == &(head->small_list2))
	{
		//教师链表
		head->small_list2.next = &(p->small_list2);
		head->small_list2.prev = &(p->small_list2);
		p->small_list2.prev = &(head->small_list2);
		p->small_list2.next = &(head->small_list2);
		return true;
	}
	
	//第二次或以后插入：
	//教师链表
	p->small_list2.prev = &(head->small_list2);
	p->small_list2.next = head->small_list2.next;
	(head->small_list2.next)->prev = &(p->small_list2);
	head->small_list2.next = &(p->small_list2);
	return true;
}

//学生个人信息头插入
bool stu_head_data_nodelist(PStudent_Info p, PStudent_Info head)
{
	if(NULL == p || NULL == head)
	{
		printf("add data error\n");
		return false;
	}
	

	//第一次插入：
	if(head->small_list1.next == &(head->small_list1))
	{
		//printf("第一次插入\n");
		//学生链表
		head->small_list1.next = &(p->small_list1);
		head->small_list1.prev = &(p->small_list1);
		p->small_list1.prev = &(head->small_list1);
		p->small_list1.next = &(head->small_list1);

		return true;
	}
	
	//第二次或以后插入：
	//学生链表
	//printf("第二次插入\n");
	p->small_list1.prev = &(head->small_list1);
	p->small_list1.next = head->small_list1.next;
	(head->small_list1.next)->prev = &(p->small_list1);
	head->small_list1.next = &(p->small_list1);
	return true;
}




//学生个人信息显示
bool stu_show_data_nodelist(PStudent_Info p)
{
	if(NULL == p)
	{
		printf("show data error\n");
		return false;
	}
	
	printf("  \t姓名\t学号\t性别\t出生年月\n");
	printf("  \t%s\t%s\t%s\t%s\n", 
			p->name, p->number,
			p->sex, p->age);
	return true;
}

//教师个人信息显示
bool tec_show_data_nodelist(PStudent_Info p)
{
	if(NULL == p)
	{
		printf("show data error\n");
		return false;
	}
	
	printf("  \t姓名\t性别\t出生年月\n");
	printf("  \t%s\t%s\t%s\n", 
			p->name,p->sex, p->age);
	return true;
}

//学生个人信息修改
bool stu_change_data_nodelist(char *name, char *number, PStudent_Info p)
{
	if(NULL == p)
	{
		printf("show data error\n");
		return false;
	}
	//填写个人信息：
	char buf[128] = {0};
	printf("修改您的个人信息：\n姓名-学号-性别-出生年月\r\n");
	scanf("%s", buf);
	sscanf(buf, "%[^-]-%[^-]-%[^-]-%[^ ]", 
			p->name, p->number, p->sex, p->age);
	strcpy(name, p->name);
	strcpy(number, p->number);
	printf("\n修改个人信息成功\n");
	return true;

}

//教师个人信息修改
bool tec_change_data_nodelist(char *name, char *number, PStudent_Info p)
{
	if(NULL == p)
	{
		printf("show data error\n");
		return false;
	}
	//填写个人信息：
	char buf[128] = {0};
	printf("修改您的个人信息：\n姓名-性别-出生年月\r\n");
	scanf("%s", buf);
	sscanf(buf, "%[^-]-%[^-]-%[^-]", 
			p->name, p->sex, p->age);
	strcpy(name, p->name);
	strcpy(number, p->number);
	printf("\n修改个人信息成功\n");
	return true;
}

//小结构体转换为大结构体
PStudent_Info change_struct_nodelist(struct list_head *small_list, int num)
{
	if(NULL == small_list)
	{
		printf("change error\n");
		return NULL;
	}
	PStudent_Info p = NULL;
	switch(num)
	{
		case Student:
			p = (PStudent_Info)((char*)small_list -
		   		(unsigned long)&(((PStudent_Info)0)->small_list1));
			return p;break;
		case Teacher:
			p = (PStudent_Info)((char*)small_list -
		   		(unsigned long)&(((PStudent_Info)0)->small_list2));
			return p;break;
		case Administrator:
			p = (PStudent_Info)((char*)small_list -
		   		(unsigned long)&(((PStudent_Info)0)->small_list3));
			return p;break;
		default:
			printf("change error\n");
			return NULL;
	}

}

//查找学生是否存在(通过姓名及学号判断)
PStudent_Info stu_find_data_nodelist(char *name, char *number, PStudent_Info head)
{
	if(NULL == head)
	{
		printf("addr error\n");
		return NULL;
	}

	struct list_head *p = head->small_list1.next;
	PStudent_Info pos = NULL;
	//循环遍历
	while(p != &(head->small_list1))
	{
		pos = change_struct_nodelist(p, 1);
		if(0 == strcmp(pos->name, name) && 0 == strcmp(pos->number, number))
		{
			//printf("find succeed\n");
			return pos;
		}
		p = p->next;
	}
	return NULL;

}

//查找教师是否存在(通过姓名及密码判断)
PStudent_Info tec_find_data_nodelist(char *name, char *secret, PStudent_Info head)
{
	if(NULL == head)
	{
		printf("addr error\n");
		return NULL;
	}

	struct list_head *p = head->small_list2.next;
	PStudent_Info pos = NULL;
	//循环遍历
	while(p != &(head->small_list2))
	{
		pos = change_struct_nodelist(p, 2);
		if(0 == strcmp(pos->name, name) && 0 == strcmp(pos->secret, secret))
		{
			//printf("find succeed\n");
			return pos;
		}
		p = p->next;
	}
	return NULL;
}

//学生成绩修改（教师用）(通过姓名及学号判断)
bool Performance_input_nodelist(char *name, char *number, PStudent_Info head)
{
	PStudent_Info p = stu_find_data_nodelist(name, number, head);
	if(NULL == p)
	{
		printf("\n不存在此学生用户\n");
		return false;
	}
	//填写学生成绩：
	char buf[128] = {0};
	char Math[4] = {0};
	char Maogai[4] = {0};
	char English[4] = {0};
	char C_languague[4] = {0};
	printf("填写 %s学生成绩：\n高数-毛概-英语-C语言\r\n", p->name);
	scanf("%s", buf);
	sscanf(buf, "%[^-]-%[^-]-%[^-]-%[^ ]", 
			Math, Maogai, English, C_languague);
	p->result.Math = atoi(Math);
	p->result.Maogai = atoi(Maogai);
	p->result.English = atoi(English);
	p->result.C_languague = atoi(C_languague);
	return true;

}

//学生成绩查询（教师用）
bool Performance_find_nodelist(PStudent_Info head)
{
	if(NULL == head)
	{
		return false;
	}
	struct list_head *p = head->small_list1.next;
	PStudent_Info pos = NULL;
	double aver;
	printf("  \t学生姓名 高数\t毛概\t英语\tC语言\t平均分\r\n");
	//循环遍历
	while(p != &(head->small_list1))
	{
		pos = change_struct_nodelist(p, 1);
		aver = (pos->result.Math + pos->result.Maogai+
			pos->result.English + pos->result.C_languague)/(double)4;
		printf("\n  \t%s\t%d\t%d\t%d\t%d\t%0.2lf\r\n", pos->name,
			pos->result.Math, pos->result.Maogai,
			pos->result.English, pos->result.C_languague, aver);
		p = p->next;
	}

	
	return true;

}

//学生个人信息查询（教师用）
bool tec_stu_show_data_nodelist(PStudent_Info head)
{
	if(NULL == head)
	{
		return false;
	}
	struct list_head *p = head->small_list1.next;
	PStudent_Info pos = NULL;
	printf("  \t学生姓名 学号\t性别\t出生年月\r\n");
	//循环遍历
	while(p != &(head->small_list1))
	{
		pos = change_struct_nodelist(p, 1);
		printf("\n  \t%s\t%s\t%s\t%s\r\n", 
			pos->name, pos->number,
			pos->sex, pos->age);
		p = p->next;
	}

	
	return true;
}

//学生个人成绩查询（学生用）
bool stu_Performance_find_nodelist(char *name, char *number, PStudent_Info head)
{
	PStudent_Info p = stu_find_data_nodelist(name, number, head);
	if(NULL == p)
	{
		return false;
	}
	printf("  \t高数\t毛概\t英语\tC语言\r\n");
	printf("  \t%d\t%d\t%d\t%d\r\n",
		p->result.Math, p->result.Maogai,
		p->result.English, p->result.C_languague);
	return true;
}



//程序结束后(将链表的内容输出到文件中)
bool pagram_exit_inputfile(PStudent_Info head)
{
	//判断是否为空
	if(NULL == head)
	{
		printf("save File error\n");
		return false;
	}
	PStudent_Info pos = NULL;
	struct list_head *p = head->small_list1.next;
	struct list_head *p1 = NULL;
	char buf[128] = {0};

	//保存学生信息：
	//打开文件(打开方式为清空内容后再打开)
	FILE *fp = fopen("./data.txt", "w+");
	if(NULL == fp)
	{
		perror("fopen error\n");
		return false;
	}

	//遍历每读取一个就保存一个，然后删除
	while(p != &(head->small_list1))
	{
		pos = change_struct_nodelist(p, 1);
		p1 = p->next;
		sprintf(buf, "%s-%s-%s-%s-%d-%d-%d-%d\n",
			pos->name, pos->number, pos->sex, pos->age,
			pos->result.Math, pos->result.Maogai,
			pos->result.English, pos->result.C_languague);
		//printf("%s", buf);
		fwrite(buf, 1, strlen(buf), fp);
		free(pos);
		p = p1;

	}

	//关闭文件
	fclose(fp);
	fp = NULL;


	//保存教师信息：
	FILE *fp1 = fopen("./data1.txt", "w+");
	if(NULL == fp1)
	{
		perror("fopen error\n");
		return false;
	}
	p = head->small_list2.next;

	char buf1[128] = {0};
	//遍历每读取一个就保存一个，然后删除
	while(p != &(head->small_list2))
	{
		pos = change_struct_nodelist(p, 2);
		p1 = p->next;
		sprintf(buf1, "%s-%s-%s-%s\n",
			pos->name, pos->sex, pos->age, pos->secret);
		//printf("%s", buf1);
		fwrite(buf1, 1, strlen(buf1), fp1);
		free(pos);
		p = p1;

	}

	//关闭文件
	printf("\n学生信息管理系统已退出\n");
	fclose(fp1);
	fp1 = NULL;

	return true;


}


//程序开始前（将文件内容放置链表中）
bool pagram_init_outputlist(PStudent_Info head)
{
	
	//学生信息的：
	//打开文件(打开方式为只读)
	FILE *fp = fopen("./data.txt", "r");
	if(NULL == fp)
	{
		perror("fopen error\n");
		return false;
	}

	//插入链表中
	int size;
	char buf[128];
	char *buf1;
	char Math[4] = {0};
	char Maogai[4] = {0};
	char English[4] = {0};
	char C_languague[4] = {0};
	size = fread(buf,1, 128, fp);
	if(size < 2)
	{
		printf("data is NULL\n");
		goto label;
	}

	buf[size] = '\0';
	
	buf1 = strtok(buf, "\n");
	
	do
	{
		//printf("%s", buf1);
		//scanf("%d", &size);
		PStudent_Info p = calloc(1, sizeof(Student_Info));
		sscanf(buf1, "%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%[^-]-%s", 
			p->name, p->number, p->sex, p->age,
			Math, Maogai, English, C_languague);
		p->result.Math = atoi(Math);
		p->result.Maogai = atoi(Maogai);
		p->result.English = atoi(English);
		p->result.C_languague = atoi(C_languague);
		stu_head_data_nodelist(p, head);
		buf1 = strtok(NULL, "\n");
	}while(NULL != buf1);
	

label:	
	fclose(fp);
	fp = NULL;

	//教师信息的：
	//打开文件(打开方式为只读)
	fp = fopen("./data1.txt", "r");

	if(NULL == fp)
	{
		perror("fopen error\n");
		return false;
	}

	//插入链表中
	char secret[20] = {0};
	size = fread(buf, 1, 128, fp);
	if(size < 2)
	{
		return false;
	}
	buf[size] = '\0';
	buf1 = strtok(buf, "\n");

	do
	{
		//printf("%s", buf1);
		//scanf("%d", &size);
		PStudent_Info p1 = calloc(1, sizeof(Student_Info));
		sscanf(buf, "%[^-]-%[^-]-%[^-]-%s", 
			p1->name, p1->sex, p1->age, p1->secret);
		tec_head_data_nodelist(p1, head);
		buf1 = strtok(NULL, "\n");
	}while(NULL != buf1);

	fclose(fp);
	fp = NULL;

	return true;
	

}

//学生节点移除
bool stu_delete_data_nodelist(PStudent_Info p)
{
	if(NULL == p || NULL == p)
	{
		printf("delete error\n");
		return false;
	}

	struct list_head *pos = &(p->small_list1);

	//排除头结点
	if(pos->next == pos)
	{
		printf("delete error\n");
		return false;
	}

	//修改链表
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(p);
	p = NULL;
	return true;

}


//教师节点移除
bool tec_delete_data_nodelist(PStudent_Info p)
{
	if(NULL == p || NULL == p)
	{
		printf("delete error\n");
		return false;
	}

	struct list_head *pos = &(p->small_list2);

	//排除头结点
	if(pos->next == pos)
	{
		printf("delete error\n");
		return false;
	}

	//修改链表
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	free(p);
	p = NULL;
	return true;

}

//节点查找（管理员通过姓名）
PStudent_Info adm_find_data_nodelist(char *name, int num, PStudent_Info head)
{

	if(NULL == head)
	{
		printf("addr error\n");
		return NULL;
	}

	//学生查找
	if(1 == num)
	{
		struct list_head *p = head->small_list1.next;
		PStudent_Info pos = NULL;
		//循环遍历
		while(p != &(head->small_list1))
		{
			pos = change_struct_nodelist(p, 1);
			if(0 == strcmp(pos->name, name))
			{
				//printf("find succeed\n");
				return pos;
			}
			p = p->next;
		}
	}

	//教师查找
	if(2 == num)
	{
		struct list_head *p = head->small_list2.next;
		PStudent_Info pos = NULL;
		//循环遍历
		while(p != &(head->small_list2))
		{
			pos = change_struct_nodelist(p, 2);
			if(0 == strcmp(pos->name, name))
			{
				//printf("find succeed\n");
				return pos;
			}
			p = p->next;
		}
	}
	
	return NULL;

}