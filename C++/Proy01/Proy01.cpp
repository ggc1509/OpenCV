// ejemplo1_mostrar_imagen.cpp
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <ruta_imagen>" << std::endl;
        return -1;
    }

    cv::Mat imagen = cv::imread(argv[1], cv::IMREAD_COLOR);
    if (imagen.empty()) {
        std::cerr << "No se pudo cargar la imagen" << std::endl;
        return -1;
    }

    std::cout << "Dimensiones: " << imagen.cols << "x" << imagen.rows << std::endl;
    cv::imshow("Imagen", imagen);
    cv::waitKey(0);
    return 0;
}
