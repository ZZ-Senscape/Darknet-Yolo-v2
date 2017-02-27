p# Darknet-Yolo v2 训练自己的数据

**Author:** Zeyu Chen
**Email:** iszeyu.chen@gmail.com

## 0. 参考资料
- Yolo v1
http://guanghan.info/blog/en/my-works/train-yolo
- Yolo v2
http://lib.csdn.net/article/deeplearning/57863?knId=1726
https://github.com/AlexeyAB/darknet#how-to-train-to-detect-your-custom-objects



## 1. 搜集样本集
### 1.1 基本要求:
> \>300张/class

## 2. 标签
### 2.1 工具: [BBox-Label-Tool](https://github.com/puzzledqs/BBox-Label-Tool)
### 2.2 环境配置:
> python 2.7

> PIL-1.1.7

**注:** PIL已经停止更新,如果Terminal:

    pip install PIL

则返回:

    Collecting PIL
    Could not find a version that satisfies the requirement PIL (from versions: )
    No matching distribution found for PIL

现在以pillow替代PIL

    pip install pillow

### 2.3 使用说明
* 目录结构：图片目录名images,标签目录名labels,图像目录下各类别目录名要以001,002,003,...的格式命名.
* 图片格式: .JPEG (大写)
* 图片命名: 001 ~ 0XX; 或者0001 ~ 0XXX
* 快捷键:   a,d前后切换图像

### 2.4 Label格式转换

转换前

    1
    116 89 537 386

转换后

    0 0.18125 0.185417 0.657813 0.61875

#### 2.4.1 Yolo标签格式
    <object-class> <x> <y> <width> <height> (以比例形式表示)

#### 2.4.2 使用LabelConvert.cpp进行标签格式转换

## 3. 训练
### 3.1 训练所需文件

* train.txt
* test.txt
* 图片和对应的label.txt放在同一文件夹下

#### 3.1.1 train.txt
存放所有用于训练图像的绝对路径
例如

    /home/chen/Program/Train/image/0001.JPEG
    /home/chen/Program/Train/image/0002.JPEG
    /home/chen/Program/Train/image/0003.JPEG
    /home/chen/Program/Train/image/0004.JPEG
    /home/chen/Program/Train/image/0005.JPEG
    /home/chen/Program/Train/image/0006.JPEG
    /home/chen/Program/Train/image/0007.JPEG
    /home/chen/Program/Train/image/0008.JPEG
    /home/chen/Program/Train/image/0009.JPEG
    /home/chen/Program/Train/image/0010.JPEG
    ......

#### 3.1.2 test.txt
存放所有用于测试图像的绝对路径
例如

    /home/chen/Program/Train/image/0311.JPEG
    /home/chen/Program/Train/image/0312.JPEG
    /home/chen/Program/Train/image/0313.JPEG
    /home/chen/Program/Train/image/0314.JPEG
    /home/chen/Program/Train/image/0315.JPEG
    /home/chen/Program/Train/image/0316.JPEG
    /home/chen/Program/Train/image/0317.JPEG
    /home/chen/Program/Train/image/0318.JPEG
    /home/chen/Program/Train/image/0319.JPEG
    /home/chen/Program/Train/image/0320.JPEG
    ......

### 3.2 修改代码
#### 3.2.1 .names文件
在 darknet/data 文件下新建 helipad.names
这个文件中的行数要和类数一致，每一行都是一个类别的名字。
我的只有一类,所以:

    helipad

#### 3.2.2 .data文件
复制 cfg/voc.data,重命名为 helipad.data
修改

    classes = 1
    train  = train.txt
    valid  = test.txt
    names = data/helipad.names
    backup = backup

#### 3.2.3 .cfg文件
复制 cfg/yolo_voc.cfg,重命名为 helipad.cfg
修改

    [region]中
    class = 1

    [region]上方第一个的[convolution]中
    filters = 30

**注**: filters参数计算方法:
> (classes + coords + 1) * num

在yolo_voc.vfg中:
coords = 4, num = 5

附: [关于filters参数的讨论 - Google Group](https://groups.google.com/forum/#!topic/darknet/B4rSpOo84yg)

#### 3.2.4
