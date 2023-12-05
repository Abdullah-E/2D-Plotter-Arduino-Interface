#include "Plotter.h"


Plotter::Plotter(int x_step_pin, int x_dir_pin, int y_step_pin, int y_dir_pin){
    pinMode(x_step_pin, OUTPUT);
    pinMode(x_dir_pin, OUTPUT);
    pinMode(y_step_pin, OUTPUT);
    pinMode(y_dir_pin, OUTPUT);
    X_STEP_PIN = x_step_pin;
    X_DIR_PIN = x_dir_pin;
    Y_STEP_PIN = y_step_pin;
    Y_DIR_PIN = y_dir_pin;
    step_delay_us = 15;
}

void Plotter::stepMotor(int steps, int step_pin){
    for(int i = 0; i < steps; i++){
        digitalWrite(step_pin, HIGH);
        delayMicroseconds(step_delay_us);
        digitalWrite(step_pin, LOW);
        // delay(1);
        delayMicroseconds(step_delay_us);
    }
}

void Plotter::stepX(int steps, int dir){
    Serial.println("stepX");
    if(dir == -1){
        digitalWrite(X_DIR_PIN, LOW);
    }
    else{
        digitalWrite(X_DIR_PIN, HIGH);
    }
    stepMotor(steps, X_STEP_PIN);
}

void Plotter::stepY(int steps, int dir){
    if(dir == -1){
        digitalWrite(Y_DIR_PIN, LOW);
    }
    else{
        digitalWrite(Y_DIR_PIN, HIGH);
    }
    stepMotor(steps, Y_STEP_PIN);
}

void Plotter::goto_relative_coords(int x, int y){
    
    int grad = abs(y)/abs(x);
    int steps_to_go = abs(x);

    if(x < 0){
        digitalWrite(X_DIR_PIN, LOW);
    }
    else{
        digitalWrite(X_DIR_PIN, HIGH);
    }

    if(y < 0){
        digitalWrite(Y_DIR_PIN, LOW);
    }
    else{
        digitalWrite(Y_DIR_PIN, HIGH);
    }
    
    while(steps_to_go > 0){
        stepMotor(4, X_STEP_PIN);
        stepMotor(grad, Y_STEP_PIN);
        steps_to_go--;
    }

}

void Plotter::goto_rel_reverse(int x, int y){
    int grad = y/x;
    int steps_to_go = abs(x);
    digitalWrite(X_DIR_PIN, LOW);
    digitalWrite(Y_DIR_PIN, LOW);
    while(steps_to_go > 0){
        stepMotor(grad, Y_STEP_PIN);
        stepMotor(4, X_STEP_PIN);
        steps_to_go--;
    }
}