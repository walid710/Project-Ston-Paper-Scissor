#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

#include "clsScreen.h"
using namespace std;

class clsDataProcessing
{
private :

	string _Player1Name;
	string _Player2Name;
	//------------------------
	short _Player1Age=0;
	short _Player2Age = 0;
	//------------------------
	enum enWhoPlayingWith;
	enWhoPlayingWith _WhoPlayingWith;
	//------------------------
	short _HowManyRounds = 0;
	//------------------------
	enum enGameChoice;
	enGameChoice _Player1Choice;
	enGameChoice _Player2Choice;
	//------------------------
	short _Player1WonTimes=0;
	short _Player2WonTimes = 0;
	short _DrawTimes=0;
	//------------------------
	enum enWHoWinner;
	enWHoWinner _Winner;
	//------------------------
	string _WinnerName;
	//------------------------
	short _RoundNumber;
	//------------------------
	enWHoWinner _GameWinner;


public:

	enum enGameChoice
	{
		Stone=1,
		Paper=2,
		Scissors=3
	};
	enum enWhoPlayingWith
	{
		AnotherPlayer=1,
		Computer=2
	};
	enum enWHoWinner
	{
		Player1 = 1,
		Player2 = 2,
		Draw =3
	};
	//----------------------------------------------------------------------------------------------

	//Properaty Set And Get
	void SetPlayer1Name(string Player1Name)
	{
		_Player1Name = Player1Name;
	}
	string GetPlayer1Name()
	{
		return _Player1Name;
	}
	__declspec(property(get = GetPlayer1Name, put = SetPlayer1Name))string Player1Name;
	//Properaty Set And Get
	void SetPlayer2Name(string Player2Name)
	{
		_Player2Name = Player2Name;
	}
	string GetPlayer2Name()
	{
		return _Player2Name;
	}
	__declspec(property(get = GetPlayer2Name, put = SetPlayer2Name))string Player2Name;
	//Properaty Set And Get
	void SetPlayer1Age(short Player1Age)
	{
		_Player1Age = Player1Age;
	}
	short GetPlayer1Age()
	{
		return _Player1Age;
	}
	__declspec(property(get = GetPlayer1Age, put = SetPlayer1Age))short Player1Age;
	//Properaty Set And Get
	void SetPlayer2Age(short Player2Age)
	{
		_Player2Age = Player2Age;
	}
	short GetPlayer2Age()
	{
		return _Player2Age;
	}
	__declspec(property(get = GetPlayer2Age, put = SetPlayer2Age))short Player2Age;
	//Properaty Set And Get
	void SetPlayer1Choice(enGameChoice Player1Choice)
	{
		_Player1Choice = Player1Choice;
	}
	enGameChoice GetPlayer1Choice()
	{
		return _Player1Choice;
	}
	__declspec(property(get = GetPlayer1Choice, put = SetPlayer1Choice))enGameChoice Player1Choice;
	//Properaty Set And Get
	void SetPlayer2Choice(enGameChoice Player2Choice)
	{
		_Player2Choice = Player2Choice;
	}
	enGameChoice GetPlayer2Choice()
	{
		return _Player2Choice;
	}
	__declspec(property(get = GetPlayer2Choice, put = SetPlayer2Choice))enGameChoice Player2Choice;
	//Properaty Set And Get
	void SetHowManyRounds(short HowManyRounds)
	{
		_HowManyRounds = HowManyRounds;
	}
	short GetHowManyRounds()
	{
		return _HowManyRounds;
	}
	__declspec(property(get = GetHowManyRounds, put = SetHowManyRounds))short HowManyRounds;
	//Properaty Set And Get
	void SetPlayer1WonTimes(short Player1WonTimes)
	{
		_Player1WonTimes = Player1WonTimes;
	}
	short GetPlayer1WonTimes()
	{
		return _Player1WonTimes;
	}
	__declspec(property(get = GetPlayer1WonTimes, put = SetPlayer1WonTimes))short Player1WonTimes;
	//Properaty Set And Get
	void SetPlayer2WonTimes(short Player2WonTimes)
	{
		_Player2WonTimes = Player2WonTimes;
	}
	short GetPlayer2WonTimes()
	{
		return _Player2WonTimes;
	}
	__declspec(property(get = GetPlayer2WonTimes, put = SetPlayer2WonTimes))short Player2WonTimes;
	//Properaty Set And Get
	void SetDrawTimes(short DrawTimes)
	{
		_DrawTimes = DrawTimes;
	}
	short GetDrawTimes()
	{
		return _DrawTimes;
	}
	__declspec(property(get = GetDrawTimes, put = SetDrawTimes))short DrawTimes;
	//Properaty Set And Get
	void SetWhoPlayingWith(enWhoPlayingWith WhoPlayingWith)
	{
		_WhoPlayingWith = WhoPlayingWith;
	}
	enWhoPlayingWith GetWhoPlayingWith()
	{
		return _WhoPlayingWith;
	}
	__declspec(property(get = GetWhoPlayingWith, put = SetWhoPlayingWith))enWhoPlayingWith WhoPlayingWith;
	//Properaty Set And Get
	void SetWinner(enWHoWinner Winner)
	{
		_Winner = Winner;
	}
	enWHoWinner GetWinner()
	{
		return _Winner;
	}
	__declspec(property(get = GetWinner, put = SetWinner))enWHoWinner Winner;
	//Properaty Set And Get
	void SetWinnerName(string WinnerName)
	{
		_WinnerName = WinnerName;
	}
	string GetWinnerName()
	{
		return _WinnerName;
	}
	__declspec(property(get = GetWinnerName, put = SetWinnerName))string WinnerName;
	//Properaty Set And Get
	void SetRoundNumber(short RoundNumber)
	{
		_RoundNumber = RoundNumber;
	}
	short GetRoundNumber()
	{
		return _RoundNumber;
	}
	__declspec(property(get = GetRoundNumber, put = SetRoundNumber))short RoundNumber;
	//Properaty Set And Get
	void SetGameWinner(enWHoWinner GameWinner)
	{
		_GameWinner = GameWinner;
	}
	enWHoWinner GetGameWinner()
	{
		return _GameWinner;
	}
	__declspec(property(get = GetGameWinner, put = SetGameWinner))enWHoWinner GameWinner;
	//--------------------------------------------------------------------------------------------------------
	static string ChoiceName(enGameChoice Choice)
	{
		switch (Choice)
		{
		case enGameChoice::Stone:
			return "Stone";
		case enGameChoice::Paper:
			return "Paper";
		case enGameChoice::Scissors:
			return "Scissors";
		}
		/*string arrGameChoices[3] = { "Stone" ,"Paper" ,"Scissors" };
		return arrGameChoices[Choice - 1];*/
	}

