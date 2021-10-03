#include<iostream>
#include<string>
#include<fstream>
#include<list>

typedef std::list<std::string> InputsList;

std::list<std::string> loadInput(const std::string& fileName)
{
    InputsList result;
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

void getAllOperands(InputsList& inputsList)
{
    for(auto& i : inputsList)
    {
        std::cout << i << "\n";
    }
}

int main()
{
  std::cout << "Advent Day2" << std::endl;
  InputsList inputData;
  try 
  {
      //inputData = loadInput("/home/pjablons/work/advent/advent2020/day2/input/day2Input.txt");
      inputData = loadInput("/home/pjablons/work/advent/advent2020/day2/input/sampleInput2.txt"); //introduce unit tests
  }
  catch(const char* msg)
  {
      std::cerr << msg << "\n";
  }

  getAllOperands(inputData);

  return 0;
}
