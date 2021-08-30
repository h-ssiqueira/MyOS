#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "driver_video.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
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
		for(j ^= j; j < VGA_WIDTH; j++)
			terminal_putentryat(' ',terminal_color,j,i);
	}
}

void terminal_initialize(void){
	size_t y,x;
	terminal_row ^= terminal_row;
	terminal_column ^= terminal_column;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for(y ^= y; y < VGA_HEIGHT; y++){
		for(x ^= x; x < VGA_WIDTH; x++){
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setbgcolor(uint8_t color){
//TODO
}

void terminal_setfgcolor(uint8_t color){
//TODO
}

void terminal_setcolor(uint8_t colorfg, uint8_t colorbg){
	uint8_t color;//TODO
	terminal_color = color;
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
	size_t x, y, index;
	uint16_t character;
	for(y ^= y; y < VGA_HEIGHT-1;){
		for(x ^= x; x < VGA_WIDTH; x++){
			index = (y+1) * VGA_WIDTH + x;
			character = terminal_buffer[index];
			index -= VGA_WIDTH;
			terminal_buffer[index] = character;
		}
		y++;
		if(y == VGA_HEIGHT-1){
			for(x ^= x; x < VGA_WIDTH; x++)
				terminal_putentryat(' ',terminal_color,x,y);
		}
	}
}