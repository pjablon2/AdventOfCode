#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<algorithm>
#include<sstream>
#include<tuple>

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
    bool isCompilantToRestrictedPolicy() const;

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

bool PasswordValidator::isCompilantToRestrictedPolicy() const
{
    unsigned int fulfileConditions = 0;
    if(m_password.at(m_lowerLimiter - 1) == m_letter)
    {
        ++fulfileConditions;
    }
    if(m_password.at(m_upperLimiter - 1) == m_letter)
    {
        ++fulfileConditions;
    }
    const unsigned int expectedFulfileConditions = 1;
    return expectedFulfileConditions == fulfileConditions;
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

std::tuple<unsigned int, unsigned int, char, std::string> splitString(const std::string& input)
{
    int low = 0;
    char limiter, comma, c;
    int up = 0;
    std::string word;
    std::stringstream ss;
    ss << input;
    ss >> low >> limiter >> up >> c >> comma >> word;
    std::cout << "splitString:" << low << " " << limiter << " " << up << " " << c << " " << comma << " " << word << "\n";
    return make_tuple(low, up, c, word);
}

void checkAllPasswords(InputsList& inputsList)
{
    unsigned int numberOfValidPasswords = 0;
    for(auto& i : inputsList)
    {
        std::cout << i << "\n";
        unsigned int lowerLimit, upperLimit;
        char letter;
        std::string password;
        std::tie(lowerLimit, upperLimit, letter, password) = splitString(i);
        PasswordValidator passwordValidator(lowerLimit, upperLimit, letter, password);
        if(passwordValidator.isCompilantToRestrictedPolicy())
        {
            std::cout << "Valid password:" << passwordValidator;
            ++numberOfValidPasswords;
        }
        std::cout << std::endl; 
    }
    std::cout << "Number of valid passwords:" << numberOfValidPasswords << std::endl;
}

int main()
{
  std::cout << "Advent Day2" << std::endl;
  InputsList rawPasswordData;
  try 
  {
      rawPasswordData = loadInput("/home/pjablons/work/advent/advent2020/day2/input/day2Input.txt");
      //rawPasswordData = loadInput("/home/pjablons/work/advent/advent2020/day2/input/sampleInput2.txt"); //introduce unit tests
  }
  catch(const char* msg)
  {
      std::cerr << msg << "\n";
  }

  checkAllPasswords(rawPasswordData);

  /*const PasswordValidator secondPassword(1, 3, 'b', "cdefg");
  std::cout << secondPassword;
  std::cout << "isValid:" << secondPassword.isValid() << "\n";

  const PasswordValidator thirdPassword(2, 9, 'c', "ccccccccc");
  std::cout << thirdPassword;
  std::cout << "isValid:" << thirdPassword.isValid() << "\n"; */
  return 0;
}
