#include <iostream>
#include <fstream>
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"
#include <sstream>
#include <string.h>

using namespace std;
using namespace cv;

bool try_use_gpu = false;
Stitcher::Mode mode = Stitcher::PANORAMA;

int main()
{
	    vector <Mat> inputs;
	    Mat pano;
		string input_folder = "/home/atul/DeWinter/Stitcher/";
	for(int i = 1; i <=2 ; i=i+1)
	{
		string path = input_folder;
	//	path.append("/");
		stringstream ss;
		ss << i;
		string str = ss.str();;
		path.append(str);
		path.append(".jpg");



		Mat temp = imread(path);
		inputs.push_back(temp);
	}
 
	
    Ptr<Stitcher> stitcher = Stitcher::create(mode, try_use_gpu);
    Stitcher::Status status = stitcher->stitch(inputs, pano);
    imwrite("/home/atul/DeWinter/Stitcher/final.jpg",pano);
    return 0;
}


