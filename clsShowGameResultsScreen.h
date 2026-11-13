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

class clsShowGameResultsScreen
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
	static void _ShowGameOverScreen()
	{
		cout << "\n\n" << clsUtil::Tabs(5) << "--------------------------------------------------------";
		cout << "\n\n" << clsUtil::Tabs(5) << "              +++ G a m e  O v e r +++                       ";
		cout << "\n\n" << clsUtil::Tabs(5) << "--------------------------------------------------------\n";
	}
	static void _ShowFinalGameResults(clsDataProcessing DataProcessing)
	{
		DataProcessing.GameWinner = clsDataProcessing::WhoWonTheGame(DataProcessing);
		DataProcessing.WinnerName = DataProcessing.Winner_Name(DataProcessing.GameWinner);

		cout << "\n"   << clsUtil::Tabs(5) << "|____________________[ Game Results ]___________________|";
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Geme Rounds          : " << DataProcessing.HowManyRounds;
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Player1 won times    : " << DataProcessing.Player1WonTimes;
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Player2 won times    : " << DataProcessing.Player2WonTimes;
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Draw times           : " << DataProcessing.DrawTimes;
		cout << "\n\n" << clsUtil::Tabs(5) << "   * Final Winner         : " << DataProcessing.WinnerName;
		cout << "\n\n" << clsUtil::Tabs(5) << "|______________________________________________________|\n";
		_SetWinnerScreenColor(DataProcessing.GameWinner);

	}

public :

	static void ShowGameResultsScreen(clsDataProcessing DataProcessing)
	{
		_ShowGameOverScreen();
		_ShowFinalGameResults(DataProcessing);
	}


};

