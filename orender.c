#include <math.h>
#include "headers/mathematics.h"

double RenderSphere(double mode, double OriginVector[3], double DirectionVector[3], double SphereVector[3], double radius, double tmin, double tmax){
  double closest_t = INFINITY;   
  double hit = 0;
  double matching_t1;

  //Finding the closest object needs to be fixed.
  matching_t1 = RayHitsCircle(mode,OriginVector,DirectionVector,SphereVector, radius);
    if (((matching_t1 >= tmin) && (matching_t1 <= tmax)) && matching_t1 < closest_t ){
   // closest_t = matching_t1;
    hit = 1;
  }
  return hit;
}
