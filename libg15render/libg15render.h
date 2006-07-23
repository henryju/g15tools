#ifndef LIBG15RENDER_H_
#define LIBG15RENDER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>

#define BYTE_SIZE 	8

#ifndef _LIBG15_H_
enum {
   G15_LCD_OFFSET = 32,
   G15_LCD_HEIGHT = 43,
   G15_LCD_WIDTH = 160
};
#endif /*_LIBG15_H_*/

/// \brief This structure holds the data need to render objects to the LCD screen.
typedef struct g15canvas {
/// g15canvas::buffer[] is a buffer holding the pixel data to be sent to the LCD.
    unsigned char buffer[G15_LCD_WIDTH * G15_LCD_HEIGHT];  
/// g15canvas::mode_xor determines whether xor processing is used in g15r_setPixel.
    int mode_xor;  
/// g15canvas::mode_cache can be used to determine whether caching should be used in an application.
    int mode_cache;  
/// g15canvas::mode_reverse determines whether color values passed to g15r_setPixel are reversed.
    int mode_reverse;  
} g15canvas;

/// \brief Fills an area bounded by (x1, y1) and (x2, y2)
void g15r_pixelReverseFill(g15canvas * canvas, int x1, int y1, int x2, int y2, int fill, int color);
/// \brief Overlays a bitmap of size width x height starting at (x1, y1)
void g15r_pixelOverlay(g15canvas * canvas, int x1, int y1, int width, int height, int colormap[]);
/// \brief Draws a line from (px1, py1) to (px2, py2)
void g15r_drawLine(g15canvas * canvas, int px1, int py1, int px2, int py2, const int color);
/// \brief Draws a box bounded by (x1, y1) and (x2, y2)
void g15r_pixelBox(g15canvas * canvas, int x1, int y1, int x2, int y2, int color, int thick, int fill);

/// \brief Gets the value of the pixel at (x, y)
int g15r_getPixel(g15canvas * canvas, unsigned int x, unsigned int y);
/// \brief Sets the value of the pixel at (x, y)
void g15r_setPixel(g15canvas * canvas, unsigned int x, unsigned int y, int val);
/// \brief Fills the screen with pixels of color
void g15r_clearScreen(g15canvas * canvas, int color);
/// \brief Clears the canvas and resets the mode switches
void g15r_initCanvas(g15canvas * canvas);

/// \brief Font data for the large (8x8) font
extern unsigned char fontdata_8x8[];
/// \brief Font data for the medium (7x5) font
extern unsigned char fontdata_7x5[];
/// \brief Font data for the small (6x4) font
extern unsigned char fontdata_6x4[];

/// \brief Renders a character in the large font at (x, y)
void g15r_renderCharacterLarge(g15canvas * canvas, int x, int y, unsigned char character, unsigned int sx, unsigned int sy);
/// \brief Renders a character in the meduim font at (x, y)
void g15r_renderCharacterMedium(g15canvas * canvas, int x, int y, unsigned char character, unsigned int sx, unsigned int sy);
/// \brief Renders a character in the small font at (x, y)
void g15r_renderCharacterSmall(g15canvas * canvas, int x, int y, unsigned char character, unsigned int sx, unsigned int sy);
/// \brief Renders a string with font size in row
void g15r_renderString(g15canvas * canvas, unsigned char stringOut[], int row, int size, unsigned int sx, unsigned int sy);

#ifdef __cplusplus
}
#endif

#endif /*LIBG15RENDER_H_*/
