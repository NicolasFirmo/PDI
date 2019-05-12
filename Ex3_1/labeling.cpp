#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv){
  Mat image, mask;
  
  int width, height;
  Vec3b nobjects = {1,0,0}, branco = {255,255,255};
  
  CvPoint p;
  image = imread(argv[1],CV_LOAD_IMAGE_COLOR);
  
  if(!image.data){
    std::cout << "imagem nao carregou corretamente\n";
    return(-1);
  }
  width=image.size().width;
  height=image.size().height;

  p.x=0;
  p.y=0;

  namedWindow("image",WINDOW_NORMAL);

  // busca objetos com buracos presentes
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<Vec3b>(i,j) == branco){
		// achou um objeto
		p.x=j;
		p.y=i;
		floodFill(image,p,nobjects);
		if(nobjects[0]==255){
		  nobjects[0]=0;
		  if(nobjects[1]==255){
		    nobjects[1]=0;
		    nobjects[2]++;
		    continue;
		  }
		  nobjects[1]++;
		  continue;		
		}
		nobjects[0]++;
	  }
	}
  }
  imshow("image", image);
  imwrite("labeling.png", image);
  waitKey();
  return 0;
}
