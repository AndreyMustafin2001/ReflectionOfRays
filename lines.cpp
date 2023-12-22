#include <iostream>
#include <vector>
#include <map>
//Symmetric check function
bool isSymmetric(const std::vector<std::pair<int, int>>& pointGroup, double middleX)
{
    double distanceToLeft = 0.0;
    double distanceToRight = 0.0;
    //Storing x coordinates and their quantity in  map have
    std::map<int,int> have;
    for (const auto& pair : pointGroup)
    {
        have[pair.first]++;
    }

    for (const auto& pair : pointGroup)
    {
        int symmx;
        //Finding symmetric point
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
        //Checking presence
        if(have[symmx] != have[pair.first])
            return false;

    }
    return true;
}
//Finding candidate for middle point
double straightline(std::vector<std::pair<int, int>>& pairs)
{
 std::map<int, std::vector<std::pair<int, int>>> groupPairs;
    //Group by y coordinates inside map groupPairs;
    for (const auto& pair : pairs)
    {
        groupPairs[pair.second].push_back(pair);
    }
    auto it = groupPairs.begin();
    //Finding min x coordinate in first group
    int minX = it->second.begin()->first;
    for (const auto& p : it->second)
    {
        if(minX > p.first)
            minX = p.first;
    }
    //Finding max x coordinate in first group
    int maxX = it->second.begin()->first;
    for (const auto& p : it->second)
    {
        if(maxX < p.first)
            maxX = p.first;
    }

    double middleX = 0.5 * (minX + maxX);
    return middleX;
}
//Checking existence of a vertical line, relative to which points are symmetric
bool isSymmetricExists(std::vector<std::pair<int, int>>& pairs)
{
    //Group by y coordinates inside map groupPairs;
    std::map<int, std::vector<std::pair<int, int>>> groupPairs;

    for (const auto& pair : pairs)
    {
        groupPairs[pair.second].push_back(pair);
    }

    bool answer = true;
    double middleX = straightline(pairs);
    //Checking if the points are symmetric in the group with respect to the midpoint
    for (auto it = groupPairs.begin(); it != groupPairs.end(); ++it)
        {
            bool symmetricResult = isSymmetric(it->second, middleX);
            if(symmetricResult == false)answer = false;
        }

    if(answer == true){std::cout << "x="<< middleX << std::endl << "true";return true;}
    else
    {
        std::cout << "false";
        return false;
    }
}

