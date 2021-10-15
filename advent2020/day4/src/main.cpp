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
    auto inputList = loadInput("/home/pjablons/work/advent/advent2020/day4/input/sampleInput4.txt");
    for(auto& i : inputList)
    {
        if(i.length() == 0)
        {
           continue;
        }
        std::cout << i << std::endl;
    }
    return 0;
}

