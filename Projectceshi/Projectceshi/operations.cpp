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
////记账
void accounting(vector<AccountItem>& items)
{

	char key = readMenuSelection(3);
	switch (key)
	{
	case'1'://收入
		income(items);
		break;
	case '2'://支出
		expand(items);
		break;
	//case '3'://退出
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
	cout << "\n本次收入金额：";
	cin >> item.amount;
	item.amount = readAmount();
	cout << "\n备注：";
	getline(cin, item.detail);
	//添加到	vector
	items.push_back(item);
	insertIntoFile(item);
	cout << "========记账成功=======" << endl;
	cout << "\n请按住回车键返回菜单" << endl;
	string line;
	getline(cin, line);
}


void expand(vector<AccountItem>& items)
{
	AccountItem item;
	item.itemType = EXCOME;
	cout << "\n本次支出金额：";
	cin >> item.amount;
	item.amount = - readAmount();
	cout << "\n备注：";
	getline(cin, item.detail);
	//添加到	vector
	items.push_back(item);
	insertIntoFile(item);
	cout << "========记账成功=======" << endl;
	cout << "\n请按住回车键返回菜单" << endl;
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
////查询
void query(const vector<AccountItem>& items) {
	char key = readMenuSelection(4);
	switch (key)
	{
	case'1'://查询所有账目并总收支
		queryItems(items);

		break;
	case '2'://查询收入，统计总收入
		queryItems(items,INCOME);
		break;
	case '3'://查询支出，统计总支出
		queryItems(items, EXCOME);
		break;//break;
	defaut:
		break;
	}
}
//查询账目功能函数
void queryItems(const vector<AccountItem>& items )
{
	cout << "----------查询结果-----------"<<endl;
	cout << "\n类型\t\t金额\t\t备注\n" <<endl;
	//遍历所有账目
	int total = 0;
	for (auto item : items)
	{
		printItem(item);
		total += item.amount;
	}
	cout << "=====================\n" << endl;
	cout << "总收支：" << total << endl;
	cout << "\n请按住回车键返回菜单" << endl;
	string line;
	getline(cin, line);
}



void queryItems(const vector<AccountItem>& items ,const string& itemType)
{
	cout << "----------查询结果-----------" << endl;
	cout << "\n类型\t\t金额\t\t备注\n" << endl;
	//遍历所有账目
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
	cout << "总收支：" << total << endl;
	cout << "\n请按住回车键返回菜单" << endl;
	string line;
	getline(cin, line);
}



void printItem(const AccountItem& item)
{
	cout << item.itemType << "\t" << item.amount << "\t" << item.detail << endl;
}