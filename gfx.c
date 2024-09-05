#include <headers/stdio.h>
#include <headers/math.h>
#include <headers/stdlib.h>
#include <headers/string.h>

#define M 251
#define KNRM  "\x1B[0m"

//Setting up canvas and pixels

void SetCanvas(int scene[M][M]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
		scene[i][j] = 0;
		}
	}
}

void RenderCanvas(int scene[M][M], char clrstring[]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < M; j++){
	if (scene[i][j] == 1) {printf("%d%s ", scene[i][j-1], clrstring);} 
  else {printf("%d%s ", scene[i][j-1],KNRM);}}

		printf("\n");
	}
}

void PutPixel(int x, int y, int scene[M][M]){
  if(!((x > M) || (y > M))){  
  scene[x][y] = 1;
  }
}


char* PickColor(double ColorIntensity, double RGBVector[3]){
  double Rnumber = (RGBVector[0] * ColorIntensity);  
  double Gnumber = (RGBVector[1] * ColorIntensity);  
  double Bnumber = (RGBVector[2] * ColorIntensity);  
  
  int Rcolor = (int) Rnumber;
  int Gcolor = (int) Gnumber;
  int Bcolor = (int) Bnumber;

  //"\033[48;2;0;0;0m"
  // String shenanigans so we can actually have color
    const char* pt1 = "\033[48;2;";
    const char* pt3 = "m";
    const char* divider = ";";

    size_t length = strlen(pt1) + strlen(pt3) + 2 * strlen(divider) + 9 + 1; // 3 for maximum digits in pt2
    char* FullColor = malloc(length);
  
    snprintf(FullColor, length, "%s%d%s%d%s%d%s", pt1, Rcolor,divider,Gcolor,divider,Bcolor, pt3);
    
    return FullColor;

}
