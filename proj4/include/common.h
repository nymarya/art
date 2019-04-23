#ifndef _common_h_
#define _common_h_

#include <iostream>

#include "primitive.h"
#include "surface_interaction.h"

using component_t = float;
typedef long coord_type;

/// Enum for easily access the coordinates positions.
enum COORDINATES
{
    X,
    Y,
    Z
};

/// Enum for easily access the colors.
enum RGB
{
    RED,
    GREEN,
    BLUE
};

#endif