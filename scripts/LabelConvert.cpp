#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const int imgHeight = 480;
const int imgWidth = 640;
const int fileNum = 361;

int main()
{

    for(int i = 1; i <= fileNum; i ++ )
    {
        string finAddress = "/home/chen/label/fin/";
        string foutAddress = "/home/chen/label/fout/";

        string fileName;
        ostringstream oss;
        oss << i;
        if (i < 10)
            fileName = "000" + oss.str();
        else if (i < 100)
            fileName = "00" + oss.str();
        else
            fileName = "0" + oss.str();

        fileName += ".txt";
        //cout << fileName << endl;

        finAddress += fileName;
        foutAddress += fileName;


        ifstream fin(finAddress);
        ofstream fout(foutAddress);

        int classID;
        int x1, x2, y1, y2;
        double rx1, rx2, ry1, ry2;

        if(fin.is_open())
            cout << "open " << finAddress << endl;

        fin >> classID;
        fin >> x1;
        fin >> y1;
        fin >> x2;
        fin >> y2;

        //cout << classID << " " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

        rx1 = (double)x1 / (double)imgWidth;
        rx2 = (double)(x2 - x1) / (double)imgWidth;
        ry1 = (double)y1 / (double)imgHeight;
        ry2 = (double)(y2 - y1) / (double)imgHeight;

        fout << "0" << " " << rx1 << " " << ry1 << " " << rx2 << " " << ry2 << endl;

        fin.close();
        fout.close();
    }

    return 0;
}

