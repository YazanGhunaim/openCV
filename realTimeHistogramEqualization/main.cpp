#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0);

    if (cap.isOpened() == false)
    {
        cout << "Could not open video camera." << endl;
        cin.get();
        return -1;
    }

    String windowNameOriginal = "Original video";
    String windowNameHistrogramEqualized = "Histogram equalized image";

    namedWindow(windowNameOriginal, WINDOW_NORMAL);
    namedWindow(windowNameHistrogramEqualized, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool isSuccess = cap.read(frame);

        if (!isSuccess)
        {
            cout << "Reached end of video." << endl;
            cin.get();
            return -1;
        }

        Mat histogram_equalized_image;
        cvtColor(frame, histogram_equalized_image, COLOR_BGR2YCrCb);

        vector<Mat> vec_channels;
        split(histogram_equalized_image, vec_channels);

        equalizeHist(vec_channels[0], vec_channels[0]);

        merge(vec_channels, histogram_equalized_image);

        cvtColor(histogram_equalized_image, histogram_equalized_image, COLOR_YCrCb2BGR);

        imshow(windowNameOriginal, frame);
        imshow(windowNameHistrogramEqualized, histogram_equalized_image);

        if (waitKey(10) == 27)
        {
            cout << "Esc key was pressed." << endl;
            break;
        }
    }
    destroyAllWindows();
    return 0;
}