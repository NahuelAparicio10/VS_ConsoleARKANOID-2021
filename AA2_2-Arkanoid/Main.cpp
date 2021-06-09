// actualització sleep -> miliseconds (windows.h)
#pragma once
#include "Inputs.h"
#include "GameManager.h"

enum class GameState { MENU, PLAY, SCORE, RANKING, EXIT };

int main(int argc, char *argv[]) {
	
	GameState myGS = GameState::MENU;
	GameManager myGM;
	InputData inputs;

	do {
		switch (myGS)
		{
		
			case GameState::MENU:
				//**** INPUTS ****//
				inputs.Update();

				//**** UPDATE ****//
				if (inputs.Keyboard[(int)InputKey::GAME]) myGS = GameState::PLAY;
				else if (inputs.Keyboard[(int)InputKey::RANK]) myGS = GameState::RANKING;
				else if (inputs.Keyboard[(int)InputKey::LEAVE]) myGS = GameState::EXIT;

				//**** DRAW ****//
				myGM.Menu();
				Sleep(100); 
				break;

			case GameState::PLAY:

				//**** INPUTS ****//
				inputs.Update();

				//**** UPDATE ****//
				if (inputs.Keyboard[(int)InputKey::LEFT]) { myGM.player.UpdateLeft(myGM.board); }
				else if (inputs.Keyboard[(int)InputKey::RIGHT]) { myGM.player.UpdateRight(myGM.board); }
				else if (inputs.Keyboard[(int)InputKey::ESCAPE]) myGS = GameState::EXIT;
				else if (inputs.Keyboard[(int)InputKey::LEAVE]) myGS = GameState::SCORE;
			
				myGM.Play();

				//**** CHECK ****//
				if (myGM.blocks.values.empty()) myGS = GameState::SCORE;
				if (myGM.player.lifes <= 0) myGS = GameState::SCORE;
				Sleep(myGM.sleepRate);
				break;
		
			case GameState::SCORE:
				//*** INPUTS ***//
				inputs.Update();
				if (inputs.Keyboard[(int)InputKey::ESCAPE]) myGS = GameState::EXIT;

				myGM.PlayScore();
				myGS = GameState::RANKING;
				Sleep(100);
				break;
		
			case GameState::RANKING:
				//*** INPUTS ***//
				inputs.Update();
				if (inputs.Keyboard[(int)InputKey::ESCAPE]) myGS = GameState::MENU;
			
				//*** DRAW ***//
				myGM.SortRanking(myGM.ranking);
				myGM.ShowRanking();
				Sleep(100);
				break;
		
			case GameState::EXIT:
				myGM.Exit();
				break;

			default:
				break;
		}
		system("cls");

	} while (myGS != GameState::EXIT);

}

