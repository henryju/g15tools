
#ifndef _LIBG15_H_
#define _LIBG15_H_

#ifdef __cplusplus
extern "C"
{
#endif
	
  enum
  {
    G15_NO_ERROR = 0,
    G15_ERROR_OPENING_USB_DEVICE,
    G15_ERROR_WRITING_PIXMAP,
    G15_ERROR_TIMEOUT,
    G15_ERROR_READING_USB_DEVICE,
    G15_ERROR_TRY_AGAIN
  };
  
  enum
  {
    G15_LCD_HEIGHT = 43,
    G15_LCD_WIDTH = 160
  };
  
  enum
  {
    G15_LED_M1=1<<0,
    G15_LED_M2=1<<1,
    G15_LED_M3=1<<2,
    G15_LED_MR=1<<3
  };
  
  enum
  {
    G15_CONTRAST_LOW=0,
    G15_CONTRAST_MEDIUM,
    G15_CONTRAST_HIGH    
  };
  
  enum
  {
    G15_BRIGHTNESS_DARK=0,
    G15_BRIGHTNESS_MEDIUM,
    G15_BRIGHTNESS_BRIGHT
  };
  
  enum
  {
    G15_KEY_G1  = 1<<0,
    G15_KEY_G2  = 1<<1,
    G15_KEY_G3  = 1<<2,
    G15_KEY_G4  = 1<<3,
    G15_KEY_G5  = 1<<4,
    G15_KEY_G6  = 1<<5,
    G15_KEY_G7  = 1<<6,
    G15_KEY_G8  = 1<<7,
    G15_KEY_G9  = 1<<8,
    G15_KEY_G10 = 1<<9,
    G15_KEY_G11 = 1<<10,
    G15_KEY_G12 = 1<<11,
    G15_KEY_G13 = 1<<12,
    G15_KEY_G14 = 1<<13,
    G15_KEY_G15 = 1<<14,
    G15_KEY_G16 = 1<<15,
    G15_KEY_G17 = 1<<16,
    G15_KEY_G18 = 1<<17,
    
    G15_KEY_M1  = 1<<18,
    G15_KEY_M2  = 1<<19,
    G15_KEY_M3  = 1<<20,
    G15_KEY_MR  = 1<<21,
    
    G15_KEY_L1  = 1<<22,
    G15_KEY_L2  = 1<<23,
    G15_KEY_L3  = 1<<24,
    G15_KEY_L4  = 1<<25,
    G15_KEY_L5  = 1<<26,
    
    G15_KEY_LIGHT = 1<<27
  };
  
  /* this one return G15_NO_ERROR on success, something
   * else otherwise (for instance G15_ERROR_OPENING_USB_DEVICE */
  int initLibG15();
  void exitLibG15();
    
  int writePixmapToLCD(unsigned char const *data);
  int setLCDContrast(unsigned int level);
  int setLEDs(unsigned int leds);
  int setLCDBrightness(unsigned int level);
  int getPressedKeys(unsigned int *pressed_keys, unsigned int timeout);
  

#ifdef __cplusplus
}
#endif
	
#endif
