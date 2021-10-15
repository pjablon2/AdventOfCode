#include<iostream>
#include<string>
#include<list>
#include<fstream>

typedef std::list<std::string> ListOfWord;

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

int main()
{

    return 0;
}

