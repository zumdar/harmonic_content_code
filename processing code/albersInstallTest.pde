import controlP5.*;
import processing.sound.*;

SinOsc sine1;
SinOsc sine2;
SinOsc sine3;
SinOsc sine4;
SinOsc sine5;
SinOsc sine6;

ControlP5 cp5;
int myColor = color(0,0,0);

int OSC1 = 100;
int OSC2 = 100;
int OSC3 = 100;
int OSC4 = 100;
int OSC5 = 100;
int OSC6 = 100;

Slider abc;

void setup() {
   size(400, 800);
   noStroke();
   colorMode(HSB, 255, 100, 100);
   cp5 = new ControlP5(this);
  
  // add a horizontal sliders, the value of this slider will be linked
  // to variable 'sliderValue' 
  cp5.addSlider("OSC1")
     .setPosition(0 ,height-50)
     .setRange(0,255)
     ;
       cp5.addSlider("OSC2")
     .setPosition(width/4 ,height-25)
     .setRange(0,255)
     ;  cp5.addSlider("OSC3")
     .setPosition(2*(width/4) ,height-50)
     .setRange(0,255)
     ;  cp5.addSlider("OSC4")
     .setPosition(3*(width/4) ,height-25)
     .setRange(0,255)
     ;
    cp5.addSlider("OSC5")
     .setPosition(3*(width/4) ,height-50)
     .setRange(0,255)
     ;  
     cp5.addSlider("OSC6")
     .setPosition(3*(width/4) ,height-75)
     .setRange(0,255)
     ;
  sine1 = new SinOsc(this);
  sine2 = new SinOsc(this);
  sine3 = new SinOsc(this);
  sine4 = new SinOsc(this);
  sine5 = new SinOsc(this);
  sine6 = new SinOsc(this);
  sine1.play();
  sine2.play();
  sine3.play();
  sine4.play();
  sine5.play();
  sine6.play();
 }
  
 void draw() {
   //colors and shapes
   //vertical bands 
  fill(OSC1,100,100);
  rect(0, 0, width/5, height);
  fill(OSC2,100,100);
  rect((width/5), 0, width/5, height);
  fill(OSC2,100,100);
  rect(3*(width/5), 0, width/5, height);
  fill(OSC3,100,100);
  rect(2*(width/5), 0, width/5, height);    
  fill(OSC1,100,100);
  rect(4*(width/5), 0, width/5, height);
  
  // horizontal band1 (for osc4)
  //colorMode(HSB);
  //color osc4HSB = color(OSC4, 100, 100);
  //color osc2HSB = color(OSC2, 100, 100);
  //colorMode(RGB);
  //color osc4RGB =  red(osc4HSB);
  fill((OSC4+OSC2)/2, 100, 100);
  rect((width/5),height/7 ,(width/5), height/7);
  fill((OSC4+OSC3)/2, 100, 100);
  rect(2*(width/5),height/7 ,(width/5), height/7);
  fill((OSC4+OSC2)/2, 100, 100);
  rect(3*(width/5),height/7 ,(width/5), height/7);
  
  // horizontal band2 (for osc5)
  fill((OSC5+OSC2)/2, 100, 100);
  rect((width/5),3*(height/7) ,(width/5), height/7);
  fill((OSC5+OSC3)/2, 100, 100);
  rect(2*(width/5),3*(height/7) ,(width/5), height/7);
  fill((OSC5+OSC2)/2, 100, 100);
  rect(3*(width/5),3*(height/7) ,(width/5), height/7);
  
  // horizontal band3 (for osc6)
  fill((OSC6+OSC2)/2, 100, 100);
  rect((width/5),5*(height/7) ,(width/5), height/7);
  fill((OSC6+OSC3)/2, 100, 100);
  rect(2*(width/5),5*(height/7) ,(width/5), height/7);
  fill((OSC6+OSC2)/2, 100, 100);
  rect(3*(width/5),5*(height/7) ,(width/5), height/7);

  //sound now!
  float frequency1 = map(OSC1, 0, 255, 80.0, 1000.0);
  sine1.freq(frequency1);
  float frequency2 = map(OSC2, 0, 255, 80.0, 1000.0);
  sine2.freq(frequency2);
  float frequency3 = map(OSC3, 0, 255, 80.0, 1000.0);
  sine3.freq(frequency3);
  float frequency4 = map(OSC4, 0, 255, 80.0, 1000.0);
  sine4.freq(frequency4);
  float frequency5 = map(OSC5, 0, 255, 80.0, 1000.0);
  sine5.freq(frequency5);
  float frequency6 = map(OSC6, 0, 255, 80.0, 1000.0);
  sine6.freq(frequency6);
  sine1.amp(.16);
  sine2.amp(.16);
  sine3.amp(.16);
  sine4.amp(.16);
  sine5.amp(.16);
  sine6.amp(.16);
 }
 
