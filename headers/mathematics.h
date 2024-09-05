double dotproduct(double u[3], double v[3]);
double magnitude(double u[3]);  
double* unitvectorize(double *u);
double project(double u[3], double v[3]);
double RayHitsCircle(double mode, double OriginVector[3], double DirectionVector[3], double SphereVector[3], double radius);
double LightingHitsCircle(double LightingIntensity, double LightingPosition[], double SphereCenter[], double x, double y, double z);

