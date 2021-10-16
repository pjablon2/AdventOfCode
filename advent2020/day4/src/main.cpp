#include<iostream>
#include<string>
#include<list>
#include<fstream>

typedef std::list<std::string> ListOfWord;
class Passport;
typedef std::list<Passport> ListOfPassports;

class Passport
{
public:
    Passport(const std::string& rawData) : m_rawData(rawData) {}
    Passport() {}

private:
    std::string m_rawData;

    friend std::ostream& operator<<(std::ostream& os, const Passport& pass)
    {
        std::cout << pass.m_rawData;
        return os;
    }

};

ListOfWord loadInput(const std::string& fileName)
{
    ListOfWord result;
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

void fillListOfPassportsBasedOnInput(const ListOfWord& input, ListOfPassports& listOfPassports)
{
    std::string wholeData = "";
    for(auto i : input)
    {
        wholeData = wholeData + " " + i;
        if(i.length() == 0)
        {
           listOfPassports.emplace_back(wholeData);
           wholeData = "";
           continue;
        }
    }
    listOfPassports.emplace_back(wholeData);
}

int main()
{
    ListOfPassports listOfPassports;
    auto inputList = loadInput("/home/pjablons/work/advent/advent2020/day4/input/sampleInput4.txt");
    fillListOfPassportsBasedOnInput(inputList, listOfPassports);

    for(auto i : listOfPassports)
    {
       std::cout << i << std::endl;
    }

    return 0;
}

