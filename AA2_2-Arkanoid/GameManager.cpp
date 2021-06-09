#include "GameManager.h"

//GM Constructor
GameManager::GameManager() {	
	blocks.SetBaseValues(board.blockVal1, board.blockVal2, (board.rowsWithBlocks * (board.rows - 2)));	
	ReadRankingFile();
	maxBlocs = blocks.values.size();
	sleepRate = 100;
}

//GM Destructor
GameManager::~GameManager() {}

void GameManager::Menu() 
{
	std::cout << "~*~*~*- MENU -*~*~*~" << std::endl;
	std::cout << "1 Play" << std::endl;
	std::cout << "2 Ranking" << std::endl;
	std::cout << "0 Exit" << std::endl;
}

void GameManager::Play() {

	//**** UPDATE ****//

	board.ClearBall(ball.pos.posY, ball.pos.posX);

	ball.MoveBall(board, player);

	if (ball.GetNextPos(board) == CellType::BLOCK) { score.SetScore(blocks.GetValue()); }

	board.UpdateBoard(player.pos.posY, player.pos.posX, ball.pos.posY, ball.pos.posX);

	//**** DRAW ****//
	score.DrawScore();
	player.DrawLives();
	board.PrintBoard();

	//**** CHECK ****//
	if (ball.pos.posY > player.pos.posY) {
		player.lifes--;
		//Reset ball
		board.ClearBall(ball.pos.posY, ball.pos.posX);
		ball.ResetBallOnDie();
	}

}

void GameManager::PlayScore() {
	std::cout << "~*~*~*- GAME OVER -*~*~*~" << std::endl;
	std::cout << "Final Score ~> " << score.GetScore() << std::endl;

	//Ask & Get UserName
	std::string tempName;
	std::cout << "Enter your name: " << std::endl;
	std::cin >> tempName;

	//add current player info to map 
	ranking.insert(std::pair<int, std::string>(score.GetScore(), tempName));
}

void GameManager::ShowRanking() {
	std::cout << "~*~*~*- RANKING -*~*~*~" << std::endl;
	for (auto it = ranking.rbegin(); it != ranking.rend(); ++it)
		std::cout << it->second << ' ' << it->first << std::endl;
}

void GameManager::Exit() { exit(1); }

void GameManager::SaveRanking() {
	std::ofstream rankingFile;
	rankingFile.open("ranking.txt");
	for(auto it = ranking.rbegin(); it != ranking.rend(); ++it)
		rankingFile << it->first << '\n' << it->second << '\n';
	rankingFile.close();
}

void GameManager::ReadRankingFile() 
{
	std::string line;
	std::vector<std::string> data;
	std::ifstream rankingFile;
	rankingFile.open("ranking.txt");

	if (rankingFile.fail()) {
		std::cout << "ranking is not available";
		exit(1);
	}

	while (getline(rankingFile, line)) {
		std::istringstream txt_str(line);
		getline(txt_str, line, '\n'); data.push_back(line);
	}
	rankingFile.close();

	int it = 1;
	for (int i = 0; i < data.size(); i+=2)
	{
		if (i <= 8) ranking.insert({ std::stol(data[i]), data[it] });
		it += 2;
	}
}

//Giving the map, sort the ranking and shows the results
void GameManager::SortRanking(std::map<int, std::string> &M)
{
	// Declare set according to Comaparator
	std::set<std::pair<int, std::string>, comparator> S (M.begin(), M.end());
	ranking.clear();

	// Fill ranking map sorted
	for (auto &it : S) 
		if (ranking.size() < 5) ranking.insert({it.first, it.second});
	
	// Save ranking map
	SaveRanking();
}

int GameManager::ChangeSpeed() 
{
	int temp = (blocks.values.size() * 100) / maxBlocs;
	if (temp <= 75 && temp >= 50) return sleepRate = 85;
	else if (temp < 50 && temp >= 25) return sleepRate = 70;
	else if (temp < 25) return sleepRate = 60;
}