#include "cursor_mock.h"


void cursor_show() { }

void cursor_hide() { }

void cursor_setposition(int x, int y, int width) { }


Cursor create_cursor() {
    Cursor cursor;
    
    cursor.Show = cursor_show;
    cursor.Hide = cursor_hide;
    cursor.SetPosition = cursor_setposition;

    return cursor;
}
