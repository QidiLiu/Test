#include <opencv2/opencv.hpp>

#include "include/Yolo11ClsApi.h"

int main() {
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_ERROR);
    Yolo11ClsRetCode ret = Yolo11ClsRet_UNKNOWN;
    Yolo11ClsHandle handle = NULL;

    /// Get Yolo11(classify) version
    char version[42] = {};
    ret = GetYolo11ClsVersion(version, sizeof(version));
    if (ret != Yolo11ClsRet_SUCCESS) { std::cerr << "[ERROR] Failed to get Yolo11(classify) version. Error code: " << ret << std::endl; return EXIT_FAILURE; }
    std::cout << "[DEBUG] Yolo11(classify) version: " << version << std::endl;

    /// Create Yolo11(classify) inferencer
    ret = CreateYolo11ClsInferencer(&handle, "C:/Users/ben/Test/yolo11-cls-infer-openvino/_res/model");
    if (ret != Yolo11ClsRet_SUCCESS) { std::cerr << "[ERROR] Failed to create Yolo11(classify) inferencer. Error code: " << ret << std::endl; return EXIT_FAILURE; }

    /// Infer Yolo11(classify)

    const std::string in_path = "C:/Users/ben/Test/yolo11-cls-infer-openvino/_res/img/test_img/test_0.png";
    std::cout << "[INFO] Processing file: " << in_path << std::endl;
    cv::Mat in_img = cv::imread(in_path);
    if (in_img.empty()) { std::cerr << "[ERROR] Failed to read input image." << std::endl; return EXIT_FAILURE; }
    unsigned char* result_buf = nullptr;
    ret = InferYolo11Cls(
        handle,
        in_img.data, in_img.cols, in_img.rows,
        result_buf);
    if (ret != Yolo11ClsRet_SUCCESS) { std::cerr << "[ERROR] Failed to infer Yolo11(classify). Error code: " << ret << std::endl; return EXIT_FAILURE; }

    /// Destory Yolo11(classify) inferencer
    ret = DestoryYolo11ClsInferencer(&handle);
    if (ret != Yolo11ClsRet_SUCCESS) { std::cerr << "[ERROR] Failed to destory Yolo11(classify) inferencer. Error code: " << ret << std::endl; return EXIT_FAILURE; }

    if (ret == Yolo11ClsRet_SUCCESS) { std::cout << "[DEBUG] Test finished." << std::endl; }

    std::cout << "[DEBUG] Return code: " << ret << std::endl;

    return EXIT_SUCCESS;
}

