#include "Plotter.h"
Plotter plotter(10, 8, 6, 4);

void setup() {

  int steps = 20000;
  for(int i = 0; i < 4; i++){
    plotter.goto_relative_coords(steps, steps);
    plotter.goto_rel_reverse(steps, steps);
  }


}

void loop() {
  // put your main code here, to run repeatedly:

  
    
  
}

