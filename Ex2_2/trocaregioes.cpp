#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image, troca;
  Size tam;

  image= imread("caatinga.jpg",CV_LOAD_IMAGE_COLOR);
  if(!image.data)
    cout << "nao abriu caatinga.jpg" << endl;

  troca= imread("caatinga.jpg",CV_LOAD_IMAGE_COLOR);
  if(!troca.data)
    cout << "nao abriu caatinga.jpg" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  tam = image.size();

  for(int i=0;i<tam.height;i++){
    for(int j=0;j<tam.width;j++){
      if(i>tam.height/2 && j>tam.width/2){
        troca.at<Vec3b>(i,j) = image.at<Vec3b>(i-tam.height/2,j-tam.width/2);
      }else if(i>tam.height/2){
        troca.at<Vec3b>(i,j) = image.at<Vec3b>(i-tam.height/2,j+tam.width/2);
      }else if(j>tam.width/2){
        troca.at<Vec3b>(i,j) = image.at<Vec3b>(i+tam.height/2,j-tam.width/2);
      }else{
        troca.at<Vec3b>(i,j) = image.at<Vec3b>(i+tam.height/2,j+tam.width/2);
      }
    }
  }

  imshow("janela", troca);
  imwrite("troca.png", troca);
  waitKey();

  return 0;
}
