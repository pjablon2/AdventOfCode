#include<iostream>
#include<string>
#include<fstream>
#include<list>

typedef std::list<std::string> InputsList;

class PasswordValidator
{
public:
    PasswordValidator(unsigned int lowerLimiter, unsigned int upperLimiter, char letter, const std::string& password)
        : m_lowerLimiter(lowerLimiter), m_upperLimiter(upperLimiter), m_letter(letter), m_password(password) {}
    bool isValid();

private:
    unsigned int m_lowerLimiter;
    unsigned int m_upperLimiter;
    char m_letter;
    std::string m_password;

    friend std::ostream& operator<<(std::ostream& os, PasswordValidator passValid)
    {
      std::cout << "m_lowerLimiter:" << passValid.m_lowerLimiter << " m_upperLimiter:" << passValid.m_upperLimiter << " m_letter:" << passValid.m_letter << " m_password:" << passValid.m_password << "\n"; 
      return os;
    }
};

bool PasswordValidator::isValid()
{
    return true;
}

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

  const PasswordValidator firstPassword(1,3,'a',"abcde");
  std::cout << firstPassword << "\n";

  return 0;
}