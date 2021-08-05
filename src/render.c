#include "render.h"

/* render.c and render.h:
    The graphics library for the game.
*/

int draw_line(uint32_t *pixel_buffer, int x1, int y1, int x2, int y2, uint32_t color) {

    // implements y = mx + b

    draw_pixel(pixel_buffer, x1, y1, color);

    if (x1 > x2) {
        int temp_x = x1;
        int temp_y = y1;

        x1 = x2;
        y1 = y2;

        x2 = temp_x;
        y2 = temp_y;
    }

    int dx = x2 - x1;
    int dy = y2 - y1;

    if (dx >= abs(dy)) {
        float m = (float) dy/dx;

        // top down
        if (y1 <= y2) {

            float ideal_y = y1 + m;
            int y = (int) round(ideal_y);
            float error = ideal_y - y;
            
            for (int i = 1; i <= dx; i++) {

                int x = x1 + i;
                draw_pixel(pixel_buffer, x, y, color);
                error += m;

                if (error >= 0.5) {
                    y++;
                    error -= 1;
                }
            }
        }

        // bottom up
        if (y1 > y2) {

            float ideal_y = y1 + m;
            int y = (int) round(ideal_y);
            float error = ideal_y - y;
            
            for (int i = 1; i <= dx; i++) {

                int x = x1 + i;
                draw_pixel(pixel_buffer, x, y, color);
                error += m;

                if (error <= -0.5) {
                    y--;
                    error += 1;
                }
            }
        }
    }
    if (abs(dy) > dx) {
        float m = (float) dy/dx;

        // top to bottom
		if (y1 < y2) {
			
			float ideal_x = x1 + m;
			int x = (int) round(ideal_x);
			float error = ideal_x - x;
			
			for(int i = 1; i <= dy; i++) {
				
				int y = y1 + i;
				
				draw_pixel(pixel_buffer, x, y, color);
				
				error += m;

				if (error  >= 0.5) {
				
					x++;
					error -= 1;
				}
			}
		}
		
        // bottom to top
		if (y1 > y2) {
			
			float ideal_x = x1 - m;
			int x = (int) round(ideal_x);
			float error = ideal_x - x;

			for(int i = 1; i <= fabs(dy); i++) {
				
				int y = y1 - i;
				
				draw_pixel(pixel_buffer, x, y, color);
				
				error += m;

				if (error  <= -0.5) {
				
					x++;
					error += 1;
				}
			}
		}
    }

    return 0;
}

int draw_pixel(uint32_t *pixel_buffer, int x, int y, uint32_t color) {

    // places one pixel on the screen

    if (x < 0 || y < 0) {
        return 1;
    }

    if (x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) {
        return 1;
    }

    uint32_t position = y * SCREEN_WIDTH + x;
    pixel_buffer[position] = color;

    return 0;
}

void clear_pixels(uint32_t *pixel_buffer, uint32_t color) {

    // makes entire buffer a singular color

    int buffer_size = SCREEN_WIDTH * SCREEN_HEIGHT;

    for (int i = 0; i < buffer_size; i++) {
        pixel_buffer[i] = color;
    }
}