#include "Dropbox.h"

Dropbox::Dropbox() {}

Dropbox::Dropbox(float x, float y, float size, float length):
    pos({x, y}),
    size(size),
    length(length) {}

Dropbox::Dropbox(Vector2 pos, float size, float length):
    pos(pos),
    size(size),
    length(length) {}
