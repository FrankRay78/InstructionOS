#pragma once


typedef struct {
    void (*Show)();
    void (*Hide)();
    void (*SetPosition)(int x, int y, int width);
} Cursor;
