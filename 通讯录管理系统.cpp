#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

//��װ������ʾ�˵�����
void showMenu()
{
	cout << "��ӭʹ�ð�è��èͨѶ¼����ϵͳ" << endl;
	cout << "******************************" << endl;
	cout << "*******��1�������ϵ��********" << endl;
	cout << "*******��2����ʾ��ϵ��********" << endl;
	cout << "*******��3��ɾ����ϵ��********" << endl;
	cout << "*******��4��������ϵ��********" << endl;
	cout << "*******��5���޸���ϵ��********" << endl;
	cout << "*******��6�������ϵ��********" << endl;
	cout << "*******��0���˳�ͨѶ¼********" << endl;
	cout << "******************************" << endl;
}

//��ϵ�˽ṹ��
struct people
{
	string name;
	string gender;
	string phone;
	string job;
	string address;
};

//ͨѶ¼�ṹ��
struct addressbook
{
	struct people addressbookArray[MAX];//ͨѶ¼�б������ϵ������
	int size = 0;//ͨѶ¼�е�ǰ��¼��ϵ������ 
};

//������������ϵ��
void add(struct addressbook* a )
{
	if (a->size == MAX)
	{
		cout << "��Ǹ����ͨѶ¼����" << endl;
		return;
	}
	else
	{
		cout << "��������ϵ�˵� ���� �Ա� �ֻ��� ְҵ ��ͥסַ" << endl;
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		a->addressbookArray[a->size].name = name;

		//�Ա�
		int b = 0;
		string gender;
		cout << "�������Ա�1Ϊ���ԣ�2ΪŮ��" << endl;
		cin >> b;
		if (b == 1)
		{
			gender = "��";
		}
		else if (b == 2)
		{
			gender = "Ů";
		}
		a->addressbookArray[a->size].gender = gender;
		
		//ְҵ
		string job;
		cout << "������ְҵ" << endl;
		cin >> job;
		a->addressbookArray[a->size].job = job;

		//�绰
		string phoneNumber;
		cout << "������绰����" << endl;
		cin >> phoneNumber;
		a->addressbookArray[a->size].phone = phoneNumber;

		//סַ
		string address;
		cout << "������סַ" << endl;
		cin >> address;
		a->addressbookArray[a->size].address = address;

		(a->size)++;

		cout << "��ϵ����ϸ��Ϣ����" << endl;
		cout << "������" << name << endl;
		cout << "�Ա�" << gender << endl;
		cout << "ְҵ��" << job << endl;
		cout << "�绰��" << phoneNumber << endl;
		cout << "��ַ��" << address << endl;
	}
	system("pause");
	system("cls");
	showMenu();
}

//�ظ�����1
void infoOne(struct addressbook* a, int i)
{
	cout << "�Ա�" << a->addressbookArray[i].gender << endl;
	cout << "ְҵ��" << a->addressbookArray[i].job << endl;
	cout << "�绰��" << a->addressbookArray[i].phone << endl;
	cout << "��ַ��" << a->addressbookArray[i].address << endl;
}

