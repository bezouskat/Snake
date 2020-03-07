#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdbool.h>
#include "state.h"

struct
{
    int start_length;
    int start_level;
    bool running;
    state current_state;
} settings;

#endif // SETTINGS_H
