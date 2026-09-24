// ejemplo2_camara.cpp
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0, cv::CAP_V4L2); // índice /dev/video0
    if (!cap.isOpened()) {
        std::cerr << "No se pudo abrir la cámara" << std::endl;
        return -1;
    }

    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    cv::Mat frame;
    while (true) {
        cap >> frame;
        if (frame.empty()) break;
        cv::imshow("Camara en vivo", frame);
        if (cv::waitKey(1) == 27) break; // ESC para salir
    }
    return 0;
}
