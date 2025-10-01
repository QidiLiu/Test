#ifndef YOLO11CLS_YOLO11CLSAPI_H
#define YOLO11CLS_YOLO11CLSAPI_H

#include "Yolo11ClsGlobal.h"
#include "Yolo11ClsInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

    /// @brief Get yolo11(classify) version information
    /// @param version: Buffer to store version string
    /// @param buffer_size: Size of the version buffer
    /// @return Return code. Negative values indicate errors, while zero indicates success.
    YOLO11CLS_API Yolo11ClsRetCode GetYolo11ClsVersion(char* version, int buffer_size);

    /// @brief Create yolo11(classify) inferencer
    /// @param handle: ptr to yolo11(classify) Handle
    /// @param res_files_dir: folder directory for resources files
    /// @return Return code. Negative values indicate errors, while zero indicates success.
    YOLO11CLS_API Yolo11ClsRetCode CreateYolo11ClsInferencer(
        Yolo11ClsHandle* handle,
        const char* res_files_dir);

    /// @brief Destroy yolo11(classify) inferencer and release resources
    /// @param handle: ptr to yolo11(classify) Handle
    /// @return Return code. Negative values indicate errors, while zero indicates success.
    YOLO11CLS_API Yolo11ClsRetCode DestoryYolo11ClsInferencer(Yolo11ClsHandle* handle);

    /// @brief Infer yolo11(classify) input image
    /// @param handle: yolo11(classify) Handle
    /// @param in_img: input image data
    /// @param in_width: width of input image
    /// @param in_height: height of input image
    /// @param out_buf: output buffer
    /// [Time] Input image w * h * channels, single call time consuming *** [ms]
    /// @return Return code. Negative values indicate errors, while zero indicates success.
    YOLO11CLS_API Yolo11ClsRetCode InferYolo11Cls(
        Yolo11ClsHandle handle,
        const unsigned char* in_img, int in_width, int in_height,
        const unsigned char* out_buf);

#ifdef __cplusplus
}
#endif

#endif // YOLO11CLS_YOLO11CLSAPI_H
