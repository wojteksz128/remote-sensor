#ifndef rs_screen_lcdscreen
#define rs_screen_lcdscreen

#include <LiquidCrystal_I2C.h>

class LCDScreen : public Print {
  private:
    LiquidCrystal_I2C lcd;
  public:   
    LCDScreen(); 

    void clear();
    void home();
    void noDisplay();
    void display();
    void noBlink();
    void blink();
    void noCursor();
    void cursor();
    void scrollDisplayLeft();
    void scrollDisplayRight();
    void printLeft();
    void printRight();
    void leftToRight();
    void rightToLeft();
    void shiftIncrement();
    void shiftDecrement();
    void noBacklight();
    void backlight();
    void autoscroll();
    void noAutoscroll();
    void setCursor(uint8_t, uint8_t); 
#if defined(ARDUINO) && ARDUINO >= 100
    virtual size_t write(uint8_t);
#else
    virtual void write(uint8_t);
#endif
    void command(uint8_t);

    ////compatibility API function aliases
    void blink_on();						// alias for blink()
    void blink_off();       					// alias for noBlink()
    void cursor_on();      	 					// alias for cursor()
    void cursor_off();      					// alias for noCursor()
    void setBacklight(uint8_t new_val);				// alias for backlight() and nobacklight()
    void printstr(const char[]);

    ////Unsupported API functions (not implemented in this library)
    // uint8_t status();
    // void setContrast(uint8_t new_val);
    // uint8_t keypad();
    // void setDelay(int,int);
    // void on();
    // void off();
    // uint8_t init_bargraph(uint8_t graphtype);
    // void draw_horizontal_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
    // void draw_vertical_graph(uint8_t row, uint8_t column, uint8_t len,  uint8_t pixel_col_end);
};

#endif  // rs_screen_lcdscreen