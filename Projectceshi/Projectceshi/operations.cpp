#include "common.h"
#include "account_item.h"
void loadDataFromFile(vector<AccountItem>& items)
{
	ifstream input(FILENAME);
	AccountItem item;

	while (input >>item.itemType >> item.amount >>item.detail)
	{
		items.push_back(item);
	}
	input.close();
}   

//
//
//
////����
void accounting(vector<AccountItem>& items)
{

	char key = readMenuSelection(3);
	switch (key)
	{
	case'1'://����
		income(items);
		break;
	case '2'://֧��
		expand(items);
		break;
	//case '3'://�˳�
		//break;
	default:
		break;
	}
	cout << endl;
}


void income(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = INCOME;
	cout << "\n���������";
	cin >> item.amount;
	item.amount = readAmount();
	cout << "\n��ע��";
	getline(cin, item.detail);
	//��ӵ�	vector
	items.push_back(item);
	insertIntoFile(item);
	cout << "========���˳ɹ�=======" << endl;
	cout << "\n�밴ס�س������ز˵�" << endl;
	string line;
	getline(cin, line);
}


void expand(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = EXCOME;
	cout << "\n����֧����";
	cin >> item.amount;
	item.amount = - readAmount();
	cout << "\n��ע��";
	getline(cin, item.detail);
	//��ӵ�	vector
	items.push_back(item);
	insertIntoFile(item);
	cout << "========���˳ɹ�=======" << endl;
	cout << "\n�밴ס�س������ز˵�" << endl;
	string line;
	getline(cin, line);
}


void insertIntoFile(const AccountItem& item)
{
	ofstream output(FILENAME, ios::out | ios::app);
	output << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
	output.close();
}
//
// 
// 
// 

//
////��ѯ
void query(const vector<AccountItem>& items) {
	char key = readMenuSelection(4);
	switch (key)
	{
	case'1'://��ѯ������Ŀ������֧
		queryItems(items);

		break;
	case '2'://��ѯ���룬ͳ��������
		queryItems(items,INCOME);
		break;
	case '3'://��ѯ֧����ͳ����֧��
		queryItems(items, EXCOME);
		break;//break;
	defaut:
		break;
	}
}
//��ѯ��Ŀ���ܺ���
void queryItems(const vector<AccountItem>& items )
{
	cout << "----------��ѯ���-----------"<<endl;
	cout << "\n����\t\t���\t\t��ע\n" <<endl;
	//����������Ŀ
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}
	cout << "=====================\n" << endl;
	cout << "����֧��" << total << endl;
	cout << "\n�밴ס�س������ز˵�" << endl;
	string line;
	getline(cin, line);
}



void queryItems(const vector<AccountItem>& items ,const string& itemType)
{
	cout << "----------��ѯ���-----------" << endl;
	cout << "\n����\t\t���\t\t��ע\n" << endl;
	//����������Ŀ
	int total = 0;
	for (auto item : items)
	{

		if (item.itemType == itemType)
		{
			printItem(item);
			total += item.amount;

		}
		printItem(item);
		total += item.amount;
	}
	cout << "=====================\n" << endl;
	cout << "����֧��" << total << endl;
	cout << "\n�밴ס�س������ز˵�" << endl;
	string line;
	getline(cin, line);
}



void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}