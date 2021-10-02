#include<iostream>
#include<string>
#include<fstream>

void loadInput(const std::string& fileName)
{
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
        std::cout << line << "\n";
    }

    input.close();
}


int main()
{
  std::cout << "Advent Day1" << std::endl;
  loadInput("/home/pjablons/work/advent/advent2020/day1/input/day1Input.txt");
  return 0;
}
