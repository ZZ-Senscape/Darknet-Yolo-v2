/******************************************************************************************
** Created on 2017.02.17
** Revised on 2017.02.17
** @Author:   Chen
** Info   :   使用外部摄像头采集图片,按'S'保存,按'ESC'退出
**            imgName修改文件地址
******************************************************************************************/

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    VideoCapture inputVideo(0);    //0为外部摄像头的ID，1为笔记本内置摄像头的ID
    Mat src;
    int i = 0;

    for(;;)
    {
        inputVideo >> src;
        if(src.empty() & i > 0)
            return 1;

        imshow("input",src);

        char c = waitKey(1);

        string imgName = "/media/chen/DATA/Image/negative/";
        ostringstream oss;
        oss << i;
        if (i < 10)
            imgName += "00" + oss.str() + ".jpg";
        else if (i < 100)
            imgName += "0" + oss.str() + ".jpg";
        else
            imgName += oss.str() + ".jpg";

        if (c == 27)
            break;
        if (c == 's')
        {
            imwrite(imgName, src);
            Mat save = imread(imgName);
            imshow("save", save);
            cout << imgName << endl;
            i++;
        }
    }

    return 0;
}
