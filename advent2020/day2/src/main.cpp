#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<algorithm>
#include<sstream>

typedef std::list<std::string> InputsList;

class PasswordValidator
{
public:
    PasswordValidator(unsigned int lowerLimiter, unsigned int upperLimiter, char letter, const std::string& password)
        : m_lowerLimiter(lowerLimiter), m_upperLimiter(upperLimiter), m_letter(letter), m_password(password) {}
    PasswordValidator(const PasswordValidator& passValid)
    {
      std::cout << "Copy constructor" << std::endl;
      m_lowerLimiter = passValid.m_lowerLimiter;
      m_upperLimiter = passValid.m_upperLimiter;
      m_letter = passValid.m_letter;
      m_password = passValid.m_password;
    }
    PasswordValidator& operator=(const PasswordValidator& passValid)
    {
      std::cout << "Assign operator" << std::endl;
      m_lowerLimiter = passValid.m_lowerLimiter;
      m_upperLimiter = passValid.m_upperLimiter;
      m_letter = passValid.m_letter;
      m_password = passValid.m_password;
      return *this;
    }
    bool isValid() const;

private:
    unsigned int m_lowerLimiter;
    unsigned int m_upperLimiter;
    char m_letter;
    std::string m_password;

    friend std::ostream& operator<<(std::ostream& os, const PasswordValidator& passValid)
    {
      std::cout << "m_lowerLimiter:" << passValid.m_lowerLimiter << " m_upperLimiter:" << passValid.m_upperLimiter << " m_letter:" << passValid.m_letter << " m_password:" << passValid.m_password << "\n"; 
      return os;
    }
};

bool PasswordValidator::isValid() const
{
    const unsigned int count = std::count(m_password.begin(), m_password.end(), m_letter);
    return count >= m_lowerLimiter && count <= m_upperLimiter;
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

void splitString(const std::string& input)
{
    int low = 0;
    char limiter, comma, c;
    int up = 0;
    std::string word;
    std::stringstream ss;
    ss << input;
    ss >> low >> limiter >> up >> c >> comma >> word;
    std::cout << "splitString:" << low << " " << limiter << " " << up << " " << c << " " << comma << " " << word << "\n";
}

void getAllOperands(InputsList& inputsList)
{
    for(auto& i : inputsList)
    {
        std::cout << i << "\n";
        splitString(i);
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

  /*const PasswordValidator secondPassword(1, 3, 'b', "cdefg");
  std::cout << secondPassword;
  std::cout << "isValid:" << secondPassword.isValid() << "\n";

  const PasswordValidator thirdPassword(2, 9, 'c', "ccccccccc");
  std::cout << thirdPassword;
  std::cout << "isValid:" << thirdPassword.isValid() << "\n"; */

  return 0;
}
