/*
AK ewen tool
Ver. 0.1.0
------------------------------------------------
Author:
	hanyuchen2019 (Luogu uid=277757)
Modifier:
	_Shu          (Luogu uid=556013) (0.0.4)
	_��������ռ��_(Luogu uid=370281) (0.1.0)
Thanks for their help!
------------------------------------------------
Update:
1.����ȱʡԴ�Զ����빦�� 
2.�޸�ĳ����bug
3.�޸�cls������ֱ�ӵ���main()�� 
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
			puts("�����ָ������");	
	}
}
bool caozuo_run(int lx)
{
	string str;
	char ch;
	switch(lx)
	{
		case 1://help
			puts("---�����б�---");
			puts("help �鿴�����б�");
			puts("cls ����");
			puts("exit �˳�");
			puts("set �����йر�������Ϣ����data�ļ�·����ȱʡԴ·��");
			puts("create ���ݴ������Զ�������Ŀ�������ȱʡԴ");
			break;
		case 2://cls
			system("cls");
			main();
			break;
		case 3://exit
			all_end=true;
			return 0;
		case 4://set
			puts("��ǰ������Ϣ:");
			cout<<"  ������·��   : "<<data_lujing<<'\n';
			cout<<"  ȱʡԴ·��   : "<<qs_lujing<<'\n';
			puts("�Ƿ��޸ģ�Y/N");
			ch=getch();
			if(ch=='Y'||ch=='y')
			{
				cout<<"������������ľ���·��:";
				getline(cin,data_lujing);
				cout<<"������ȱʡԴ�ľ���·��:";
				getline(cin,qs_lujing);
			}
			break;
		case 5://create
			find_problem();
			if(pro_cnt)
			{
				create_code();
				printf("���봴���ɹ����ҵ���%d����Ŀ\n",pro_cnt);
				for(int i=1;i<=pro_cnt;++i)
					cout<<" "<<i<<" : "<<problem[i]<<'\n';
				if(qs_lujing!="NaN")push_qx();
			}
			else
			{
				puts("���봴��ʧ��");
				if(data_lujing=="NaN")
					puts("��ʹ��set����ָ��������·�����Դ������롣");
			}
			break;
		default:
			puts("�����caozuo_run()ը��");
			break; 
	}
}
void find_problem()//�˺����� _Shu ������� 
{
	if(data_lujing=="NaN")return;
    system(("dir "+data_lujing+"/B  > buffer.txt").c_str());
    ifstream fin("buffer.txt");
	string s;
	for(pro_cnt=0;fin>>s;)
	{
		if(s=="gmon.out")continue;
		char ch=s[s.length()-1];
		if(ch=='n')continue;//xxx.in ���� 
		else
		{
			s[s.length()-1]='p';
			s[s.length()-2]='p';// .out/.ans �滻Ϊ .cpp 
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
void push_qx()//�˺����� _��������ռ��_ ������� 
{
	for(int i=1;i<=pro_cnt;++i)
		system(("copy "+qs_lujing+" "+problem[i]+" > buffer.txt").c_str());
	puts("ȱʡԴ���ɹ���");
}
int main()
{
	system(("title AK ewen tool ("+banben+")").c_str());
	puts(("----------------------------AK ewen tool ("+banben+")----------------------------").c_str());
	puts("��������̨ (����help�鿴ָ���б�)");
	jiaohu();
	return 0;
}

