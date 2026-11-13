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
#include "clsInputValidate.h"

#include "clsDataProcessing.h"
#include "clsShowPlayGameScreen.h"
#include "clsShowGameResultsScreen.h"
using namespace std;

class clsShowGameStarScreen:protected clsScreen
{
private:
	struct stDate
	{
		string FirstName;
		short Age;
	};
	
	//-------------------------------------------------------------------------
	static clsDataProcessing::enWhoPlayingWith _ReadWhoPlayingWith()
	{
		cout << "\nPlease Choose who do you want to Play With? [1]:Another Player ,[2]:Computer. => ";
		short Choice= clsInputValidate::ReadShortNumberBetween(1, 2);
		return (clsDataProcessing::enWhoPlayingWith)Choice;
	}
	static short _ReadHowManyRounds()
	{
		cout << "\nHow Many Rounds To Playing [1:10] => ";
		short Choice= clsInputValidate::ReadShortNumberBetween(1, 10);
		return Choice;
	}
	static stDate _ReadFirstNameAndAgeOfEachPlayers(short PlayerNumber)
	{
		stDate Data;
		printf("\nPlayer:[%d]\n", PlayerNumber);
		cout << "\nPlease enter your Firts Name? => ";
		Data.FirstName= clsInputValidate::ReadString();
		cout << "\nPlease enter your Age? => ";
		Data.Age= clsInputValidate::ReadShortNumber();
		return Data;

	}
	//-------------------------------------------------------------------------
	static void _ReadPlayersDatat(clsDataProcessing &DataProcessing)
	{
		_DrawScreenHeader("   Welcome to Game [Ston_Paper_Scissor] "," Pleas Enter Some Information To Start The Game.");

		DataProcessing.WhoPlayingWith = _ReadWhoPlayingWith();
		DataProcessing.HowManyRounds = _ReadHowManyRounds();
		
		if (DataProcessing.WhoPlayingWith == clsDataProcessing::enWhoPlayingWith::AnotherPlayer)
		{
			stDate Data = _ReadFirstNameAndAgeOfEachPlayers(1);
			DataProcessing.Player1Name = Data.FirstName;
			DataProcessing.Player1Age = Data.Age;
			Data = _ReadFirstNameAndAgeOfEachPlayers(2);
			DataProcessing.Player2Name = Data.FirstName;
			DataProcessing.Player2Age = Data.Age;
		}
		else
		{
			stDate Data = _ReadFirstNameAndAgeOfEachPlayers(1);
			DataProcessing.Player1Name = Data.FirstName;
			DataProcessing.Player1Age = Data.Age;
			DataProcessing.Player2Name = "Computer";
		}
	}

public:

	static void ShowGameStartScreen()
	{
		clsDataProcessing DataProcessing;
		_ReadPlayersDatat(DataProcessing);

		clsShowPlayGameScreen::ShowPlayGameScreen(DataProcessing);
		clsShowGameResultsScreen::ShowGameResultsScreen(DataProcessing);
	}
};

