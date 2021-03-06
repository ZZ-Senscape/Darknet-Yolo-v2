# Darknet Yolo安装与测试记录

**Author:** Zeyu Chen

**Email:** iszeyu.chen@gmail.com

**Date:** 2017.2.18

## 1. Darknet 简介
* [官网](https://pjreddie.com/)
* [Giuthub](https://github.com/pjreddie/darknet)

## 2. Yolo简介
Yolo v1/v2(-tiny) 都是基于darknet，网络的不同是因为.cfg配置文件不同。

**论文:**
* Yolo v1 - [You Only Look Once: Unified, Real-Time Object Detection](https://arxiv.org/abs/1506.02640)
* Yolo v2 - [YOLO9000: Better, Faster, Stronger](https://arxiv.org/abs/1612.08242)

## 3. Darknet安装(Ubuntu系统)
### 3.1 Nvidia私有驱动 安装配置 @HP-OMEN-17-GTX1070版
驱动安装方法有四种：

1. Terminal添加源安装
2. Ubuntu软件管理器安装
3. 从官网下载.deb文件安装
4. 从官网下载.run文件安装

适用于本机@HP-OMEN-17-GTX1070版 最简单的方法是（1）

#### **安装步骤:**
#### 3.1.1 BIOS中关闭 安全启动 Secure Boot 项

#### 3.1.2 查找合适的驱动版本
[Nvidia驱动](http://www.geforce.cn/drivers)

#### 3.1.3 添加驱动源并安装
Terminal:

    sudo add-apt-repository ppa:graphics-drivers/ppa
    sudo apt-get update
    sudo apt-get install nvidia-375
安装完成后

    sudo reboot

**注：** 这种方法不需要将开源nouveau设为黑名单项，不需要修改环境配置

### 3.2 CUDA8 安装配置

#### 3.2.1 下载[.run](https://developer.nvidia.com/cuda-downloads )文件

#### 3.2.2 Terminal:

    $ sudo sh cuda_8.0.27_linux.run

询问是否安装Nvidia驱动，选择n。

询问是否安装Cuda Samples，选择Y。

#### 3.2.3 配置：
声明环境变量，并将其写入到 ~/.bashrc 的尾部:

    $ export PATH=/usr/local/cuda-8.0/bin${PATH:+:${PATH}}
    $ export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}

#### 3.2.4 测试：
    $ nvidia-smi
    $ nvcc -V

### 3.3 CUDNN


### 3.4 OpenCV 2.4.X
注：darknet-OpenCV3.X 编译报错，应该是OpenCV3.X调整了函数和文件导致的

#### 3.4.1 安装依赖项
Terminal：

    $ sudo apt-get install build-essential libgtk2.0-dev libavcodec-dev libavformat-dev libjpeg62-dev libtiff4-dev cmake libswscale-dev libjasper-dev cmake pkg-config

#### 3.4.2 下载[OpenCV](http://opencv.org/downloads.html)源码
Terminal：

    $ cd 进入OpenCV目录
    $ cmake .
    $ make
    $ sudo make install

#### 3.4.3 配置环境
Terminal:

    $ sudo gedit /etc/ld.so.conf.d/opencv.conf

末尾添加:

    /usr/local/lib

#### 3.4.3.2

    $ sudo ldconfig

#### 3.4.3.3

    $ sudo gedit /etc/bash.bashrc

末尾添加:

    export  PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig

### 3.4 IDE - Clion
#### 3.4.1 [下载地址](http://www.jetbrains.com/clion/)
#### 3.4.2 解压后按照说明文档安装
#### 3.4.3 [获取注册码](http://idea.lanyus.com/)
#### 3.4.4 配置
##### 3.4.4.1 创建新项目
##### 3.4.4.2 编辑CMakeLists.txt
project(你的项目名称)下面添加

    find_package( OpenCV REQUIRED );

最后添加

    target_link_libraries( 项目名称 ${OpenCV_LIBS} )

### 3.5 安装编译[darknet](https://pjreddie.com/darknet/install/)

可选项 -OpenCV -CUDNN -CUDA

[GPU ARCH参数查询](https://developer.nvidia.com/cuda-gpus)

### 3.5 编译测试 Yolo
* [Yolo v1](http://pjreddie.com/darknet/yolov1/)
* [Yolo v2](https://pjreddie.com/darknet/yolo/)
