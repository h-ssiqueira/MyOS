#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "driver_video.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color, fgcolor = VGA_COLOR_LIGHT_GREY, bgcolor = VGA_COLOR_BLACK;
uint16_t* terminal_buffer;

size_t strlen(const char* str){
	size_t len;
	len ^= len;
	while(str[len])
		len++;
	return len;
}

void clear(){
	uint8_t i,j;
	for(i ^= i; i < VGA_HEIGHT; i++){
		for(j ^= j; j < VGA_WIDTH; j++){
			const size_t index = i * VGA_WIDTH + j;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
	terminal_row ^= terminal_row;
	terminal_column ^= terminal_column;
}

void terminal_initialize(void){
	terminal_buffer = (uint16_t*) 0xB8000;
	terminal_row ^= terminal_row;
	terminal_column ^= terminal_column;
	terminal_setcolor();
}

void terminal_setbgcolor(uint8_t color){
	switch(color){
		case VGA_COLOR_BLACK:
			bgcolor = VGA_COLOR_BLACK;
			break;
		case VGA_COLOR_BLUE:
			bgcolor = VGA_COLOR_BLUE;
			break;
		case VGA_COLOR_GREEN:
			bgcolor = VGA_COLOR_GREEN;
			break;
		case VGA_COLOR_CYAN:
			bgcolor = VGA_COLOR_CYAN;
			break;
		case VGA_COLOR_RED:
			bgcolor = VGA_COLOR_RED;
			break;
		case VGA_COLOR_MAGENTA:
			bgcolor = VGA_COLOR_MAGENTA;
			break;
		case VGA_COLOR_BROWN:
			bgcolor = VGA_COLOR_BROWN;
			break;
		case VGA_COLOR_LIGHT_GREY:
			bgcolor = VGA_COLOR_LIGHT_GREY;
			break;
		case VGA_COLOR_DARK_GREY:
			bgcolor = VGA_COLOR_DARK_GREY;
			break;
		case VGA_COLOR_LIGHT_BLUE:
			bgcolor = VGA_COLOR_LIGHT_BLUE;
			break;
		case VGA_COLOR_LIGHT_GREEN:
			bgcolor = VGA_COLOR_LIGHT_GREEN;
			break;
		case VGA_COLOR_LIGHT_CYAN:
			bgcolor = VGA_COLOR_LIGHT_CYAN;
			break;
		case VGA_COLOR_LIGHT_RED:
			bgcolor = VGA_COLOR_LIGHT_RED;
			break;
		case VGA_COLOR_LIGHT_MAGENTA:
			bgcolor = VGA_COLOR_LIGHT_MAGENTA;
			break;
		case VGA_COLOR_LIGHT_BROWN:
			bgcolor = VGA_COLOR_LIGHT_BROWN;
			break;
		case VGA_COLOR_WHITE:
			bgcolor = VGA_COLOR_WHITE;
			break;
	}
	terminal_setcolor();
}

void terminal_setfgcolor(uint8_t color){
	switch(color){
		case VGA_COLOR_BLACK:
			fgcolor = VGA_COLOR_BLACK;
			break;
		case VGA_COLOR_BLUE:
			fgcolor = VGA_COLOR_BLUE;
			break;
		case VGA_COLOR_GREEN:
			fgcolor = VGA_COLOR_GREEN;
			break;
		case VGA_COLOR_CYAN:
			fgcolor = VGA_COLOR_CYAN;
			break;
		case VGA_COLOR_RED:
			fgcolor = VGA_COLOR_RED;
			break;
		case VGA_COLOR_MAGENTA:
			fgcolor = VGA_COLOR_MAGENTA;
			break;
		case VGA_COLOR_BROWN:
			fgcolor = VGA_COLOR_BROWN;
			break;
		case VGA_COLOR_LIGHT_GREY:
			fgcolor = VGA_COLOR_LIGHT_GREY;
			break;
		case VGA_COLOR_DARK_GREY:
			fgcolor = VGA_COLOR_DARK_GREY;
			break;
		case VGA_COLOR_LIGHT_BLUE:
			fgcolor = VGA_COLOR_LIGHT_BLUE;
			break;
		case VGA_COLOR_LIGHT_GREEN:
			fgcolor = VGA_COLOR_LIGHT_GREEN;
			break;
		case VGA_COLOR_LIGHT_CYAN:
			fgcolor = VGA_COLOR_LIGHT_CYAN;
			break;
		case VGA_COLOR_LIGHT_RED:
			fgcolor = VGA_COLOR_LIGHT_RED;
			break;
		case VGA_COLOR_LIGHT_MAGENTA:
			fgcolor = VGA_COLOR_LIGHT_MAGENTA;
			break;
		case VGA_COLOR_LIGHT_BROWN:
			fgcolor = VGA_COLOR_LIGHT_BROWN;
			break;
		case VGA_COLOR_WHITE:
			fgcolor = VGA_COLOR_WHITE;
			break;
	}
	terminal_setcolor();
}

void terminal_setcolor(){
	terminal_color = vga_entry_color(fgcolor, bgcolor);
	clear();
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y){
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(char c){
	if(c == '\b'){ // Case backspace, decrement 1 in terminal width
		if(terminal_column-- == 0 && terminal_row > 0){
			terminal_column = VGA_WIDTH-1;
			terminal_row--;
		}
		terminal_putentryat(' ', terminal_color, terminal_column, terminal_row);
	}
	else if(c == '\n'){ // Case new line, increment 1 in terminal row
		terminal_row++;
		terminal_column ^= terminal_column;
		if(terminal_row == VGA_HEIGHT){
			update_row();
			terminal_row--;
		}
	}
	else{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if(++terminal_column == VGA_WIDTH){
			terminal_column ^= terminal_column;
			if(++terminal_row == VGA_HEIGHT){
				update_row();
				terminal_row--;
			}
		}
	}
}

void terminal_write(const char* data, size_t size){
	size_t i;
	for(i ^= i; i < size; i++)
		terminal_putchar(data[i]);
}

void terminal_writestring(const char* data){
	terminal_write(data, strlen(data));
}

void update_row(){
	size_t x, y;
	uint16_t character;
	for(y ^= y; y < VGA_HEIGHT-1;){
		for(x ^= x; x < VGA_WIDTH; x++){
			const size_t index = (y+1) * VGA_WIDTH + x;
			character = terminal_buffer[index];
			const size_t index1 = index - VGA_WIDTH;
			terminal_buffer[index1] = character;
		}
		y++;
		if(y == VGA_HEIGHT-1){
			for(x ^= x; x < VGA_WIDTH; x++)
				terminal_putentryat(' ',terminal_color,x,y);
		}
	}
}