#include "cursor_mock.h"


void cursor_mock_show() { }

void cursor_mock_hide() { }

void cursor_mock_setposition(int x, int y, int width) { }


Cursor create_cursor_mock() {
    Cursor cursor;
    
    cursor.Show = cursor_mock_show;
    cursor.Hide = cursor_mock_hide;
    cursor.SetPosition = cursor_mock_setposition;

    return cursor;
}
