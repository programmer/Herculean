
#define M 251
#define KNRM  "\x1B[0m"
void SetCanvas(int scene[M][M]);
void RenderCanvas(int scene[M][M], char clrstring[]);
void PutPixel(int x, int y, int scene[M][M]);
char* PickColor(double ColorIntensity, double RGBVector[3]);
