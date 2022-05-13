/*
AK ewen tool
Ver. 0.1.0
------------------------------------------------
Author:
	hanyuchen2019 (Luogu uid=277757)
Modifier:
	_Shu          (Luogu uid=556013) (0.0.4)
	_该名称已占用_(Luogu uid=370281) (0.1.0)
Thanks for their help!
------------------------------------------------
Update:
1.增加缺省源自动导入功能 
2.修改某弱智bug
3.修改cls函数（直接调用main()） 
*/
#pragma GCC optimize(2)
#include<iostream>
#include<fstream>
#include<cstdio>
#include<windows.h>
#include<conio.h>

using namespace std;

int jiaohu(void);
bool caozuo_run(int lx);
void find_problem(void);
void create_code(void);
void push_qx(void);
int main(void); 

bool all_end=false;
int max_caozuo=5;
string caozuo[]={"","help","cls","exit","set","create"};
//                    1      2     3      4       5
string data_lujing="NaN";
string qs_lujing="NaN";
string banben="Ver 0.1.0";

string problem[10];
int pro_cnt=0;

int jiaohu()
{
	bool found;
	while(!all_end)
	{
		found=0;
		printf(">>>");
		string s;
		getline(cin,s);
		for(int i=1;i<=max_caozuo;++i)
		{
			if(s==caozuo[i])
			{
				found=1;
				caozuo_run(i);
				if(i!=2&& (!all_end))puts("--------------");
				break;
			}
		}
		if(found==0)
			puts("输入的指令有误。");	
	}
}
bool caozuo_run(int lx)
{
	string str;
	char ch;
	switch(lx)
	{
		case 1://help
			puts("---操作列表---");
			puts("help 查看操作列表");
			puts("cls 清屏");
			puts("exit 退出");
			puts("set 配置有关比赛的信息，如data文件路径，缺省源路径");
			puts("create 根据大样例自动创建题目，并填充缺省源");
			break;
		case 2://cls
			system("cls");
			main();
			break;
		case 3://exit
			all_end=true;
			return 0;
		case 4://set
			puts("当前配置信息:");
			cout<<"  大样例路径   : "<<data_lujing<<'\n';
			cout<<"  缺省源路径   : "<<qs_lujing<<'\n';
			puts("是否修改？Y/N");
			ch=getch();
			if(ch=='Y'||ch=='y')
			{
				cout<<"请输入大样例的绝对路径:";
				getline(cin,data_lujing);
				cout<<"请输入缺省源的绝对路径:";
				getline(cin,qs_lujing);
			}
			break;
		case 5://create
			find_problem();
			if(pro_cnt)
			{
				create_code();
				printf("代码创建成功，找到了%d个题目\n",pro_cnt);
				for(int i=1;i<=pro_cnt;++i)
					cout<<" "<<i<<" : "<<problem[i]<<'\n';
				if(qs_lujing!="NaN")push_qx();
			}
			else
			{
				puts("代码创建失败");
				if(data_lujing=="NaN")
					puts("请使用set命令指定大样例路径，以创建代码。");
			}
			break;
		default:
			puts("程序的caozuo_run()炸了");
			break; 
	}
}
void find_problem()//此函数由 _Shu 帮助完成 
{
	if(data_lujing=="NaN")return;
    system(("dir "+data_lujing+"/B  > buffer.txt").c_str());
    ifstream fin("buffer.txt");
	string s;
	for(pro_cnt=0;fin>>s;)
	{
		if(s=="gmon.out")continue;
		char ch=s[s.length()-1];
		if(ch=='n')continue;//xxx.in 跳过 
		else
		{
			s[s.length()-1]='p';
			s[s.length()-2]='p';// .out/.ans 替换为 .cpp 
			s[s.length()-3]='c';
			problem[++pro_cnt]=s;
		}
	}
	fin.close();
}
void create_code()
{
	for(int i=1;i<=pro_cnt;++i)
	{
		string str="cd.> "+problem[i];
		system(str.c_str());
	}
}
void push_qx()//此函数由 _该名称已占用_ 帮助完成 
{
	for(int i=1;i<=pro_cnt;++i)
		system(("copy "+qs_lujing+" "+problem[i]+" > buffer.txt").c_str());
	puts("缺省源填充成功。");
}
int main()
{
	system(("title AK ewen tool ("+banben+")").c_str());
	puts(("----------------------------AK ewen tool ("+banben+")----------------------------").c_str());
	puts("交互控制台 (输入help查看指令列表)");
	jiaohu();
	return 0;
}

