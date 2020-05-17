// Corona Simulation - basic simulation of a human transmissable virus
// Copyright (C) 2020  wbrinksma

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

namespace corsim
{

enum CanvasColor
{
    RED,
    GREEN,
    BLUE,
    ORANGE,
    BLACK,
    SHADE_BLUE,
    SHADE_ORANGE,
};

/**
 * The canvas interface describes that a canvas to draw the simulation on should be
 * able to do.
 */
class Canvas
{
    public:
    virtual ~Canvas(){};
    virtual void clear() = 0;
    virtual void draw_pixel(double x, double y, CanvasColor color) = 0;
    virtual void draw_rectangle(double x, double y, double width, double height, CanvasColor color) = 0;
    virtual void draw_ellipse(double x, double y, double radius, CanvasColor color) = 0;
};

}