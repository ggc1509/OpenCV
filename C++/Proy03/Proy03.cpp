// ejemplo3_canny.cpp
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    cv::Mat img = cv::imread(argv[1]);
    cv::Mat gris, bordes;

    cv::cvtColor(img, gris, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(gris, gris, cv::Size(5, 5), 0);
    cv::Canny(gris, bordes, 50, 150);

    cv::imshow("Original", img);
    cv::imshow("Bordes", bordes);
    cv::waitKey(0);
    return 0;
}
