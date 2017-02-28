/******************************************************************************************
** Created on 2017.02.17
** Revised on 2017.02.17
** @Author:   Chen
** Info   :   转换图片格式
******************************************************************************************/


#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    for(int i = 0; i <= 361; i ++ )
    {
        string jpgAddress = "/media/chen/DATA/Image/helipad/";
        string jpegAddress = "/media/chen/DATA/Image/helipad2/";
        string imgName;

        ostringstream oss;
        oss << i;
        if (i < 10)
            imgName += "00" + oss.str();
        else if (i < 100)
            imgName += "0" + oss.str();
        else
            imgName += oss.str();

        string jpgName = jpgAddress + imgName + ".jpg";
        string jpegName = jpegAddress + "0" + imgName + ".JPEG";

        Mat src = imread(jpgName);
        imwrite(jpegName, src);

        cout << jpgName << endl;
    }
    return 0;
}
