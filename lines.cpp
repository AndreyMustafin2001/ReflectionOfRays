#include <iostream>
#include <vector>
#include <map>

bool isSymmetric(const std::vector<std::pair<double, double>>& pointGroup, double middleX)
{
    double distanceToLeft = 0.0;
    double distanceToRight = 0.0;

    std::map<double,double> have;
    for (const auto& pair : pointGroup)
    {
        have[pair.first]=1;
    }

    for (const auto& pair : pointGroup)
    {
        double symmx;
        if (pair.first <= middleX)
        {
            distanceToLeft = middleX - pair.first;
            symmx = middleX + distanceToLeft;
        }
        else if (pair.first > middleX)
        {
            distanceToRight = pair.first - middleX;
            symmx = middleX - distanceToRight;
        }
        if(have.count(symmx) == 0)
            return false;

    }
    return true;
}

void readAllGroups(const std::map<double, std::vector<std::pair<double, double>>>& groupPairs)
{
    bool answer = true;
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

            bool symmetricResult = isSymmetric(it->second, middleX);
            if(symmetricResult == false)answer = false;
            std::cout << "Simmetric ?: " << (symmetricResult ? "TRUE" : "FALSE") << std::endl;
        }
    if(answer == true){std::cout << "x="<< middleX << std::endl << "true";}
    else std::cout << "false";
}

int main()
{
    std::vector<std::pair<double, double>> pairs = {{1, 2}, {3, 2}, {5, 2}, {3, 6}};

    std::map<double, std::vector<std::pair<double, double>>> groupPairs;

    for (const auto& pair : pairs)
    {
        groupPairs[pair.second].push_back(pair);
    }

    readAllGroups(groupPairs);

    return 0;
}

