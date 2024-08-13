
#include <Arduino.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <lvgl.h>
#include "ui.h"
#include <SPI.h>
#include <esp_log.h>

#define LV_CONF_INCLUDE_SIMPLE 1

const char TAG[] = "main";

static const uint16_t screenWidth = 128;
static const uint16_t screenHeight = 160;

TFT_eSPI tft = TFT_eSPI(); // Invoke library, pins defined in User_Setup.h

// Set to your screen resolution and rotation
#define TFT_HOR_RES 128
#define TFT_VER_RES 160
#define TFT_ROTATION LV_DISPLAY_ROTATION_0

// LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes
#define DRAW_BUF_SIZE (TFT_HOR_RES * TFT_VER_RES / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

// LVGL calls it when a rendered image needs to copied to the display
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{

    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    // tft.pushColors((uint16_t *)&px_map, w * h, true);
    tft.pushPixels(&px_map, w * h);
    tft.endWrite();

    // Call it to tell LVGL you are ready
    lv_display_flush_ready(disp);
}

// use Arduinos millis() as tick source
static uint32_t my_tick(void)
{
    return millis();
}

void setup()
{
    tft.begin();
    tft.setRotation(0);
    tft.fillScreen(TFT_BLACK); // Clear the screen to black
    // Initialize LVGL
    delay(100);
    lv_init();
    // Set a tick source so that LVGL will know how much time elapsed.
    lv_tick_set_cb(my_tick);

    lv_display_t *disp;

    // disp = lv_display_create(TFT_HOR_RES, TFT_VER_RES);
    // lv_display_set_flush_cb(disp, my_disp_flush);
    // lv_display_set_buffers(disp, draw_buf, NULL, sizeof(draw_buf), LV_DISPLAY_RENDER_MODE_PARTIAL);

    // TFT_eSPI can be enabled lv_conf.h to initialize the display in a simple way
    disp = lv_tft_espi_create(TFT_HOR_RES, TFT_VER_RES, draw_buf, sizeof(draw_buf));
    lv_display_set_rotation(disp, TFT_ROTATION);

    lv_obj_t *label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Hello Arduino, I'm LVGL!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    tft.fillScreen(TFT_BLACK);
    tft.printf("hello world !!!");
    ui_init();

    Serial.println("Setup done");
}
void loop()
{
    lv_timer_handler();
    delay(5);
}

extern "C" void app_main()
{
    initArduino(); // Initialize Arduino framework
    setup();
    while (true)
    {
        loop();
        delay(1); // Yield control to the system
    }
}
