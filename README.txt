Hello everyone,

I'm encountering build problems in my project when I try to use the TFT_eSPI library 
to initialize my display with the lv_tft_espi_create function. After setting LV_USE_TFT_ESPI to 1 inside lv_conf.h, 
I get include errors in the header and source files of my components. For example:
/components/lvgl/src/drivers/display/tft_espi/lv_tft_espi.cpp:12:10: fatal error: TFT_eSPI.h: No such file or directory
   12 | #include <TFT_eSPI.h>
If I fix this using include_directories in the main project CMake file, this error goes away, but another one pops up. I haven't been able to locate the root of the problem and would appreciate any help.

Here are the details of my setup:

Board: ESP32-S3
TFT Screen IC: ST7735
ESP-IDF Version: 5.1.4
Arduino ESP32 Version: 3.0.4
LVGL Version: 9.1.1
TFT_eSPI Version: 2.5.43
Thanks in advance for your assistance!