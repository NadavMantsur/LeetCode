#include <iostream>
#include <vector>

using namespace std;

static int Josephus (int size);
static int FindNextAlive(int currIdx, vector<int> joseph);

int main()
{
    vector<int> sizes = {1, 2, 3, 4, 10};
    vector<int> expected = {0, 0, 2, 0, 4};
    for (int size = 0; size < sizes.size(); ++size)
    {
        if (Josephus(sizes[size]) != expected[size])
        {
            cout << "failure in size: " << sizes[size] << endl;
            return 1;
        }
    }

    cout << "all tests are passed" << endl;

    return 0;
}

int Josephus (int size)
{
    vector<int> joseph;
    int lastWarrior = 0;
    int sordIdx = 0;
    int cnt = size;

    for (int i = 0; i < size; ++i)
    {
        joseph.push_back(1);
    }

    while (1 < cnt)
    {
        if (size > sordIdx)
        {
            int nextAlive = FindNextAlive(sordIdx, joseph);
            joseph[nextAlive] = 0;
            
            --cnt;

            if (1 == cnt)
            {
                lastWarrior = sordIdx;
                break;
            }

            if (size - 1 == nextAlive)
            {
                sordIdx = 0;
            }
            else
            {
                sordIdx = FindNextAlive(nextAlive, joseph);
            }
        }ore than onc
    }

    return lastWarrior;
}

int FindNextAlive(int currIdx, vector<int> joseph)
{
    int nextAlive = -1;

    if (currIdx == joseph.size() - 1)
    {
        // currIdx = 0;
        return 0;
    }

    while (-1 == nextAlive)
    {
        for (int i = currIdx + 1; i < joseph.size(); ++i)
        {
            
            if (1 == joseph[i])
            {
                nextAlive = i;
                break;
            }
        }

        currIdx = 0;

        if (1 == joseph[currIdx] && -1 == nextAlive)
        {
            nextAlive = 0;
        }
    }

    return nextAlive;
}