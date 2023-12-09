#include "Plotter.h"

void simplify(int* num, int*den){
    int a = *num;
    int b = *den;
    int c = 0;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    *num = *num/a;
    *den = *den/a;
}

Plotter::Plotter(int x_step_pin, int x_dir_pin, int y_step_pin, int y_dir_pin):
motorX(AccelStepper::DRIVER, x_step_pin, x_dir_pin),
motorY(AccelStepper::DRIVER, y_step_pin, y_dir_pin){
    speed= 500;
    motorX.setMaxSpeed(speed);
    motorY.setMaxSpeed(speed);

}

void Plotter::stepX(int steps, int dir){
    motorX.move(steps*dir);
    motorX.setSpeed(speed);
    while(motorX.distanceToGo() != 0){
        motorX.runSpeedToPosition();
    }
}

void Plotter::stepY(int steps, int dir){
    motorY.move(steps*dir);
    motorY.setSpeed(speed);
    while(motorY.distanceToGo() != 0){
        motorY.runSpeedToPosition();
    }
}

void Plotter::goto_relative_coords(int x, int y){
    if(x == 0 && y == 0){
        return;
    }else if(x == 0){
        stepY(y, 1);
        return;
    }else if(y == 0){
        stepX(x, 1);
        return;
    }
    int x_dir = x/abs(x);
    int y_dir = y/abs(y);
    // int eh = 4;
    int x_step_size = abs(x);
    int y_step_size = abs(y);
    simplify(&x_step_size, &y_step_size);
    x_step_size = abs(x_step_size);
    y_step_size = abs(y_step_size);
    int distance_to_go = abs(x);
    while(distance_to_go > 0){
        stepX(x_step_size, x_dir);
        stepY(y_step_size, y_dir);
        distance_to_go -= x_step_size;
    }

}





void Plotter::goto_rel_best(int x, int y){

}