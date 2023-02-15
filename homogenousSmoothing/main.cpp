#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("media/image.JPG");

    if (image.empty())
    {
        cout << "Could not load image." << endl;
        cin.get();
        return -1;
    }

    // blur image with 3x3 kernel
    Mat image_blurred_3x3;
    blur(image, image_blurred_3x3, Size(3, 3));

    Mat image_blurred_5x5;
    blur(image, image_blurred_5x5, Size(5, 5));

    String windowNameOriginal = "Original image";
    String windowName3x3 = "blur  3x3";
    String windowName5x5 = "blur 5x5";

    namedWindow(windowNameOriginal);
    namedWindow(windowName3x3);
    namedWindow(windowName5x5);

    imshow(windowNameOriginal, image);
    imshow(windowName3x3, image_blurred_3x3);
    imshow(windowName5x5, image_blurred_5x5);

    waitKey(0);
    destroyAllWindows();

    return 0;
}