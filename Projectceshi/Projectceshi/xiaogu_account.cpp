#include"common.h"
#include"account_item.h"
int main()
{
	vector<AccountItem> items;
	loadDataFromFile(items);
	bool quit = false;
	while (!quit)
	{
		showMainMenu();
		char key = readMenuSelection(3);
		switch (key)
		{
		case'1':showAccountingMenu();
	   	    accounting(items);
			break;
    	case '2':showQueryMenu();
    		query(items);
			break;
		case '3':
			cout << "\n�Ƿ�ȷ���˳��� ��y/n):";
			if (readQuitConfirm() == 'Y')
				quit = true;
			break;
		defaut :
			break;
		}
		cout << endl;
    }

}