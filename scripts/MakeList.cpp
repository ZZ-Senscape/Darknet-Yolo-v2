/******************************************************************************************
** Created on 2017.02.22
** Revised on 2017.02.22
** @Author:   Chen
** Info   :   Make Image List
******************************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const int fileNum = 361;

int main()
{
    ofstream fout("/home/chen/Program/Train/train.txt");

    for(int i = 1; i <= fileNum; i ++ )
    {
        string imgAddress = "/home/chen/Program/Train/image/";

        ostringstream oss;
        oss << i;
        if (i < 10)
            imgAddress += "000" + oss.str();
        else if (i < 100)
            imgAddress += "00" + oss.str();
        else
            imgAddress += "0" + oss.str();

        imgAddress += ".JPEG";
        cout << imgAddress << endl;

        fout << imgAddress << endl;
    }

    fout.close();

    return 0;
}
