#include <iostream>
#include <windows.h>

using namespace std;

int main(){
	
	double progress = 0.0;
	while (progress <= 1.0) {
    	int barWidth = 30;

	    cout << "[";
	    int pos = barWidth * progress;
	    for (int i = 0; i < barWidth; ++i) {
	    	Sleep(50);
	        if (i < pos){
	        	cout << "=";	
			}
	        else if (i == pos){
	        	cout << ">";
			}
	        else{
	        	cout << " ";
			} 
	    }
	    cout << "] " << int(progress * 100.0) << " %\r";
	
	    progress += 0.10;
	}
	
	cout << endl;
	
	return 0;
}
