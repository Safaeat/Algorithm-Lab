#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <sstream>
#include <vector>
/**
=========Sample Input=========
Memory Holes:50 200 70 115 15
Memory Requests:100 10 35 15 23 6 25 55 88 40
==========End  Input==========
**/
using namespace std;

void worstFit(vector <int> memHoles, vector <int> memReq);
void print(int indicator[], vector <int> memReq, vector <int> memHoles, int *blockStat);
int main(void)
{
    int take;
    string holeList, reqList,fit;
    vector <int> memHoles, memReq;

    cout << "Memory Holes: ";
    getline(cin, holeList);

    cout << "Memory Requests: ";
    getline(cin, reqList);
    stringstream holes(holeList), requests(reqList);

     while(holes >> take)
        memHoles.push_back(take);

    while(requests >> take)
        memReq.push_back(take);

    worstFit(memHoles, memReq);
    return 0;
}
void worstFit(vector <int> memHoles, vector <int> memReq)
{
    cout << "\nWorst-fit\n";
    cout << "---------\n";

    int i, j, mx, lHoles = memHoles.size(), lReq = memReq.size(), indicator[lReq+1], blockStat[lHoles][lReq+1];

    for(i = 0; i < lHoles; ++i)
        blockStat[i][0] = memHoles[i];

    for(j = 0; j <= lReq; ++j)
        indicator[j] = -1;
    indicator[0] = 0;

    for(i = 0; i < lReq; ++i)
    {
        mx = -1;
        for(j = 0; j < lHoles; ++j)
        {
            blockStat[j][i+1] = blockStat[j][i];
            if(memHoles[j] >= memReq[i] && memHoles[j] > mx && indicator[i] != -1)
            {
                indicator[i+1] = j;
                mx = memHoles[j];
            }
        }
        memHoles[indicator[i+1]] -= memReq[i];
        blockStat[indicator[i+1]][i+1] -= memReq[i];
    }

    print(indicator, memReq, memHoles, *blockStat);
    cout << "End of Worst-fit\n";
}

void print(int indicator[], vector<int> memReq, vector<int> memHoles, int *blockStat)
{
    int i, j, frag = 0, lHoles = memHoles.size(), lReq = memReq.size();

    cout << "Request\t|";
    for (i = 0; i < lReq; ++i)
        cout << setw(6) << right << memReq[i] << "|";
    cout << "\n=========";
    j = lReq * 7;
    while (j--)
        cout << "=";
    cout << "\n";

    for (i = 0; i < lHoles; ++i)
    {
        cout << "Block " << i + 1 << "\t|";
        for (j = 0; j < lReq; ++j)
        {
            if (indicator[j + 1] == i)
                cout << " ->" << setw(3) << right << *((blockStat + i + i * lReq) + j + 1) << "|";
            else if (indicator[j + 1] == -1)
                cout << setw(4) << right << "-" << setw(3) << right << "|";
            else
                cout << setw(6) << right << *((blockStat + i + i * lReq) + j + 1) << "|";
        }
        cout << "\n---------";
        j = lReq * 7;
        while (j--)
            cout << "-";
        cout << "\n";
    }

    for (i = 0; i < lHoles; ++i)
        frag += memHoles[i];

    if (indicator[lReq] == -1)
        cout << "Total External Fragmentation: " << frag << "\n";
    else
        cout << "No External Fragmentation\n";
}
