/// @file Yolo11ClsApi.cpp
/// @brief Yolo11(classify) API Implementation
/// 
/// This file implements the C-style API for yolo11(classify) functionality.
/// It provides a wrapper around the C++ implementation (Yolo11Cls).

#include "include/Yolo11ClsApi.h"
#include "include/Yolo11Cls.h"
#include <filesystem>

Yolo11ClsRetCode GetYolo11ClsVersion(char* version, int buffer_size) {
    if (version == NULL || buffer_size <= 0) {
        return Yolo11ClsRet_UNKNOWN;
    }

    const char* version_str = "0.0.0";
    if (strlen(version_str) >= static_cast<size_t>(buffer_size)) {
        return Yolo11ClsRet_UNKNOWN;
    }

    strncpy(version, version_str, buffer_size - 1);
    version[buffer_size - 1] = '\0';

    return Yolo11ClsRet_SUCCESS;
}


Yolo11ClsRetCode CreateYolo11ClsInferencer(
    Yolo11ClsHandle* handle,
    const char* res_files_dir
) {
    // Check input parameters
    if (!std::filesystem::exists(res_files_dir)) {
        std::cout << "[ERROR] res_files_dir does not exist. res_files_dir: " << res_files_dir << std::endl;
        return Yolo11ClsRet_INVALID_PATH;
    }

    // Create Yolo11Cls C++ interface instance using static factory method
    Yolo11Cls* yolo11_cls_ptr = new Yolo11Cls(res_files_dir);
    if (yolo11_cls_ptr == NULL) {
        return Yolo11ClsRet_UNKNOWN;
    }

    *handle = yolo11_cls_ptr;
    return Yolo11ClsRet_SUCCESS;
}


Yolo11ClsRetCode DestoryYolo11ClsInferencer(Yolo11ClsHandle* handle) {
    Yolo11Cls* yolo11_cls_ptr = reinterpret_cast<Yolo11Cls*>(*handle);
    if (yolo11_cls_ptr == NULL) {
        return Yolo11ClsRet_UNKNOWN;
    }

    delete yolo11_cls_ptr;
    *handle = NULL;
    return Yolo11ClsRet_SUCCESS;
}


Yolo11ClsRetCode InferYolo11Cls(
    Yolo11ClsHandle handle,
    const unsigned char* in_img, int in_width, int in_height,
    const unsigned char* out_buf) {
    Yolo11Cls* yolo11_cls_ptr = reinterpret_cast<Yolo11Cls*>(handle);
    if (yolo11_cls_ptr == NULL) {
        return Yolo11ClsRet_UNKNOWN;
    }

    return yolo11_cls_ptr->InferYolo11Cls(in_img, in_width, in_height, out_buf);
}

