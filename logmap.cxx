/* Homework2 by Michael Stumpf
 * Changed solution from Lab2 to directly save some data
 * in an output-file.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	ofstream out("output.dat"); //name of data-output file
	
	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   double y[Nend-Nskip]; //create array for data-storage
	   
	   for(int i=1; i <= Nskip; i++){
		   x = r*x*(1.0-x);	//for-loop for skipped results
	   }
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1.0-x);	//calculate x for storage
			   y[i-Nskip-1] = x;	//store x in array y
	   }
	   for(int i=0; i <=(Nend-Nskip-1); i++){	//for-loop for storage of y	  
		  out << r << "\t" << y[i] << endl;
	   }
	}
		  out.close();

	return 0;
}