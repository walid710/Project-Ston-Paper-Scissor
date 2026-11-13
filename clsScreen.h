#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

#include "clsDate.h"
#include "clsDataProcessing.h"
using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\n\n" << clsUtil::Tabs(5) << "===============================================\n";
		cout  << clsUtil::Tabs(5) << Title;
		if (SubTitle != "")
		{
			cout << "\n" << clsUtil::Tabs(5) << SubTitle;
		}
		cout << "\n" << clsUtil::Tabs(5) << "===============================================\n\n";
		cout << clsUtil::Tabs(5) << "Date: "<< clsDate::DateToString(clsDate());	
		cout <<"\n\n";
	}
	
public:

};

