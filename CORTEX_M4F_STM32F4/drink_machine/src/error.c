#include "stm32f429i_discovery_lcd.h"

void reportError(char *str)
{
    sFONT *font;

    font = LCD_GetFont();

    LCD_SetBackColor(LCD_COLOR_BLACK);
    LCD_ClearLine(LCD_PIXEL_HEIGHT - font->Height);

    LCD_SetBackColor(LCD_COLOR_BLUE);

    LCD_DisplayStringLine(LCD_PIXEL_HEIGHT - font->Height, (uint8_t *) str);
    //LCD_DisplayStringLine(20, (uint8_t *) str);

}
