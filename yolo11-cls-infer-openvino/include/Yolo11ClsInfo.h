#ifndef YOLO11CLS_YOLO11CLSINFO_H
#define YOLO11CLS_YOLO11CLSINFO_H

/// @file Yolo11ClsInfo.h
/// @brief Basic data structures and return codes for yolo11(classify) API
/// @version
/// @date
///
/// This header file defines the basic data structures and return codes used
/// in the yolo11(classify) API.

#ifdef __cplusplus
extern "C" {
#endif

    /// @brief Opaque handle for yolo11(classify) inferences
    /// 
    /// This handle is created by createYolo11ClsInferencer() and must be destroyed
    /// using destoryYolo11ClsInferencer() when no longer needed.
    typedef void* Yolo11ClsHandle;

    /// @brief Return codes for yolo11(classify) inferences
    /// 
    /// These codes indicate the result of yolo11(classify) inferences.
    /// Negative values indicate errors, while zero indicates success.
    typedef enum {
        Yolo11ClsRet_SUCCESS = 0,              // Operation completed successfully
        Yolo11ClsRet_UNKNOWN = -1,             // Unknown error occurred
        Yolo11ClsRet_INVALID_PTR = -2,         // Invalid pointer of output image
        Yolo11ClsRet_INVALID_PATH = -3,        // Invalid path for resource files
    } Yolo11ClsRetCode;

#ifdef __cplusplus
}
#endif

#endif // YOLO11CLS_YOLO11CLSINFO_H

