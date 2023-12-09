#include "Plotter.h"
#include <Servo.h>

Servo pen;
Plotter plotter(10, 8, 6, 4);
String data;
long x;

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1);

  pen.attach(11);
  pen.write(0);
  

  // int steps = 20000;
  
  // for(int i = 0; i < 4; i++){
  //   plotter.goto_rel_test(steps, steps);
  //   plotter.goto_rel_reverse(steps, steps);
  // }
  

  // plotter.stepX(steps, -1);
  // plotter.stepY(steps, -1);


}

void loop() {
  // put your main code here, to run repeatedly:
  while(!Serial.available());
  // data = Ser
  data = Serial.readStringUntil('\n');
  long x = data.substring(0, data.indexOf(',')).toInt(); 
  long y = data.substring(data.indexOf(',') + 1).toInt();

  plotter.goto_relative_coords(x, y);
  // Serial.println(x);
  Serial.println("done");
  
  

}

