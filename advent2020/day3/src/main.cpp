#include<iostream>
#include<string>
#include<list>
#include<fstream>

std::list<std::string> loadInput(const std::string& fileName)
{
    std::list<std::string> result;
    std::ifstream input(fileName, std::ios::in);
    if(!input.is_open())
    {
        throw "Unable to open file";
    }
    std::string line;
    while(getline(input, line))
    {
        result.emplace_back(line);
    }

    input.close();
    return result;
}

class Player
{
public:
    Player() : currentPositionX(0), encounteredTrees(0), encounteredFreeSquares(0) {}
    void makeNextStep(std::string& path);
    void checkStartingPoint(std::string& path);
private:
    void checkWhatEncountered(char& spot);
    unsigned int currentPositionX;
    unsigned int encounteredTrees;
    unsigned int encounteredFreeSquares;

    friend std::ostream& operator<<(std::ostream& os, const Player& player)
    {
        std::cout << "Player position:" << player.currentPositionX << " encoutered trees:" << player.encounteredTrees << " encountered free squares:" << player.encounteredFreeSquares << std::endl;
        return os;
    }
};

void Player::checkWhatEncountered(char& spot)
{
    if(spot == '.')
    {
        spot = 'O';
        ++encounteredFreeSquares;
    }
    else
    {
        spot = 'X';
        ++encounteredTrees;
    }
}

void Player::makeNextStep(std::string& path)
{
    currentPositionX = (currentPositionX + 3) % path.size();
    checkWhatEncountered(path.at(currentPositionX));
}

void Player::checkStartingPoint(std::string& path)
{
    checkWhatEncountered(path.at(currentPositionX));
}

int main()
{
    std::list<std::string> inputData;
    try 
    {
        //inputData = loadInput("/home/pjablons/work/advent/advent2020/day3/input/day3Input.txt");
        inputData = loadInput("/home/pjablons/work/advent/advent2020/day3/input/sampleInput3.txt"); //introduce unit tests
    }
    catch(const char* msg)
    {
        std::cerr << msg << "\n";
    }

    Player player;
    for(auto& i : inputData)
    {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    player.checkStartingPoint(*inputData.begin());
    for(auto it = std::next(inputData.begin()); it != inputData.end(); ++it)
    {
        player.makeNextStep(*it);
    }
    std::cout << std::endl;
    for(auto& i : inputData)
    {
        std::cout << i << std::endl;
    }
    std::cout << "Player has reached to the target " << player;
    return 0;
}
