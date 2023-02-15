#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat image = imread("media/lofi_generator.png");

    if (image.empty())
    {
        cout << "image could not be opened." << endl;
        cin.get();
        return -1;
    }

    /*
    void Mat::convertTo( OutputArray m, int rtype, double alpha=1, double beta=0 ) const

    This function converts the each pixel value to the target data type and changes the value as per the following formula.

    pixel_value_of_output_image(x, y) = pixel_value_of_input_image(x, y) * alpha + beta;

    1-m - Output image. This data structure will be reallocated if required.

    2-rtype - Type of the output image. If rtype is a negative value, the type of the output image will be same as the input image.

    3-alpha - Each pixels in the input image will be multiplied by this number before assigning to the output image.

    4-beta - This value will be added to each pixels in the input image and assigned to the output image.
    */
    Mat imageBrightnessHigh50;
    image.convertTo(imageBrightnessHigh50, -1, 1, 50);
    Mat imageBrightnessHigh100;
    image.convertTo(imageBrightnessHigh100, -1, 1, 100);
    Mat imageBrightnessLow50;
    image.convertTo(imageBrightnessLow50, -1, 1, -50);
    Mat imageBrightnessLow100;
    image.convertTo(imageBrightnessLow100, -1, 1, -100);

    String windowNameOriginalImage = "Original Image";
    String windowNameBrightnessHigh50 = "Brightness Increased by 50";
    String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
    String windowNameBrightnessLow50 = "Brightness Decreased by 50";
    String windowNameBrightnessLow100 = "Brightness Decreased by 100";

    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    imshow(windowNameOriginalImage, image);
    imshow(windowNameBrightnessHigh50, imageBrightnessHigh50);
    imshow(windowNameWithBrightnessHigh100, imageBrightnessHigh100);
    imshow(windowNameBrightnessLow50, imageBrightnessLow50);
    imshow(windowNameBrightnessLow100, imageBrightnessLow100);

    waitKey(0);
    destroyAllWindows();
    return 0;
}