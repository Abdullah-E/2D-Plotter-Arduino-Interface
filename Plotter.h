#ifndef Plotter_h
#define Plotter_h

#include "Arduino.h"
#include <AccelStepper.h>
#include <Servo.h>


class Plotter{
    private:
        int X_STEP_PIN, X_DIR_PIN, Y_STEP_PIN, Y_DIR_PIN;
        AccelStepper motorX, motorY;
        Servo pen;
        int servo_pin, up_angle;
        int speed;
        int pos_x, pos_y;
    public:
        Plotter(int x_step_pin, int x_dir_pin, int y_step_pin, int y_dir_pin, int pen_pin);

        void init_pen();

        // void stepMotor(int steps, int step_pin);
        void stepX(int steps, int dir);
        void stepY(int steps, int dir);

        void goto_relative_coords(int x, int y);
        void goto_abs_coords(int x, int y, int z);
        
        void goto_rel_best(int x, int y);
        // void line(int x1, int y1, int x2, int y2);

};

#endif