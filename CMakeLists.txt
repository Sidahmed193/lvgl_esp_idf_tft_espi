# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

#include_directories(components/TFT_eSPI  components/arduino components/lvgl components/lvgl_ui_files) 
#set(EXTRA_COMPONENT_DIRS components/TFT_eSPI components/arduino components/lvgl components/lvgl_ui_files)
#LVGL custom config file setup
#idf_build_set_property(COMPILE_OPTIONS "-DLV_CONF_INCLUDE_SIMPLE=1" APPEND)
#idf_build_set_property(COMPILE_OPTIONS "-I../main" APPEND)
add_definitions(-DLV_CONF_INCLUDE_SIMPLE)


include_directories(components/lvgl_ui_files)
include_directories(components/TFT_eSPI)
include_directories(components)
include_directories(managed_components/espressif__arduino-esp32/cores/esp32)
include_directories(managed_components/espressif__arduino-esp32/variants/esp32s3)


#add_subdirectory(managed_components/lvgl__lvgl)
#add_subdirectory(managed_components/espressif__arduino-esp32)
#add_subdirectory(componenets/TFT_eSPI)
#add_subdirectory(componenets/lvgl_ui_files)


#include_directories(components/arduino/cores/esp32)
#include_directories(components/arduino/variants/esp32s3)


#add_definitions(-DLV_CONF_INCLUDE_SIMPLE)
idf_build_set_property(COMPILE_OPTIONS "-Wno-missing-field-initializers" APPEND)

#set(EXTRA_COMPONENT_DIRS components/lvgl components/TFT_eSPI components/lvgl_ui_files)
project(espi_disp)

