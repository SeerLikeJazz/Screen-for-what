# Screen-for-what
基于lvgl的小屏幕驱动，用于DIY  

## 更新
### 22.06.19 
- Cmakelists.txt文件记得备份，cubeMX重新配置后会被覆盖，暂时未解决
- cmake-build-debug文件夹删去，不然clone下来cmake编译有问题
- **LV_COLOR_16_SWAP** 使能，Swap the 2 bytes of RGB565 color. Useful if the display has a 8 bit interface (e.g. SPI)  
- 完成LVGL库，ST7789驱动移植，135 x 240像素小屏幕，背景显示红色

