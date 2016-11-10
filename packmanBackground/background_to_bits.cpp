#include <iostream>
#include "rgbapixel.h"
#include "png.h"
#include <map>
#include <fstream>

using namespace std;


int main(){

	fstream myfile;
	myfile.open("out.txt", ios::out);

	//Open a new PNG image from the file in.png
	PNG inputImage("in.png");

	RGBAPixel black(0,0,0);
	RGBAPixel blue(33,33, 255);
	RGBAPixel pink(252,181,255);


	for(size_t row = 0; row < inputImage.height(); row++){
		for(size_t col = 0; col < inputImage.width(); col++){
			
			RGBAPixel curr = *(inputImage(col,row));	
				
			
			if(curr == black){

				myfile <<"2'b00,\n";

			}else if( curr == blue){

				myfile <<"2'b01,\n";

			}else{

				myfile <<"2'b10,\n";

			}
		}
	}
							

	myfile.close();


	return 0;
}
