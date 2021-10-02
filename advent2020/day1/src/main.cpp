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
        throw "Unable to open file";
    }
    std::string line;
    while(getline(input, line))
    {
        result.emplace_back(std::stoi(line)); 
    }

    input.close();
    return result;
}

unsigned int calculateMultiplyOfTwoEntriesThatSumIs2020(const std::list<unsigned int>& inputData)
{
    const unsigned int expectedSum = 2020;
    for(auto firstOperand : inputData)
    {
        for(auto secondOperand : inputData)
        {
            if(firstOperand + secondOperand == expectedSum)
            {
                std::cout << "first:" << firstOperand <<" second:" << secondOperand << " multiply of both operands:" << firstOperand * secondOperand << "\n";
                return firstOperand * secondOperand;
            }
        }
    }
    return 0;
}

unsigned int calculateProductOfThreeEntriesThatSumIs2020(const std::list<unsigned int>& inputData)
{
    const unsigned int expectedSum = 2020;
    for(auto firstOperand : inputData)
    {
        for(auto secondOperand : inputData)
        {
            for(auto thirdOperand : inputData)
            {
                if(firstOperand + secondOperand + thirdOperand == expectedSum)
                {
                    std::cout << "first:" << firstOperand <<" second:" << secondOperand << " thirdOperand:" << thirdOperand <<" multiply of three operands:" << firstOperand * secondOperand * thirdOperand << "\n";
                    return firstOperand * secondOperand * thirdOperand;
                }
            }
        }
    }
    return 0;
}


int main()
{
  std::cout << "Advent Day1" << std::endl;
  std::list<unsigned int> inputData;
  try 
  {
      inputData = loadInput("/home/pjablons/work/advent/advent2020/day1/input/day1Input.txt");
      //inputData = loadInput("/home/pjablons/work/advent/advent2020/day1/input/sampleInput1.txt"); //introduce unit tests
  }
  catch(const char* msg)
  {
      std::cerr << msg << "\n";
  }

  unsigned int multiply = calculateMultiplyOfTwoEntriesThatSumIs2020(inputData);
  std::cout << "Day1 result of first task is:" << multiply << "\n";

  multiply = calculateProductOfThreeEntriesThatSumIs2020(inputData);
  std::cout << "Day1 result of second task is:" << multiply << "\n";

  return 0;
}
