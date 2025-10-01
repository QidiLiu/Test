from ultralytics import YOLO

if __name__ == '__main__':
    training_idx = ''
    task = 'classify'  # 'detect', 'classify', 'segment'

    model = YOLO(f'runs/{task}/train{training_idx}/weights/best.pt')
    model.export(format='onnx')
    onnx_model = YOLO(f'runs/{task}/train{training_idx}/weights/best.onnx')
