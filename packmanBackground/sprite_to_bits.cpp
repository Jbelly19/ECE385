#include <iostream>
#include "rgbapixel.h"
#include "png.h"
#include <map>
#include <fstream>

using namespace std;


int main(){


	
	fstream myfile;
	myfile.open("sprite_rom.txt", ios::out);
	
	for (int fileNumber = 1; fileNumber < 10; fileNumber++)
	{
	    stringstream ss;
	    ss << "character_sprites/" << fileNumber << ".png" << endl;  

	    string fullfileName;
	    ss >> fullfileName;

	    
		PNG inputImage(fullfileName);

		RGBAPixel black = *(inputImage(0,0));
		

		myfile<<"//"<<fileNumber<<".png"<<endl;
		for(size_t row = 0; row < inputImage.height(); row++){
			myfile<<"16'b";
			for(size_t col = 0; col < inputImage.width(); col++){
				
				RGBAPixel curr = *(inputImage(col,row));	
					
				
				if(curr == black){

					myfile <<"0";

				}else{

					myfile <<"1";

				}
			}
			myfile << ",\n";
		}
	    
	}
/*
	fstream myfile;
	myfile.open("sprite_rom.txt", ios::out);

	//Open a new PNG image from the file in.png
	for(int i = 1; i < 10; i++  ){
		filename[18] = i;
		PNG inputImage(filename);

		RGBAPixel black = *(inputImage(0,0));


		for(size_t row = 0; row < inputImage.height(); row++){
			myfile<<"//"<<i<<".png"<<endl;
			myfile<<"2'b";
			for(size_t col = 0; col < inputImage.width(); col++){
				
				RGBAPixel curr = *(inputImage(col,row));	
					
				
				if(curr == black){

					myfile <<"0,";

				}else{

					myfile <<"1";

				}
			}
			myfile << ",\n";
		}
	}
	*/						

	myfile.close();


	return 0;
}
