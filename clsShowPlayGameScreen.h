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
#include "clsShowRoundResultScreen.h"
using namespace std;

class clsShowPlayGameScreen:protected clsScreen
{

private:
	static void _PrintPlayersInfoCard(clsDataProcessing& DataProcessing)
	{
		system("cls");
		cout << "\n\t\t\t\t\t|                       [ Get Ready ]                       |";
		cout << "\n\t\t\t\t\t|_____________________________|_____________________________|\n";
		cout << "\t\t\t\t\t|                             |                             |\n";
		cout << "\t\t\t\t\t| Player[1] : " << left << setw(15) << DataProcessing.Player1Name << " | " << "Player[2] : " << left << setw(16) << DataProcessing.Player2Name << "|" << endl;
		cout << "\t\t\t\t\t| Age       : " << left << setw(15) << DataProcessing.Player1Age << " | " << "Age       : " << left << setw(16) << DataProcessing.Player2Age << "|" << endl;
		cout << "\t\t\t\t\t|_____________________________|_____________________________|\n\n";
		cout << "\t\t\t\t\t| Date   : " << clsDate::DateToString(clsDate()) << "\t\t\t\t\t    |\n";
		cout << "\t\t\t\t\t| Rounds : " << DataProcessing.HowManyRounds << "\t\t\t\t\t\t    |" << endl;
		cout << "\n\n";
	}

	static clsDataProcessing::enGameChoice _ReadPlayerChoice(short NumberOfPlayer)
	{
		
		printf("\n Player[%d]:\n", NumberOfPlayer);
		cout << "\n Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? => ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 3);
		return (clsDataProcessing::enGameChoice)Choice;
	}
	static clsDataProcessing::enGameChoice _GetComputerChoice()
	{
		return (clsDataProcessing::enGameChoice)clsUtil::RandomNumber(1, 3);
	}
	static clsDataProcessing::enGameChoice _ReadComputerChoice()
	{
		cout << "\n Player[2]:\n";
		cout << "\n Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? => ";
		return  _GetComputerChoice();
	}
	static void _EnterChoices(clsDataProcessing& DataProcessing)
	{
		if (DataProcessing.WhoPlayingWith == clsDataProcessing::enWhoPlayingWith::AnotherPlayer)
		{
			DataProcessing.Player1Choice = _ReadPlayerChoice(1);
			DataProcessing.Player2Choice = _ReadPlayerChoice(2);
		}
		else
		{
			DataProcessing.Player1Choice = _ReadPlayerChoice(1);
			DataProcessing.Player2Choice = _ReadComputerChoice();
			cout << DataProcessing.Player2Choice << endl;
		}
	}
	static void _CheckWhoWonThRound(clsDataProcessing& DataProcessing)
	{

		DataProcessing.Winner = clsDataProcessing::WhoWonTheRound(DataProcessing);
		DataProcessing.WinnerName = DataProcessing.Winner_Name(DataProcessing.Winner);
		DataProcessing.IncreaseWinAndDrawCounters(DataProcessing.Winner);
	}
public:

	static void ShowPlayGameScreen(clsDataProcessing &DataProcessing)
	{
		_PrintPlayersInfoCard(DataProcessing);
		for (short GameRound = 1;GameRound <= DataProcessing.HowManyRounds;GameRound++)
		{
			DataProcessing.RoundNumber = GameRound;
			_DrawScreenHeader("\t\tRound ["+to_string(GameRound)+"] Begins.");
			_EnterChoices(DataProcessing);
			_CheckWhoWonThRound(DataProcessing);
			clsShowRoundResultScreen::ShowRoundResultScreen(DataProcessing);
		}
	}
};

