#pragma once


void cursor_show();

void cursor_hide();

void cursor_setposition(int x, int y, int width);


typedef struct {
	void (*Show)();
    void (*Hide)();
    void (*SetPosition)(int x, int y, int width);
} Cursor;

// Factory to create cursor
Cursor create_cursor();