	static enWHoWinner WhoWonTheRound(clsDataProcessing &DataProcessing)
	{
		if (DataProcessing.Player1Choice == DataProcessing.Player2Choice)
		{
			return enWHoWinner::Draw;
		}
		else if (DataProcessing.Player1Choice == enGameChoice::Stone)
		{
			if (DataProcessing.Player2Choice == enGameChoice::Paper)
			{
				return enWHoWinner::Player2;
			}
			else if (DataProcessing.Player2Choice == enGameChoice::Scissors)
			{
				return enWHoWinner::Player1;
			}
		}
		else if (DataProcessing.Player1Choice == enGameChoice::Paper)
		{
			if (DataProcessing.Player2Choice == enGameChoice::Stone)
			{
				return enWHoWinner::Player1;
			}
			else if (DataProcessing.Player2Choice == enGameChoice::Scissors)
			{
				return enWHoWinner::Player2;
			}
		}
		else if (DataProcessing.Player1Choice == enGameChoice::Scissors)
		{
			if (DataProcessing.Player2Choice == enGameChoice::Stone)
			{
				return enWHoWinner::Player2;
			}
			else if (DataProcessing.Player2Choice == enGameChoice::Paper)
			{
				return enWHoWinner::Player1;
			}
		}
	}

    string Winner_Name(enWHoWinner Winner)
	{
		switch (Winner)
		{
		case clsDataProcessing::enWHoWinner::Player1:
			return Player1Name;
		case clsDataProcessing::enWHoWinner::Player2:
			return Player2Name;
		default:
			return "Not Winner";
		}		
	}

	void IncreaseWinAndDrawCounters(enWHoWinner Winner )
	{
		switch (Winner)
		{
		case enWHoWinner::Player1:
			Player1WonTimes++;
			break;
		case enWHoWinner::Player2:
			Player2WonTimes++;
			break;
		default :
			DrawTimes++;
			break;
		}
	}

	static enWHoWinner WhoWonTheGame(clsDataProcessing& DataProcessing)
	{
		if (DataProcessing.Player1WonTimes > DataProcessing.Player2WonTimes)
		{
			return enWHoWinner::Player1;
		}
		else if (DataProcessing.Player1WonTimes < DataProcessing.Player2WonTimes)
		{
			return enWHoWinner::Player2;
		}
		else
		{
			return enWHoWinner::Draw;
		}
	}

	
};

