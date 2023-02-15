#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("media/theThinker.jpg");

    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); // wait for any key press
        return -1;
    }

    String windowName = "The Thinker";

    namedWindow(windowName);

    imshow(windowName, image);

    waitKey(0);

    destroyWindow(windowName);

    return 0;
}