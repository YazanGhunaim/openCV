#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("media/low-contrast-photography-1.jpg");

    if (image.empty())
    {
        cout << "Could not open nor find the image." << endl;
        cin.get();
        return -1;
    }

    Mat hist_equalized_image;
    // converting the image from BGR to YCrCb color space
    cvtColor(image, hist_equalized_image, COLOR_BGR2YCrCb);

    // split the image into 3 channels; Y, Cr and Cb channels and store in vector
    vector<Mat> vec_channels;
    split(hist_equalized_image, vec_channels);

    equalizeHist(vec_channels[0], vec_channels[0]);

    // merge 3 channels in the vector to form the color image in YCrCB color space
    merge(vec_channels, hist_equalized_image);

    cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);

    String windowNameOriginal = "Original image";
    String windowNameHistogramEqualized = "Histogram Equalized image";

    namedWindow(windowNameOriginal, WINDOW_NORMAL);
    namedWindow(windowNameHistogramEqualized,WINDOW_NORMAL);

    resizeWindow(windowNameOriginal,300,300);
    resizeWindow(windowNameHistogramEqualized,300,300);

    imshow(windowNameOriginal, image);
    imshow(windowNameHistogramEqualized, hist_equalized_image);

    waitKey(0);
    destroyAllWindows();

    return 0;
}