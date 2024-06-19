#include "cursor_mock.h"


int cursor_mock_x = 0;
int cursor_mock_y = 0;


void cursor_mock_show() { }

void cursor_mock_hide() { }

void cursor_mock_setposition(int x, int y, int width) 
{ 
    cursor_mock_x = x;
    cursor_mock_y = y;
}


Cursor create_cursor_mock() {
    Cursor cursor;
    
    cursor.Show = cursor_mock_show;
    cursor.Hide = cursor_mock_hide;
    cursor.SetPosition = cursor_mock_setposition;

    return cursor;
}
