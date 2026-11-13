#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>
#include <chrono>
#include  <thread>

#include "clsScreen.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsInputValidate.h"

#include "clsDataProcessing.h"

using namespace std;

class clsShowRoundResultScreen
{

private:
	
	static void _SetWinnerScreenColor(clsDataProcessing::enWHoWinner WhoWinner)
	{
		if (WhoWinner == clsDataProcessing::enWHoWinner::Player1)
			system("color 2F");
		else if (WhoWinner == clsDataProcessing::enWHoWinner::Player2)
		{
			cout << "\a";
			system("color 4F");
		}
		else
			system("color 6F");
	}
	static void _PrintRoundResult(clsDataProcessing& DataProcessing)
	{
		printf("\n|______________________Round[%d]______________________|\n", DataProcessing.RoundNumber);
		cout << "\n  *Player1 Choice : " << clsDataProcessing::ChoiceName(DataProcessing.Player1Choice) << ".\n";
		cout << "\n  *Player2 Choice : " << clsDataProcessing::ChoiceName(DataProcessing.Player2Choice) << ".\n";
		cout << "\n  *Round Winner   : " << DataProcessing.WinnerName << "." << endl;
		cout << "\n|____________________________________________________|\n";
		_SetWinnerScreenColor(DataProcessing.Winner);
	}
public :

	static void ShowRoundResultScreen(clsDataProcessing & DataProcessing)
	{
		_PrintRoundResult(DataProcessing);
	}

};

