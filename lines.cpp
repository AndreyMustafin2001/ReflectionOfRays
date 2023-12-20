#include <iostream>
#include <vector>
#include <map>
void readAllGroups(const std::map<double, std::vector<std::pair<double, double>>>& groupPairs)
{

    auto it = groupPairs.begin();
    double minX = it->second.begin()->first;
    for (const auto& p : it->second)
    {
        if(minX > p.first)
            minX = p.first;
    }

    double maxX = it->second.begin()->first;
    for (const auto& p : it->second)
    {
        if(maxX < p.first)
            maxX = p.first;
    }

    double middleX = 0.5 * (minX + maxX);
    std::cout << "MiddleX=" << middleX << std::endl;

    for (it = groupPairs.begin(); it != groupPairs.end(); ++it)
    {
        std::cout << "Group y=" << it->first << ":" << std::endl;

        for (const auto& pair : it->second)
        {
            std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
        }
    }
}
int main()
{
    std::vector<std::pair<double, double>> pairs = {{1, 2}, {3, 2}, {5, 2}, {3, 6},{1,9}};
    // Using std::map to automatically sort by y coordinate
    std::map<double, std::vector<std::pair<double, double>>> groupPairs;

    for (const auto& pair : pairs)
    {
        groupPairs[pair.second].push_back(pair);
    }

    readAllGroups(groupPairs);

    return 0;
}

