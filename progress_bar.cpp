#include <iostream>
#include <windows.h>

using namespace std;

int main(){
	
	double progress = 0.0;
	while (progress <= 1.0) {
		
    	int barWidth = 20;

	    cout << "[";
	    int pos = progress * barWidth;
	    for (int i = 0; i < barWidth; i++) {
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
	    cout << "] " << progress * 100 << " %\r";
	
	    progress += 0.10;
	}
	
	cout << endl << endl;
	cout << "Take your coffee!";
	
	return 0;
}
