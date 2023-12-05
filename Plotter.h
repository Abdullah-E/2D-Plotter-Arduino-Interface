#ifndef Plotter_h
#define Plotter_h

#include "Arduino.h"

class Plotter{
    private:
        int X_STEP_PIN, X_DIR_PIN, Y_STEP_PIN, Y_DIR_PIN;
        int step_delay_us;
    public:
        Plotter(int x_step_pin, int x_dir_pin, int y_step_pin, int y_dir_pin);

        void stepMotor(int steps, int step_pin);
        void stepX(int steps, int dir);
        void stepY(int steps, int dir);

        void goto_relative_coords(int x, int y);
        void goto_rel_reverse(int x, int y);

};

#endif