# stationG
我当年为某石油某气田写的东西，很简单，串口接收数据，udp发送出去，串口的数据有开始和结束标志位
标志位为 ‘～’ 开始和结束都是，所以就造成了一些麻烦，在程序中可以看到我是如何处理的

采用Qt5.4.1的串口库，采用阻塞式串口读取