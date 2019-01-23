#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <time.h>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;
  Vec3b val;
  int width, height;
  int x,y;
 // int x1,y1,x2,y2;

  image=imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "nao abriu bolhas.png" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  width=image.size().width;
  height=image.size().height;
  
  
  cout<<"largura:"<<width<<endl;
  cout<<"altura:"<<height<<endl;
  Mat imagemtrocada(width, height,CV_LOAD_IMAGE_GRAYSCALE);
  srand((unsigned)time(NULL));
  int numeroAleatorio= 30+rand()%190;

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      x=(i+numeroAleatorio)%256;
      y=(j+numeroAleatorio)%256;
      imagemtrocada.at<uchar>(i,j)=image.at<uchar>(x,y);
    }
  }
  
  imshow("janela", imagemtrocada);  
  waitKey();
  return 0;
}
