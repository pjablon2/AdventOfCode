#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include<unordered_map>
#include<set>
#include<sstream>
#include<utility>

namespace
{
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
bool checkBirthYear(const std::string& value)
{
    return true;
}

bool checkIssueYear(const std::string& value)
{
    return true;
}

bool checkExpirationYear(const std::string& value)
{
    return true;
}

bool checkHeight(const std::string& value)
{
    return true;
}

bool checkHairColor(const std::string& value)
{
    return true;
}
//amb blu brn gry grn hzl oth
bool checkEyeColor(const std::string& value)
{
    return value == "amb" || value == "blu" || value == "brn" || value == "gry" || value == "grn" || value == "hzl" || value == "oth";
}

bool checkPassportId(const std::string& value)
{
    return true;
}

bool checkCountryId(const std::string&)
{
    return true;
}

bool isSingleFieldValid(const std::string& key, const std::string& value)
{
    if(key == "byr")
    {
        return checkBirthYear(value);
    }
    else if(key == "iyr")
    {
        return checkIssueYear(value);
    }
    else if(key == "eyr")
    {
        return checkExpirationYear(value);
    }
    else if(key == "hgt")
    {
        return checkHeight(value);
    }
    else if(key == "hcl")
    {
        return checkHairColor(value);
    }
    else if(key == "ecl")
    {
        return checkEyeColor(value);
    }
    else if(key == "pid")
    {
        return checkPassportId(value);
    }
    else if(key == "cid")
    {
        return checkCountryId(value);
    }
    return false;
}

}




typedef std::list<std::string> ListOfWord;
class Passport;
typedef std::list<Passport> ListOfPassports;

class Passport
{
public:
    Passport(const std::string& rawData) : m_rawData(rawData)
    {
        splitRawData();
    }
    Passport() {}

    bool isValid() const
    {
        return isAllRequiredDataAvaliable();
    }

private:
    bool isAllRequiredDataAvaliable() const
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

    void splitRawData()
    {
        size_t pos = 0;
        std::string delimiter = " ";
        std::string chainToSplit = m_rawData;
        while((pos = chainToSplit.find(delimiter)) != std::string::npos)
        {
           passportData.emplace(splitString(chainToSplit.substr(0, pos)));
           chainToSplit.erase(0, pos + delimiter.length());
        }
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
    std::string m_rawData;
    std::unordered_map<std::string, std::string> passportData;
    std::set<std::string> requiredFileldsInPassport = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

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
           const Passport passport(wholeData);
           if(passport.isValid())
           {
               listOfPassports.emplace_back(passport);
           }
           wholeData = "";
           continue;
        }
    }
}

int main()
{
   // ListOfPassports listOfPassports;
   // auto inputList = loadInput("/home/pjablons/work/advent/advent2020/day4/input/day4Input.txt");
   // //auto inputList = loadInput("/home/pjablons/work/advent/advent2020/day4/input/sampleInput4.txt");
   // fillListOfPassportsBasedOnInput(inputList, listOfPassports);

   // for(auto i : listOfPassports)
   // {
   //    std::cout << i << std::endl;
   // }

   // std::cout <<"Num of valid Passports: " << listOfPassports.size() << std::endl;

    std::cout << "Is Valid Field:" << isSingleFieldValid("ecl","oth") << std::endl; 
    return 0;
}

