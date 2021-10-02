#include<iostream>
#include<string>
#include<fstream>
#include<list>

std::list<unsigned int> loadInput(const std::string& fileName)
{
    std::list<unsigned int> result;
    std::ifstream input(fileName, std::ios::in);
    if(!input.is_open())
    {
      std::cout << "Unable to open file:" << fileName << std::endl;
    }
    else
    {
      std::cout << "Sucesfuly opened file:" << fileName << std::endl; 
    }
    std::string line;
    while(getline(input, line))
    {
//        std::cout << std::stoi(line) << "\n";
      result.emplace_back(std::stoi(line)); 
    }

    input.close();
    return result;
}


int main()
{
  std::cout << "Advent Day1" << std::endl;

  std::list<unsigned int> inputData = loadInput("/home/pjablons/work/advent/advent2020/day1/input/day1Input.txt");
  return 0;
}
