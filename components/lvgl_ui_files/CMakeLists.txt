SET(SOURCES ui_Screen1.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    ui_img_no8hx_png.c)

#add_library(ui ${SOURCES})

#set(COMPONENT_SRCS ${SOURCES})
#set(COMPONENT_ADD_INCLUDEDIRS ".")

#register_component()

idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "." REQUIRES lvgl)