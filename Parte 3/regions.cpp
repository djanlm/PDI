#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;
  Vec3b val;
  int x1,y1,x2,y2;

  image=imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "nao abriu bolhas.png" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  cout<<"Insira as coordenadas do primeiro ponto"<<endl;
  cin>>x1>>y1;
  cout<<"Insira as coordenadas do segundo ponto"<<endl;
  cin>>x2>>y2;

  for(int i=x1;i<x2;i++){
    for(int j=y1;j<y2;j++){
      image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
    }
  }
  
  imshow("janela", image);  
  waitKey();
  return 0;
}
