#include "cursor_mock.h"


int cursor_mock_x;
int cursor_mock_y;


void cursor_mock_show() { }

void cursor_mock_hide() { }

void cursor_mock_setposition(int x, int y, int width) 
{ 
    cursor_mock_x = x;
    cursor_mock_y = y;
}


Cursor create_cursor_mock() {
    Cursor cursor;
    
    // Initialise the cursor state to a known starting value
    cursor_mock_x = 0;
    cursor_mock_y = 0;

    cursor.Show = cursor_mock_show;
    cursor.Hide = cursor_mock_hide;
    cursor.SetPosition = cursor_mock_setposition;

    return cursor;
}
