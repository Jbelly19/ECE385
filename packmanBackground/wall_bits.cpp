#include <iostream>
#include "rgbapixel.h"
#include "png.h"
#include <map>
#include <fstream>

using namespace std;


int main(){

	fstream myfile;
	myfile.open("walls.txt", ios::out);

	//Open a new PNG image from the file in.png
	PNG inputImage("in.png");

	
	RGBAPixel blue(33,33, 255);



	for(size_t row = 0; row < inputImage.height(); row++){
		for(size_t col = 0; col < inputImage.width(); col++){
			
			RGBAPixel curr = *(inputImage(col,row));	
				
			
			if(curr != blue){

				myfile <<"1,\n";

			}else{
				myfile <<"0,\n";
			}
		}
	

	}
							

	myfile.close();


	return 0;
}
