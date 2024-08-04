// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 9.1.0
// Project name: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C"
{
#endif

// #include "C://Users//twigy//OneDrive//Bureau//esp_idf_projects//espi_disp//managed_components//lvgl__lvgl//lvgl.h"
#include <lvgl.h>
#include "ui_helpers.h"
#include "ui_events.h"

    // SCREEN: ui_Screen1
    void
    ui_Screen1_screen_init(void);
    extern lv_obj_t *ui_Screen1;
    extern lv_obj_t *ui_pressure;
    extern lv_obj_t *ui_temperature;
    extern lv_obj_t *ui_humidity;
    extern lv_obj_t *ui_Label1;
    extern lv_obj_t *ui_Label2;
    extern lv_obj_t *ui_Label3;
    extern lv_obj_t *ui_Label4;
    extern lv_obj_t *ui_bar;
    extern lv_obj_t *ui____initial_actions0;

    LV_IMG_DECLARE(ui_img_no8hx_png); // assets/NO8hx.png

    void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
