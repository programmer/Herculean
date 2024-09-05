#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Vector math library. Nothing fancy for the next few functions.

double dotproduct(double u[3], double v[3]){
	double result = 0;
	for(int i = 0; i < 3; i++){
		result = result + (u[i] * v[i]);
	} 
	return result;
}


double magnitude(double *u){
  return (sqrt(pow(u[0],2) + pow(u[1],2) + pow(u[2],2)));
}



double* unitvectorize(double *u){

  double* unitvector = (double*)malloc(3 * sizeof(double)); 
  double scale = magnitude(u);

  if (!(scale)){
    free(unitvector);
    return 0;
  }

  unitvector[0] = u[0]/scale;
  unitvector[1] = u[1]/scale;
  unitvector[2] = u[2]/scale;
  return unitvector;
}


double projection(double u[3], double v[3]){
   double magu = magnitude(u);
   double magv = magnitude(v);
   if ((magu || magv) == 0){
    return 0;
  }

  return (dotproduct(u,v)/(magu * magv));
}

double LightingHitsCircle(double LightingIntensity, double LightingPosition[], double SphereCenter[], double x, double y, double z){
  double i = 0;
    
  double RadiusVector[3] = {
    x - SphereCenter[0],
    y - SphereCenter[1],
    z - SphereCenter[2] 
  };  
  //we take the normal of the sphere to find how intense the light is
  double* NormalVector = unitvectorize(RadiusVector);

  double IntensityLine[3] = {
    LightingPosition[0] - x,
    LightingPosition[1] - y,
    LightingPosition[2] - z
  };

  if (dotproduct(NormalVector,IntensityLine) > 0){
    i += LightingIntensity * projection(NormalVector,IntensityLine);    
  }
  free(NormalVector);
  
  return i;
}


double RayHitsCircle(double mode, double OriginVector[3], double DirectionVector[3], double SphereVector[3], double radius){
  //All we're doing here is solving a quadratic equation to figure how what what points the ray his the circle.
  double t1;
  double VectorCO[3] = {OriginVector[0] - SphereVector[0], OriginVector[1] - SphereVector[1], OriginVector[2] - SphereVector[2]};
  double TermA = dotproduct(DirectionVector,DirectionVector);  
  double TermB = 2 * dotproduct(VectorCO, DirectionVector);
  double TermC = dotproduct(VectorCO, VectorCO) - radius * radius;

  double discriminate = TermB * TermB - (4 * TermA * TermC);

  if (discriminate < 0){
    return INFINITY;
  }

  if (mode == 1){ t1 = ((-1 * TermB) + sqrt(discriminate))/(2 * TermA);}
  else{t1 = ((-1 * TermB) - sqrt(discriminate))/(2 * TermA);}
    return t1;
}
