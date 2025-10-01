#ifndef YOLO11CLS_YOLO11CLSGLOBAL_H
#define YOLO11CLS_YOLO11CLSGLOBAL_H

#if defined(_MSC_VER) || defined(WIN64) || defined(_WIN64) || defined(__WIN64__) || defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#  define Q_DECL_EXPORT __declspec(dllexport)
#  define Q_DECL_IMPORT __declspec(dllimport)
#else
#  define Q_DECL_EXPORT     __attribute__((visibility("default")))
#  define Q_DECL_IMPORT     __attribute__((visibility("default")))
#endif

#if defined(YOLO11CLS_LIBRARY)
#  define YOLO11CLS_API Q_DECL_EXPORT
#else
#  define YOLO11CLS_API Q_DECL_IMPORT
#endif

#endif // YOLO11CLS_YOLO11CLSGLOBAL_H
