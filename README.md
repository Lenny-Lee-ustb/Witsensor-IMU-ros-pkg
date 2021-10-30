## wt931 IMU解算包
适用设备：
维特智能品牌的IMU，目前已测试wt931/wt906型号(Ubuntu20.04&noetic)

脚本详情：
1. Python版本：
  - IMU_pub.py 含有ROS通讯功能，一般通过launch文件启动
  - WitSensor.py 原始解算脚本，可以在终端看到输出

2. C++版本
  - 与WitSensor.py一样的功能，由于库文件年久失修，高波特率的情况下可能无法通信（不建议使用）

使用方法：
1. 启动一个IMU（0号设备）：

    source devel/setup.bash 

    roslaunch wt931 Wt906_0.launch

2. 启用四个IMU：

    source devel/setup.bash 

    roslaunch wt931 Wt906_all.launch

## NOTICE
    多个IMU插入同一台电脑会存在设备号相同的情况，因此ttyUSB的编号可能会有所不同。如果需要绑定设备的别名，请Google寻找解决方法。

    launch文件中的参数文件并非一成不变，可以根据项目需要进行更改。

    《WT931使用说明书V1.1》为官方的说明文档，可以查找初始校准等操作。