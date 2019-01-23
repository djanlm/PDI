#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image, mask;
  int width, height;
  int nobjects, nobjectsBorda, label, nholes=0;
  int flag=0; //vai indicar se ta percorrendo um objeto ou nao
  vector<int> labelsUsados; //vai armazenar os labels utilizados pra depois verificar se o progframa ja percorreu aquele objeto.
  bool contarBorda=false;
  char bolhaBorda;
  CvPoint p;
 
  while(1){
  cout<<"Deseja contar bolhas que tocam as bordas?(y/n) "<<endl;
  cin>>bolhaBorda;
	if(bolhaBorda=='y' || bolhaBorda =='Y'){
		contarBorda=true;
		break;
	}else if(bolhaBorda=='n' || bolhaBorda =='N'){
		contarBorda=false;
		break;
	}else{
		cout<<"Digite 'y' ou 'n' para 'sim' ou nao, respectivamente"<<endl;
	}
  }

  image = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
  
  if(!image.data){
    cout << "imagem nao carregou corretamente\n";
    return(-1);
  }
  width=image.size().width;
  height=image.size().height;

  p.x=0;
  p.y=0;

  nobjects=0;
  nobjectsBorda=0;
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 255){
		// achou um objeto
		nobjects++;
		
                //labelsUsados.push_back(nobjects);
                cout << nobjects<<endl;
		p.x=j;
		p.y=i;
		floodFill(image,p,nobjects);
		
	}
	if(contarBorda == false){
		 if(j==0 || j==width-1 || i==0 || i==height-1){ //indica que eh borda
			if(image.at<uchar>(i,j) != 0 && image.at<uchar>(i,j) != 254 && image.at<uchar>(i,j) != 100){
		               p.x=j;
		               p.y=i;
		               floodFill(image,p,100);
		               nobjectsBorda++;
			}
		}	
	}

      if(image.at<uchar>(i,j) == 0){
		nholes++;
		p.x=j;
		p.y=i;
		floodFill(image,p,254);
      }

     /*  if(image.at<uchar>(i,j) != 255 && image.at<uchar>(i,j) != 0){  //verifica se o objeto ja foi percorrido
		label=image.at<uchar>(i,j); //armazena a ultima label percorrida
		if(image.at<uchar>(i,j+1) ==0){ //provavel buraco
			flag++; //flag ativada
		}
	}
	if(image.at<uchar>(i,j) == 0 && flag==1){
		if(image.at<uchar>(i,j+1) == label){
			nholes++;
                }
	}*/
     }
     
  }



// busca objetos com buracos presentes

for(int i=0; i<height; i++){
	for(int j=0; j<width; j++){





	}
}
	


  cout << "numero de bolhas: "<<nobjects<<endl;
  cout << "numero de bolhas nas bordas: "<<nobjectsBorda<<endl;
  cout<<"Numero de buracos: "<<nholes-1<<endl;
  imshow("image", image);
  imwrite("labeling.png", image);
  waitKey();
  return 0;
}