//��������ʾȫ����ϵ��
void showAll(struct addressbook* a)
{
	if (a->size == 0)
	{
		cout << "��Ǹ��ĿǰͨѶ¼��������ϵ��" << endl;
	}
	else
	{
		cout << "����Ϊȫ����ϵ�ˣ�" << endl;
		for (int i = 0; i < (a->size); i++)
		{
			cout << "������" << a->addressbookArray[i].name << endl;
			infoOne(a, i);
			cout << "  " << endl;
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//������ɾ����ϵ��
void deleteOne(struct addressbook* a)
{
	if (a->size == 0)
	{
		cout << "��Ǹ��ĿǰͨѶ¼��������ϵ��" << endl;
	}
	else
	{
		string name;
		string YesorNo;
		cout << "����������ɾ������ϵ�˵�����" << endl;
		cin >> name;
		for (int i = 0; i <= (a->size);i++)
		{
			if (name==a->addressbookArray[i].name)
			{
				FLAG:
				cout << "��ȷ��ɾ����ϵ�� " << name << " �𣿣�Y/N��" << endl;
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
					cout << "��ϵ�� " << name << " ��ɾ��" << endl;
					(a->size)--;
					break;
					system("pause");
				}
				else if (YesorNo == "N")
				{
					cout << "��ϵ�� " << name << " δɾ��" << endl;
					break;
					system("pause");
				}
				else
				{
					cout << "����������������������" << endl;
					goto FLAG;
				}
			}
			else if (i == (a->size))
			{
				cout << "��Ǹ�����޴���" << endl;
			}
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//������������ϵ��
void findOne(struct addressbook* a)
{
	if (a->size == 0)
	{
		cout << "��Ǹ��ĿǰͨѶ¼��������ϵ��" << endl;
	}
	else
	{
		string name;
		
		cout << "������������ҵ���ϵ�˵�����" << endl;
		cin >> name;
		for (int i = 0; i <= (a->size); i++)
		{
			if (name == a->addressbookArray[i].name)
			{
				cout << "�����ҵ���ϵ�� " << name << " ����ϸ��Ϣ���£�" << endl;
				infoOne(a, i);
				break;
			}
			else if (i == (a->size))
			{
				cout << "��Ǹ�����޴���" << endl;
			}
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//�������޸���ϵ��
void changeOne(struct addressbook* a)
{

	if (a->size == 0)
	{
		cout << "��Ǹ��ĿǰͨѶ¼��������ϵ��" << endl;
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

		cout << "�����������޸ĵ���ϵ�˵�����" << endl;
		cin >> name;
		for (int i = 0; i <= (a->size); i++)
		{
			if (name == a->addressbookArray[i].name)
			{
				cout << "�����ҵ���ϵ�� " << name << " ����ϸ��Ϣ���£�" << endl;
				infoOne(a, i);
				cout << " " << endl;
				FLAG2:
				cout << "��ѡ�������޸ĵ���Ϣ" << endl;
				cout << "��1���޸�����" << endl;
				cout << "��2���޸��Ա�" << endl;
				cout << "��3���޸�ְҵ" << endl;
				cout << "��4���޸ĵ绰" << endl;
				cout << "��5���޸ĵ�ַ" << endl;
				cout << "��0�������ϼ��˵�" << endl;
				cin >> select;

				switch (select)
				{
				case 0:
					cout << "�ѷ����ϼ��˵�" << endl;
					system("pause");
					system("cls");
					showMenu();
					return;
				case 1:
					cout << "��������ϵ�˵�����" << endl;
					cin >> name;
					a->addressbookArray[i].name = name;
					break;
				case 2:
					cout << "��������ϵ�˵��Ա�1Ϊ���ԣ�2ΪŮ��" << endl;
					cin >> b;
					if (b == 1)
					{
						gender = "��";
					}
					else if (b == 2)
					{
						gender = "Ů";
					}
					a->addressbookArray[i].gender = gender;
					break;
				case 3:
					cout << "��������ϵ�˵�ְҵ" << endl;
					cin >> job;
					a->addressbookArray[i].job = job;
					break;
				case 4:
					cout << "��������ϵ�˵ĵ绰����" << endl;
					cin >> phoneNumber;
					a->addressbookArray[i].phone = phoneNumber;
					break;
				case 5:
					cout << "��������ϵ�˵�סַ" << endl;
					cin >> address;
					a->addressbookArray[i].address = address;
					break;
				default:
					cout << "������������,������ѡ��" << endl;
					goto FLAG2;
				}

				cout << "�޸ĺ����ϵ����ϸ��Ϣ����" << endl;
				cout << "������" << a->addressbookArray[i].name << endl;
				infoOne(a, i);
				system("pause");
				system("cls");
				showMenu();
				return;
			}
			else if (i == (a->size))
			{
				cout << "��Ǹ�����޴���" << endl;
			}
		}
	}
	system("pause");
	system("cls");
	showMenu();
}

//������ɾ��ȫ����ϵ��
void deleteAll(struct addressbook* a)
{
	string b;
	FLAG3:
	cout << "���棺��ȷ��Ҫɾ��ȫ����ϵ���𣿣�Y/N��" << endl;
	cin >> b;
	if (b == "Y")
	{
		a->size = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else if (b == "N")
	{
		cout << "ͨѶ¼δ��գ��ѷ����ϲ�˵�" << endl;
	}
	else
	{
		cout << "����������������������" << endl;
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

	//����ͨѶ¼�ṹ�����
	struct addressbook one;

	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	one.size = 0;

	while (true)
	{
		cin >> selection;

		switch (selection)
		{
		case 0:
			cout << "��л��ʹ�ñ�ϵͳ" << endl;
			return 0;
		case 1:
			add(&one);//���õ�ַ���ݣ���������ʵ��
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