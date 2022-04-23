#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<unordered_map>
#include<set>
#include<sstream>
#include<utility>

typedef std::list<std::string> ListOfWord;
class Passport;
typedef std::list<Passport> ListOfPassports;

class Passport
{
public:
    Passport(const std::string& rawData) : m_rawData(rawData) {}
    Passport() {}
    bool isValid() const
    {
        return true;
    }
    bool isAllRequiredDataAvaliable()
    {
        for(const auto& i : requiredFileldsInPassport)
        {
            auto search = passportData.find(i);
            if(search == passportData.end())
            {
                return false;
            }
        }
        return true;
    }

    std::pair<std::string, std::string> splitString(const std::string& input)
    {
        std::string data = input;
        std::string delimiter = ":";
        size_t pos = data.find(delimiter);
        std::string field = data.substr(0, pos);
        data.erase(0, pos + delimiter.length());
        return {field, data};
    }
private:
    std::string m_rawData;
    std::unordered_map<std::string, std::string> passportData = {{"byr", "1984"}, {"iyr", "2017"}};
    std::set<std::string> requiredFileldsInPassport = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

    friend std::ostream& operator<<(std::ostream& os, const Passport& pass)
    {
        std::cout << pass.m_rawData;
        return os;
    }

};

/*
    byr (Birth Year)
    iyr (Issue Year)
    eyr (Expiration Year)
    hgt (Height)
    hcl (Hair Color)
    ecl (Eye Color)
    pid (Passport ID)
    cid (Country ID)
 */

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
           const Passport passport(wholeData);
           if(passport.isValid())
           {
               listOfPassports.emplace_back(wholeData);
           }
           wholeData = "";
           continue;
        }
    }
    listOfPassports.emplace_back(wholeData);
}

int main()
{
   // ListOfPassports listOfPassports;
   // auto inputList = loadInput("/home/pjablons/work/advent/advent2020/day4/input/sampleInput4.txt");
   // fillListOfPassportsBasedOnInput(inputList, listOfPassports);

   // for(auto i : listOfPassports)
   // {
   //    std::cout << i << std::endl;
   // }

    Passport newPassport("wks:1923 www:ssdv");
    std::cout << "IsValid:" << newPassport.isValid() << std::endl;
    std::cout << "Find: "<< newPassport.isAllRequiredDataAvaliable() << std::endl;
    newPassport.splitString("wks:dupa");

    return 0;
}

