the project has build problems, when i try to use tft_espi library to initialize the project my display using lv_tft_espi_create
function after i set LV_USE_TFT_ESPI to 1 inside lv_conf.h it causes include errors in header and source files of my components
such for example here : 
/components/lvgl/src/drivers/display/tft_espi/lv_tft_espi.cpp:12:10: fatal error: TFT_eSPI.h: No such file or directory
   12 | #include <TFT_eSPI.h>
if i fix this using include_directories in main project cmake file this error goes and another pops 
i failed to find the problem and i am stuck 

i am using : 
board esp32s3 
esp idf version 5.1.4
arduino esp32 version 3.0.4
lvgl version 9.1.1
TFT_eSPI 2.5.43