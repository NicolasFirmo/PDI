#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image, mask;

  int width, height;
  int nobjects = 0;

  CvPoint p;
  image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

  if(!image.data){
    std::cout << "imagem nao carregou corretamente\n";
    return(-1);
  }
  width=image.size().width;
  height=image.size().height;

  for(int i=0; i<width; i++){
    p.x=i;
    p.y=0;
    floodFill(image,p,0);
    p.y=height-1;
    floodFill(image,p,0);
  }

  for(int i=0; i<height; i++){
    p.y=i;
    p.x=0;
    floodFill(image,p,0);
    p.x=width-1;
    floodFill(image,p,0);
  }

  p.x=0;
  p.y=0;

  floodFill(image,p,1);

  // busca objetos com buracos presentes
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 255){
	      p.x=j;
        p.y=i;
	      floodFill(image,p,1);
	     }
     }
   }

  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 0){
	       p.x=j;
         p.y=i;
	       floodFill(image,p,(nobjects+2)*5);
	       nobjects++;
	      }
      }
    }

  cout << "número de buracos: " << nobjects << endl;

  namedWindow("image",WINDOW_NORMAL);

  imshow("image", image);
  imwrite("labeling.png", image);
  waitKey();

  return 0;
}
