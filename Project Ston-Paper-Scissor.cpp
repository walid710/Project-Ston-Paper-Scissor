#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>
#include <ctime>

#include "clsUtil.h"
#include "clsShowGameStarScreen.h"
using namespace std;

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

int main()
{
    clsUtil::Srand();
    char PlayAgain = 'y';
    do
    {
        ResetScreen();
        clsShowGameStarScreen::ShowGameStartScreen();
        cout << "\n" << clsUtil::Tabs(5) << "Do you want to play again? [Y/N]=> ";
        cin >> PlayAgain;
    } while (toupper(PlayAgain) == 'Y');
    system("pause>0");
    return 0;
}

