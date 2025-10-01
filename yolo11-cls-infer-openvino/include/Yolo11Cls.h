#ifndef YOLO11CLS_YOLO11CLS_H
#define YOLO11CLS_YOLO11CLS_H

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <memory>
#include <random>
#include <sstream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <openvino/openvino.hpp>

#include "Yolo11ClsInfo.h"

/// @brief The Yolo11Cls class
class Yolo11Cls {
public:

    /// @brief Constructor of Yolo11Cls
    /// @param init_res_files_dir: folder directory for resources files
    Yolo11Cls(const char* init_res_files_dir);

    /// @brief Destructor of Yolo11Cls
    ~Yolo11Cls();

    /// @brief Infer yolo11(classify) for the given information and input image
    /// @param in_img: input image data
    /// @param in_width: width of input image
    /// @param in_height: height of input image
    /// @param out_buf: output buffer
    /// @return Return code. Negative values indicate errors, while zero indicates success.
    Yolo11ClsRetCode InferYolo11Cls(
        const unsigned char* in_img, int in_width, int in_height,
        const unsigned char* out_buf);

private:

    std::string res_files_dir;
    std::string yolo11_cls_path;

    /// @brief Load input image
    /// @param in_img: Input image data
    /// @param in_width: Width of input image
    /// @param in_height: Height of input image
    /// @param out_buf: Output buffer
    /// @return Return code. Negative values indicate errors, while zero indicates success.
    Yolo11ClsRetCode RunYolo11Cls(const unsigned char* in_img, int in_width, int in_height, const unsigned char* out_buf);
};


#endif // YOLO11CLS_YOLO11CLS_H
