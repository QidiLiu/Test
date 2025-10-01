#include "include/Yolo11Cls.h"

Yolo11Cls::Yolo11Cls(const char* init_res_files_dir) :
    res_files_dir(init_res_files_dir) {
    this->yolo11_cls_path = std::string(this->res_files_dir) + "/best.onnx";
}


Yolo11Cls::~Yolo11Cls() {}


Yolo11ClsRetCode Yolo11Cls::InferYolo11Cls(
    const unsigned char* in_img, int in_width, int in_height,
    const unsigned char* out_buf
) { try {
    /// Load image and infer the model
    if (in_img == nullptr) { std::cerr << "[ERROR] Invalid input image" << std::endl; return Yolo11ClsRet_INVALID_PTR; }
    unsigned char* result_buf = nullptr;
    Yolo11ClsRetCode ret_code = this->RunYolo11Cls(in_img, in_width, in_height, result_buf);
    if (ret_code != Yolo11ClsRet_SUCCESS) { return ret_code; }

    return Yolo11ClsRet_SUCCESS;
} catch (...) {
    return Yolo11ClsRet_UNKNOWN;
}}


Yolo11ClsRetCode Yolo11Cls::RunYolo11Cls(const unsigned char* in_img, int in_width, int in_height, const unsigned char* out_buf) {
    /// Load the image
    cv::Mat received_img(in_height, in_width, CV_8UC3);
    const size_t in_data_size = in_width * in_height * 3 * sizeof(unsigned char);
    memcpy(received_img.data, (const void*)in_img, in_data_size);

    /// Initialize model
    ov::Core core;
    std::shared_ptr<ov::Model> yolo11_cls_model = core.read_model(this->yolo11_cls_path);
    ov::CompiledModel yolo11_cls_compiled_model = core.compile_model(yolo11_cls_model, "CPU");

    /// Get input and output shape
    ov::Shape in_shape = yolo11_cls_compiled_model.input().get_shape();
    ov::Shape out_shape = yolo11_cls_compiled_model.output().get_shape();
    std::cout << "[DEBUG] in_shape: " << in_shape << std::endl;
    std::cout << "[DEBUG] out_shape: " << out_shape << std::endl;

    /// Preprocess input image
    cv::resize(received_img, received_img, cv::Size(static_cast<int>(in_shape[2]), static_cast<int>(in_shape[3])), 0, 0, cv::INTER_CUBIC);
    cv::Mat img = received_img.clone();
    received_img.convertTo(received_img, CV_32FC3, 1.0 / 255.0);
    std::vector<cv::Mat> in_channels;
    cv::split(received_img, in_channels);

    /// Convert input image to tensor and set as input to the model
    ov::Tensor in_tensor(ov::element::f32, in_shape);
    std::memcpy(in_tensor.data<float>(), in_channels[0].data, in_channels[0].total() * in_channels[0].elemSize());
    std::memcpy(in_tensor.data<float>() + in_channels[0].total(), in_channels[1].data, in_channels[1].total() * in_channels[1].elemSize());
    std::memcpy(in_tensor.data<float>() + in_channels[0].total() + in_channels[1].total(), in_channels[2].data, in_channels[2].total() * in_channels[2].elemSize());
    ov::InferRequest infer_request = yolo11_cls_compiled_model.create_infer_request();
    infer_request.set_input_tensor(in_tensor);

    /// Run inference
    infer_request.infer();

    /// Get output tensors
    //cv::Tensor out_detect_tensor = infer_request.get_output_tensor(0);
    //cv::Tensor out_proto_tensor = infer_request.get_output_tensor(1);
    //cv::Mat detect_buf(static_cast<int>(out_detect_shape[1]), static_cast<int>(out_detect_shape[2]), CV_32FC1, out_detect_tensor.data<float>()); // [37x1344]
    //cv::Mat proto_buf(static_cast<int>(out_proto_shape[1]), static_cast<int>(out_proto_shape[2] * out_proto_shape[3]), CV_32FC1, out_proto_tensor.data<float>()); // [32x4096]

    return Yolo11ClsRet_SUCCESS;
}

