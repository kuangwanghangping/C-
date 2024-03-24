#pragma once
#include "common.h"
struct AccountItem
{
	string itemType;
	int amount;
	string detail;
};	
void loadDataFromFile(vector<AccountItem> &items);
//
//
//
////º«’À
void accounting(vector<AccountItem> &items);
void insertIntoFile(const AccountItem& item);
//
//
////≤È—Ø
//void query(const vector<AccountItem>& items);

void expand(vector<AccountItem>& items);
void income(vector<AccountItem>& items);
void query(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items);
void queryItems(const vector<AccountItem>& items, const string& itemType);
void printItem(const AccountItem& item);
