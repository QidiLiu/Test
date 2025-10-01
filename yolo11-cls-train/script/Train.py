from ultralytics import YOLO

if __name__ == '__main__':
    model = YOLO("yolo11n-cls.pt")

    results = model.train(
        data="_res/dataset/***",
        batch=32, epochs=30, imgsz=256,
        degrees=180, translate=0.5, shear=15, perspective=0.0005, flipud=0.5, fliplr=0.5
    )

    metrics = model.val()
    print(metrics)
