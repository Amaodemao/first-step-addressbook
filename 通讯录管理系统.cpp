#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

//封装函数显示菜单界面
void showMenu()
{
	cout << "欢迎使用阿猫的猫通讯录管理系统" << endl;
	cout << "******************************" << endl;
	cout << "*******按1、添加联系人********" << endl;
	cout << "*******按2、显示联系人********" << endl;
	cout << "*******按3、删除联系人********" << endl;
	cout << "*******按4、查找联系人********" << endl;
	cout << "*******按5、修改联系人********" << endl;
	cout << "*******按6、清空联系人********" << endl;
	cout << "*******按0、退出通讯录********" << endl;
	cout << "******************************" << endl;
}

//联系人结构体
struct people
{
	string name;
	string gender;
	string phone;
	string job;
	string address;
};

//通讯录结构体
struct addressbook
{
	struct people addressbookArray[MAX];//通讯录中保存的联系人数组
	int size = 0;//通讯录中当前记录联系人人数 
};

//函数：增加联系人
void add(struct addressbook* a )
{
	if (a->size == MAX)
	{
		cout << "抱歉，该通讯录已满" << endl;
		return;
	}
	else
	{
		cout << "请输入联系人的 姓名 性别 手机号 职业 家庭住址" << endl;
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		a->addressbookArray[a->size].name = name;

		//性别
		int b = 0;
		string gender;
		cout << "请输入性别，1为男性，2为女性" << endl;
		cin >> b;
		if (b == 1)
		{
			gender = "男";
		}
		else if (b == 2)
		{
			gender = "女";
		}
		a->addressbookArray[a->size].gender = gender;
		
		//职业
		string job;
		cout << "请输入职业" << endl;
		cin >> job;
		a->addressbookArray[a->size].job = job;

		//电话
		string phoneNumber;
		cout << "请输入电话号码" << endl;
		cin >> phoneNumber;
		a->addressbookArray[a->size].phone = phoneNumber;

		//住址
		string address;
		cout << "请输入住址" << endl;
		cin >> address;
		a->addressbookArray[a->size].address = address;

		(a->size)++;

		cout << "联系人详细信息如下" << endl;
		cout << "姓名：" << name << endl;
		cout << "性别：" << gender << endl;
		cout << "职业：" << job << endl;
		cout << "电话：" << phoneNumber << endl;
		cout << "地址：" << address << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

//重复函数1
void infoOne(struct addressbook* a, int i)
{
	cout << "性别：" << a->addressbookArray[i].gender << endl;
	cout << "职业：" << a->addressbookArray[i].job << endl;
	cout << "电话：" << a->addressbookArray[i].phone << endl;
	cout << "地址：" << a->addressbookArray[i].address << endl;
}

//函数：显示全部联系人
void showAll(struct addressbook* a)
{
	if (a->size == 0)
	{
		cout << "抱歉，目前通讯录中暂无联系人" << endl;
	}
	else
	{
		cout << "以下为全部联系人：" << endl;
		for (int i = 0; i < (a->size); i++)
		{
			cout << "姓名：" << a->addressbookArray[i].name << endl;
			infoOne(a, i);
			cout << "  " << endl;
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//函数：删除联系人
void deleteOne(struct addressbook* a)
{
	if (a->size == 0)
	{
		cout << "抱歉，目前通讯录中暂无联系人" << endl;
	}
	else
	{
		string name;
		string YesorNo;
		cout << "请输入您想删除的联系人的姓名" << endl;
		cin >> name;
		for (int i = 0; i <= (a->size);i++)
		{
			if (name==a->addressbookArray[i].name)
			{
				FLAG:
				cout << "您确认删除联系人 " << name << " 吗？（Y/N）" << endl;
				cin >> YesorNo;
				if (YesorNo=="Y")
				{
					for (int j = i; j <= (a->size); j++)
					{
						a->addressbookArray[j].name = a->addressbookArray[j + 1].name;
						a->addressbookArray[j].address = a->addressbookArray[j + 1].address;
						a->addressbookArray[j].phone = a->addressbookArray[j + 1].phone;
						a->addressbookArray[j].job = a->addressbookArray[j + 1].job;
						a->addressbookArray[j].gender = a->addressbookArray[j + 1].gender;
					}
					cout << "联系人 " << name << " 已删除" << endl;
					(a->size)--;
					break;
					system("pause");
				}
				else if (YesorNo == "N")
				{
					cout << "联系人 " << name << " 未删除" << endl;
					break;
					system("pause");
				}
				else
				{
					cout << "您的输入有误，请重新输入" << endl;
					goto FLAG;
				}
			}
			else if (i == (a->size))
			{
				cout << "抱歉，查无此人" << endl;
			}
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//函数：查找联系人
void findOne(struct addressbook* a)
{
	if (a->size == 0)
	{
		cout << "抱歉，目前通讯录中暂无联系人" << endl;
	}
	else
	{
		string name;
		
		cout << "请输入您想查找的联系人的姓名" << endl;
		cin >> name;
		for (int i = 0; i <= (a->size); i++)
		{
			if (name == a->addressbookArray[i].name)
			{
				cout << "您查找的联系人 " << name << " 的详细信息如下：" << endl;
				infoOne(a, i);
				break;
			}
			else if (i == (a->size))
			{
				cout << "抱歉，查无此人" << endl;
			}
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//函数：修改联系人
void changeOne(struct addressbook* a)
{

	if (a->size == 0)
	{
		cout << "抱歉，目前通讯录中暂无联系人" << endl;
	}
	else
	{
		string name;
		string gender;
		string job;
		string address;
		string phoneNumber;
		
		int select = 0;
		int b = 0;

		cout << "请输入您想修改的联系人的姓名" << endl;
		cin >> name;
		for (int i = 0; i <= (a->size); i++)
		{
			if (name == a->addressbookArray[i].name)
			{
				cout << "您查找的联系人 " << name << " 的详细信息如下：" << endl;
				infoOne(a, i);
				cout << " " << endl;
				FLAG2:
				cout << "请选择您想修改的信息" << endl;
				cout << "按1：修改姓名" << endl;
				cout << "按2：修改性别" << endl;
				cout << "按3：修改职业" << endl;
				cout << "按4：修改电话" << endl;
				cout << "按5：修改地址" << endl;
				cout << "按0：返回上级菜单" << endl;
				cin >> select;

				switch (select)
				{
				case 0:
					cout << "已返回上级菜单" << endl;
					system("pause");
					system("cls");
					showMenu();
					return;
				case 1:
					cout << "请输入联系人的姓名" << endl;
					cin >> name;
					a->addressbookArray[i].name = name;
					break;
				case 2:
					cout << "请输入联系人的性别，1为男性，2为女性" << endl;
					cin >> b;
					if (b == 1)
					{
						gender = "男";
					}
					else if (b == 2)
					{
						gender = "女";
					}
					a->addressbookArray[i].gender = gender;
					break;
				case 3:
					cout << "请输入联系人的职业" << endl;
					cin >> job;
					a->addressbookArray[i].job = job;
					break;
				case 4:
					cout << "请输入联系人的电话号码" << endl;
					cin >> phoneNumber;
					a->addressbookArray[i].phone = phoneNumber;
					break;
				case 5:
					cout << "请输入联系人的住址" << endl;
					cin >> address;
					a->addressbookArray[i].address = address;
					break;
				default:
					cout << "您的输入有误,请重新选择" << endl;
					goto FLAG2;
				}

				cout << "修改后的联系人详细信息如下" << endl;
				cout << "姓名：" << a->addressbookArray[i].name << endl;
				infoOne(a, i);
				system("pause");
				system("cls");
				showMenu();
				return;
			}
			else if (i == (a->size))
			{
				cout << "抱歉，查无此人" << endl;
			}
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//函数：删除全部联系人
void deleteAll(struct addressbook* a)
{
	string b;
	FLAG3:
	cout << "警告：您确认要删除全部联系人吗？（Y/N）" << endl;
	cin >> b;
	if (b == "Y")
	{
		a->size = 0;
		cout << "通讯录已清空" << endl;
	}
	else if (b == "N")
	{
		cout << "通讯录未清空，已返回上层菜单" << endl;
	}
	else
	{
		cout << "您的输入有误，请重新输入" << endl;
		goto FLAG3;
	}

	system("pause");
	system("cls");
	showMenu();
}

int main()
{
	int selection = 0;
	showMenu();

	//创建通讯录结构体变量
	struct addressbook one;

	//初始化通讯录中当前人员个数
	one.size = 0;

	while (true)
	{
		cin >> selection;

		switch (selection)
		{
		case 0:
			cout << "感谢您使用本系统" << endl;
			return 0;
		case 1:
			add(&one);//利用地址传递，可以修饰实参
			break;
		case 2:
			showAll(&one);
			break;
		case 3:
			deleteOne(&one);
			break;
		case 4:
			findOne(&one);
			break;
		case 5:
			changeOne(&one);
			break;
		case 6:
			deleteAll(&one);
			break;
		}
	}

	system("pause");

	return 0;
}