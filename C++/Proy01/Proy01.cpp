// Ejemplo1_mostrar_imagen.cpp
// Para la compilación se ejecuta en consola:
// Para compilar
// g++ ejemplo1_mostrar_imagen.cpp -o ejemplo1 `pkg-config --cflags --libs opencv4`
// Para la ejecución
// ./ejemplo1 foto.jpg
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
