#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);

    if (cap.isOpened() == false)
    {
        cout << "Could open camera." << endl;
        cin.get();
        return -1;
    }

    double width = cap.get(CAP_PROP_FRAME_WIDTH);
    double height = cap.get(CAP_PROP_FRAME_HEIGHT);

    cout << "Resolution of video is: " << width << "x" << height << endl;

    string windowName = "HIM";
    namedWindow(windowName);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame);
        if (!bSuccess)
        {
            cout << "Video Camera disconnected." << endl;
            cin.get();
            break;
        }

        imshow(windowName, frame);

        if (waitKey(10) == 27)
        {
            cout << "Esc key was pressed." << endl;
            break;
        }
    }
    return 0;
}