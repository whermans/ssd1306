/* SSD1306 driver code using WiringPi */

#ifndef INC_WIRINGPI_H_
#define INC_WIRINGPI_H_
#include <wiringPi.h>
#endif

#ifndef INC_SSD1306_H_
#define INC_SSD1306_H_

#define BLACK       0
#define WHITE       1
#define INVERSE     2

#define I2C_ADDRESS 0x3D

#define DISPX       128
#define DISPY       64

typedef volatile uint8_t port_reg;
typedef uint8_t port_mask;

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

struct SSD1306_VARS{
  int8_t SID;
  int8_t SCLK;
  int8_t DC;
  int8_t RST;
  int8_t CS;
};

void init(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST, int8_t CS);
void begin(uint8_t switchvcc, uint8_t i2caddr, int reset);

void command(uint8_t command);
void data(uint8_t data);

void clear_disp();
void invert_disp(uint8_t invert);
void display();

void scroll_right_start(uint8_t start, uint8_t stop);
void scroll_left_start(uint8_t start, uint8_t stop);

void scroll_right_up_start(uint8_t start, uint8_t stop);
void scroll_left_up_start(uint8_t start, uint8_t stop);
void scroll_stop();

void dim(uint8_t contrast);

void draw_px(int16_t x, int16_t y, uint16_t colour);

#endif
