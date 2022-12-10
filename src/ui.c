// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Roller2;
lv_obj_t * ui_Slider1;
lv_obj_t * ui_Bar1;
lv_obj_t * ui_Switch1;
lv_obj_t * ui_Screen2;
lv_obj_t * ui_Chart3;
lv_obj_t * ui_Colorwheel3;
lv_obj_t * menu;
lv_obj_t * back_btn;
lv_obj_t * sub_1_page;
lv_obj_t * sub_2_page;

///////////////////// TEST LVGL SETTINGS ////////////////////
// #if LV_COLOR_DEPTH != 32
//     #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
// #endif
// #if LV_COLOR_16_SWAP !=0
//     #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
// #endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{

    // ui_Screen1

    ui_Screen1 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Roller2

    ui_Roller2 = lv_roller_create(ui_Screen1);
    lv_roller_set_options(ui_Roller2, "Option 1\nOption 2\nOption 3", LV_ROLLER_MODE_NORMAL);

    lv_obj_set_height(ui_Roller2, 100);
    lv_obj_set_width(ui_Roller2, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Roller2, -57);
    lv_obj_set_y(ui_Roller2, -91);

    lv_obj_set_align(ui_Roller2, LV_ALIGN_CENTER);

    // ui_Slider1

    ui_Slider1 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Slider1, 0, 100);

    lv_obj_set_width(ui_Slider1, 150);
    lv_obj_set_height(ui_Slider1, 10);

    lv_obj_set_x(ui_Slider1, -27);
    lv_obj_set_y(ui_Slider1, -17);

    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);

    // ui_Bar1

    ui_Bar1 = lv_bar_create(ui_Screen1);
    lv_bar_set_range(ui_Bar1, 0, 100);
    lv_bar_set_value(ui_Bar1, 25, LV_ANIM_OFF);

    lv_obj_set_width(ui_Bar1, 150);
    lv_obj_set_height(ui_Bar1, 10);

    lv_obj_set_x(ui_Bar1, -21);
    lv_obj_set_y(ui_Bar1, 60);

    lv_obj_set_align(ui_Bar1, LV_ALIGN_CENTER);

    // ui_Switch1

    ui_Switch1 = lv_switch_create(ui_Screen1);

    lv_obj_set_width(ui_Switch1, 50);
    lv_obj_set_height(ui_Switch1, 25);

    lv_obj_set_x(ui_Switch1, -11);
    lv_obj_set_y(ui_Switch1, 110);

    lv_obj_set_align(ui_Switch1, LV_ALIGN_CENTER);

}
void ui_Screen2_screen_init(void)
{

    // ui_Screen2

    ui_Screen2 = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Chart3

    ui_Chart3 = lv_chart_create(ui_Screen2);

    lv_obj_set_width(ui_Chart3, 180);
    lv_obj_set_height(ui_Chart3, 100);

    lv_obj_set_x(ui_Chart3, -14);
    lv_obj_set_y(ui_Chart3, -89);

    lv_obj_set_align(ui_Chart3, LV_ALIGN_CENTER);

    // ui_Colorwheel3

    ui_Colorwheel3 = lv_colorwheel_create(ui_Screen2, true);

    lv_obj_set_width(ui_Colorwheel3, 100);
    lv_obj_set_height(ui_Colorwheel3, 100);

    lv_obj_set_x(ui_Colorwheel3, -18);
    lv_obj_set_y(ui_Colorwheel3, 52);

    lv_obj_set_align(ui_Colorwheel3, LV_ALIGN_CENTER);

}

void lv_example_menu_3(void)
{
    /*Create a menu object*/
    // lv_obj_t * menu = lv_menu_create(lv_scr_act());
    menu = lv_menu_create(lv_scr_act());
    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_center(menu);

    /*Modify the header*/
    lv_obj_t * back_btn = lv_menu_get_main_header_back_btn(menu);
    lv_obj_t * back_btn_label = lv_label_create(back_btn);
    lv_label_set_text(back_btn_label, "Back");

    lv_obj_t * cont;
    lv_obj_t * label;

    /*Create sub pages*/
    lv_obj_t * sub_1_page = lv_menu_page_create(menu, "Page 1");

    cont = lv_menu_cont_create(sub_1_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "Hello, I am hiding here");

    lv_obj_t * sub_2_page = lv_menu_page_create(menu, "Page 2");

    cont = lv_menu_cont_create(sub_2_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "Hello, I am hiding here");

    lv_obj_t * sub_3_page = lv_menu_page_create(menu, "Page 3");

    cont = lv_menu_cont_create(sub_3_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "Hello, I am hiding here");

    /*Create a main page*/
    lv_obj_t * main_page = lv_menu_page_create(menu, NULL);

    cont = lv_menu_cont_create(main_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "Item 1 (Click me!)");
    lv_menu_set_load_page_event(menu, cont, sub_1_page);

    cont = lv_menu_cont_create(main_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "Item 2 (Click me!)");
    lv_menu_set_load_page_event(menu, cont, sub_2_page);

    cont = lv_menu_cont_create(main_page);
    label = lv_label_create(cont);
    lv_label_set_text(label, "Item 3 (Click me!)");
    lv_menu_set_load_page_event(menu, cont, sub_3_page);

    lv_menu_set_page(menu, sub_3_page);
}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui_Screen2_screen_init();
    lv_example_menu_3();
    lv_disp_load_scr(menu);
}

