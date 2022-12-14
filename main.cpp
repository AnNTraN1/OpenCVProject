
#include <iostream>
#include <sstream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
using namespace cv;
using namespace std;




int main(int argc, char* argv[])
{
    VideoCapture cap;
    Mat videoFarme;

    cap.open(0);
    namedWindow("VidepCapture", WINDOW_AUTOSIZE);

    /*VideoCapture cap(samples::findFile("vtest.avi"));*/

    //string image_path = samples::findFile("C:/Users/ttien/Downloads/fb1.jpg");
    //
    //Mat img = imread(image_path, IMREAD_COLOR);

   

    Ptr<BackgroundSubtractor> pBackSub;
        pBackSub = createBackgroundSubtractorMOG2();
        /*pBackSub = createBackgroundSubtractorKNN();*/
    
    Mat frame, fgMask;
    while (true) {
        cap >> frame;
        if (frame.empty())
            break;
       pBackSub->apply(frame, fgMask);
        imshow("Frame", frame);
        imshow("FG Mask", fgMask);
        int keyboard = waitKey(30);
        if (keyboard == 'q' || keyboard == 27)
            break;
    }
    return 0;
}
