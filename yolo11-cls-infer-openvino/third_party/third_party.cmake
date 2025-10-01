# OpenCV-4.1.0
set(OpenCV_DIR C:/Users/ben/Lib/opencv-install/x64/vc17/lib)
find_package(OpenCV CONFIG REQUIRED)
message(STATUS "[INFO] Using OpenCV-${OpenCV_VERSION}")
target_include_directories(${LIB_API} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${LIB_API} ${OpenCV_LIBRARIES})

# OpenVINO
set(OpenVINO_DIR C:/Users/ben/Lib/openvino_2025.3.0/runtime/cmake)
find_package(OpenVINO CONFIG REQUIRED)
message(STATUS "[INFO] Using OpenVINO-${OpenVINO_VERSION}")
target_link_libraries(${LIB_API} openvino::runtime)
