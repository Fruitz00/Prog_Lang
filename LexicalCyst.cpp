#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include<string>
using namespace std;

string arr[] = { "alignas", "alignof", "and", "and_eq", "asm", "auto",
                     "bitand", "bitor", "bool", "break", "case", "catch", "char",
                     "char16_t", "char32_t", "class", "compl", "const", "constexpr",
                     "const_cast", "continue", "decltype", "default", "delete",
                     "do", "double", "dynamic_cast", "else", "enum", "explicit",
                     "export", "extern", "false", "float", "for", "friend", "goto",
                     "if", "inline", "int", "long", "mutable", "namespace", "new",
                     "noexcept", "not", "not_eq", "nullptr", "operator", "or",
                     "or_eq", "private", "protected", "public", "register", "reinterpret_cast",
                     "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast",
                     "struct", "switch", "templeate", "this", "thread_local", "throw", "true",
                     "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
                     "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"};

bool isKeyword (string a)
{
	for (int i = 0; i < 14; i++) {
		if (arr[i] == a) {
			return true;
		}
	}
	return false;
}

int main ()
{
	ifstream file("prog.txt");
	string x;
	string code="";
	while (getline(file, x)) 
	{
		code+=x;
	}
	
	string s="";
	string character="";
	string symbol="";	
	for (int i = 0; i < code.size(); i++) {
		
		if (code[i] != ' ') {
			s += code[i];
		}else {
			if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^" || s == "&&" || s == "||" || s == "=" 
			|| s == "==" || s == "&" || s == "|" || s == "%" || s == "++" || s == "--" || s == "+=" || s == "-=" 
			|| s == "/=" || s == "*=" || s == "%=") 
			{
				cout << s <<" is an operator"<<endl;
				s = "";
			}
			else if (isKeyword (s)) {	
					cout << s <<" is a keyword"<<endl;
					s = "";	
			}
			else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || s == "]" || s == "<" || s == ">" 
			|| s == "()" || s == ";" || s == "<<" || s == ">>" || s == "," || s == "#") {
				cout << s <<" is a symbol"<<endl;
				s = "";
			}
			else if (s == "\n" || s == "" || s == " ") {
				s = "";
			}
			else if (isdigit (s[0])) {
				int x = 0;
					if (!isdigit (s[x++])) {
						continue;
					}
					else {
						cout << s <<" is a constant"<<endl;
						s = "";
					}		
			}
			else {
				for (int j = 0; j < s.size(); j++) {
					character += s[j];
					symbol += s[j];
					if ((s[j]>=0 && s[j]<=9)||(s[j]>=65 && s[j]<=90)||(s[j]>=97 && s[j]<=122 || s[j] == 137))
			        {
			           symbol = "";
			        }else if(symbol == "(" || symbol == "{" || symbol == "[" || symbol == ")" || symbol == "}" || symbol == "]" 
					|| symbol == "<" || symbol == ">" || symbol == "()" || symbol == ";" || symbol == "<<" || symbol == ">>" 
					|| symbol == "," || symbol == "#"){
						if(character != symbol){
							character[character.length()-1] = 0; character.erase(character.end()-1);
							cout << character <<" is an identifier"<<endl;
							character = "";
						}
						cout << symbol <<" is a symbol"<<endl;
						character = "";
						symbol= "";
					}else if(symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" || symbol == "^" || symbol == "&&" 
					|| symbol == "||" || symbol == "=" || symbol == "==" || symbol == "&" || symbol == "|" || symbol == "%" 
					|| symbol == "++" || symbol == "--" || symbol == "+=" || symbol == "-=" || symbol == "/=" || symbol == "*=" 
					|| symbol == "%="){
						if(character != symbol){
							character[character.length()-1] = 0; character.erase(character.end()-1);
							cout << character <<" is an identifier"<<endl;
							character = "";
						}
						cout << symbol <<" is a operator"<<endl;
						character = "";
						symbol= "";
					}else{
						cout << character <<" is an identifier"<<endl;
						character = "";
						symbol= "";
					}
				}
				cout << character <<" is an identifier"<<endl;
				character = "";
				s = "";
			}		
		}	
	}
}