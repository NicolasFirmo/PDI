#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;
  Vec3b val = {255,255,255};
  unsigned P1 [2];
  unsigned P2 [2];

  cout << "digite P1_x:";
  cin >> P1 [0];

  cout << "digite P1_y:";
  cin >> P1 [1];
  
  cout << "digite P2_x:";
  cin >> P2 [0];

  cout << "digite P2_y:";
  cin >> P2 [1];

  image= imread("caatinga.jpg",CV_LOAD_IMAGE_COLOR);
  if(!image.data)
    cout << "nao abriu caatinga.jpg" << endl;

  namedWindow("janela",WINDOW_NORMAL);

  for(unsigned i=P1[0];i<P2[0];i++){
    for(unsigned j=P1[1];j<P2[1];j++){
      image.at<Vec3b>(i,j) = val-image.at<Vec3b>(i,j);
    }
  }
  
  imshow("janela", image);
  imwrite("negativo.png",image); 
  waitKey();

  return 0;
}
