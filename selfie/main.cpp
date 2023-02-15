#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);

    if (cap.isOpened() == false)
    {
        cout << "Camera could not be opened." << endl;
        cin.get();
        return -1;
    }

    int frameWidth = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int frameHeight = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

    Size frameSize(frameWidth, frameHeight);
    int fps = 30;

    VideoWriter oVideoWriter("results/Wrizz.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, frameSize, true);

    if (oVideoWriter.isOpened() == false)
    {
        cout << "Cannot save the video to a file" << endl;
        cin.get();
        return -1;
    }

    string WindowName = "Proof of rizz";
    namedWindow(WindowName);

    while (true)
    {
        Mat frame;
        bool isSuccess = cap.read(frame);

        if (isSuccess == false)
        {
            cout << "Camera disconnected." << endl;
            cin.get();
            return -1;
        }

        oVideoWriter.write(frame);

        imshow(WindowName, frame);
        if (waitKey(10) == 27)
        {
            cout << "Esc key was pressed." << endl;
            break;
        }
    }
    oVideoWriter.release();
    return 0;
}