#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "gfx.h"
#include "mathematics.h"
#include "orender.h"

//inital paramerters
#define O ((M/2) + 0.5)

int canvas[M][M];
double ovector[3] = {O, O, O};
double projectionplane = 1;


//Declaring structs for our objects. This should be moved elsewhere later 
struct Sphere {
  double Radius;
  double Position[3];
  double ColorVector[3]; //"\u001b[38;2;<R code>;<G code>;<B code>m"
};

struct Light {
  double Position[3]; //= {O+150,O, -400};
  double Intensity; //= 1;
};

//Initalize our objects and lights
struct Sphere BigSphere = {
  65,
  {O,O,O},
  {255,0,0}
};


struct Light PointLight = {
  {O-150,O, -300},
  0.5
};



int main(){
	SetCanvas(canvas);
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
	   double dvector[3] = {i-O ,j-O ,projectionplane};

      //Find the coords (+-x). This is makeshift and will be changed soon

     double hitormiss1 = RenderSphere(1,ovector,dvector, BigSphere.Position,BigSphere.Radius,1, INFINITY);
     double hitormiss2 = RenderSphere(0,ovector,dvector, BigSphere.Position,BigSphere.Radius,1, INFINITY);
      //Put a pixel down if the ray hits the circle at that coordinate
      if ((hitormiss1 == 1 ) || (hitormiss2 == 1)){ PutPixel((i),(j),canvas);}
      
      //Another makeshift which needs to be fixed.
      double CalculatedIntensity = LightingHitsCircle(PointLight.Intensity,PointLight.Position,BigSphere.Position,i,j,projectionplane);
      
      //Pick the shade of color that corresponds to the lighting intensity
      char* Terminalcolor = PickColor(CalculatedIntensity,BigSphere.ColorVector);                            
	    
      if (canvas[i][j] == 1) {
        printf(" %s ", Terminalcolor);
      } 
        else {printf(" %s ",KNRM);}
    }
	  printf("\n");
	}
	return 0; 
}


