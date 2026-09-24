// ejemplo5_contornos.cpp
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    cv::Mat binaria;
    cv::threshold(img, binaria, 127, 255, cv::THRESH_BINARY);

    std::vector<std::vector<cv::Point>> contornos;
    cv::findContours(binaria, contornos, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat salida;
    cv::cvtColor(img, salida, cv::COLOR_GRAY2BGR);

    for (const auto& c : contornos) {
        cv::Moments m = cv::moments(c);
        if (m.m00 == 0) continue;
        cv::Point centro(m.m10 / m.m00, m.m01 / m.m00);
        cv::drawContours(salida, std::vector<std::vector<cv::Point>>{c}, -1, cv::Scalar(0,255,0), 2);
        cv::circle(salida, centro, 4, cv::Scalar(0,0,255), -1);
    }

    cv::imshow("Contornos y centroides", salida);
    cv::waitKey(0);
    return 0;
}
