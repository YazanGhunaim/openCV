#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);

    if (cap.isOpened() == false)
    {
        cout << "Couldnt open camera." << endl;
        cin.get();
        return -1;
    }

    String windowNameOriginal = "Original Image";
    String windowNameContrastHigh2 = "Constrast Increase";
    String windowNameContrastHigh4 = "Constrast Increase++";
    String windowNameContrastLow0_5 = "Constrast Decrease by 0.5";
    String windowNameContrastLow0_25 = "Constrast Decrease by 0.25";

    namedWindow(windowNameOriginal, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSucess = cap.read(frame);

        if (!bSucess)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameContrastHigh2;
        frame.convertTo(frameContrastHigh2, -1, 2, 0);

        Mat frameContrastHigh4;
        frame.convertTo(frameContrastHigh4, -1, 4, 0);

        Mat frameContrastLow0_5;
        frame.convertTo(frameContrastLow0_5, -1, 0.5, 0);

        Mat frameContrastLow0_25;
        frame.convertTo(frameContrastLow0_25, -1, 0.25, 0);

        imshow(windowNameOriginal, frame);
        imshow(windowNameContrastHigh2, frameContrastHigh2);
        imshow(windowNameContrastHigh4, frameContrastHigh4);
        imshow(windowNameContrastLow0_5, frameContrastLow0_5);
        imshow(windowNameContrastLow0_25, frameContrastLow0_25);

        if (waitKey(10) == 27)
        {
            cout << "Esc key was pressed." << endl;
            break;
        }
    }
    return 0;
}