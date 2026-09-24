// ejemplo4_umbral_hsv.cpp
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0, cv::CAP_V4L2);
    cv::Mat frame, hsv, mascara;

    // Rango para rojo (ajusta según tu fuente de luz)
    cv::Scalar bajo(0, 120, 70), alto(10, 255, 255);

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
        cv::inRange(hsv, bajo, alto, mascara);

        cv::imshow("Original", frame);
        cv::imshow("Mascara", mascara);
        if (cv::waitKey(1) == 27) break;
    }
    return 0;
}
