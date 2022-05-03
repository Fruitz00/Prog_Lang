#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include<string>

using namespace std;

string keywords[] = { "alignas", "alignof", "and", "and_eq", "asm", "auto",
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
                    
string operators[] = {"+", "-", "*", "/", "^", "&&", "||", "=" , 
					"==", "&", "|", "%", "++", "--", "+=", "-=", 
					"/=", "*=", "%="};
					
string symbols[] = {"(", "{", "[", ")", "}", "]", "<", ">", 
					"()", ";", "<<", ">>", ",", "#", ":"};
					
string ignore[] = {"\n", "", " "};

string conditions[] = {"if", "else", "else if", "switch"};

bool isKeyword(string a){
	for (int i = 0; i < 84; i++) {
		if (keywords[i] == a) 
			return true;
	}
	return false;
}

bool isOperator(string a){
	for (int i = 0; i < 19; i++) {
		if (operators[i] == a) 
			return true;
	}
	return false;
}

bool isSymbol(string a){
	for (int i = 0; i < 15; i++) {
		if (symbols[i] == a) 
			return true;
	}
	return false;
}

bool isIgnore(string a){
	for (int i = 0; i < 3; i++) {
		if (ignore[i] == a) 
			return true;
	}
	return false;
}

bool isCondition(string a){
	for (int i = 0; i < 4; i++) {
		if (conditions[i] == a)
			return true;
	}
	return false;
}

int main (){
	
	ifstream file("prog.txt");
	string x, code="", s="", character="", symbol="", temp="", next="";	
	
	while (getline(file, x)) 
		code+=x;

	for (int i = 0; i < code.size(); i++) {
		
		if (code[i] != ' ') {
			s += code[i];
		}else {
			if (isOperator(s)) {
				cout << s <<" is an operator 1"<<endl;
				s = "";
			}else if (isKeyword(s)) {
				cout << s <<" is a keyword 1"<<endl;
				s = "";	
			}else if (isSymbol(s)) {		
				cout << s <<" is a symbol 1"<<endl;
				s = "";	
			}else if (isIgnore(s)) {
				s = "";
			}else if (isdigit (s[0])) {
					int x = 0;
					if (!isdigit (s[x++])) {
						continue;
					}else {
						cout << s <<" is a constant 1"<<endl;
						s = "";
					}	
			}
			else if (isCondition(s)){
				cout << s << "is a conditional statement 1" << endl;
				s = "";
			}else {
				for (int j = 0; j < s.size(); j++) {
					temp += symbol; 
					character += s[j];
					symbol += s[j];
					next += s[j+1];
					
					if (isKeyword(character)) {	
						cout << character <<" is a keyword 2"<<endl;
						symbol = "";
						character = "";	
					}
					
					//cout << " [ " << character << " ] " << endl;
					if ((s[j]>=48 && s[j]<=57)||(s[j]>=65 && s[j]<=90)||(s[j]>=97 && s[j]<=122) || s[j] == 137 || s[j] == 46){			
						symbol = "";
						temp = "";
						next = "";		
			        }else if (isIgnore(character)) {
						character = "";
					}else if (isdigit (character[0])) {
					int x = 0;
						if (!isdigit (character[x++])) {
							continue;
						}else {
							if(character != symbol){
								character[character.length()-1] = 0; character.erase(character.end()-1);
								cout << character <<" is a constant 2"<<endl;
								cout << symbol <<" is a symbol 2"<<endl;
								character = "";
							}else{
								character = "";
								symbol = "";
								temp = "";
							}	
						}				
					}else if(isSymbol(symbol)){
						if(character != symbol && !isSymbol(character))	{
							character[character.length()-1] = 0; character.erase(character.end()-1);
							cout << character <<" is an identifier 1"<<endl;
							character = "";
						}
						if(isSymbol(symbol) && isSymbol(next) && !isSymbol(temp)){
							character = "";
				   			continue;	
						}
						cout << symbol <<" is a symbol 2"<<endl;
						character = "";
						symbol= "";
						temp = "";
						next = "";
					}else if(isOperator(symbol)){
						if(character != symbol  && !isOperator(character)){
							character[character.length()-1] = 0; character.erase(character.end()-1);
							cout << character <<" is an identifier 2"<<endl;
							character = "";
						}
						if(isOperator(symbol) && isOperator(next) && !isOperator(temp)){
							character = "";
							continue;
						}
						cout << symbol <<" is a operator 2"<<endl;
						character = "";
					}else{
						cout << character <<" is an identifier 3"<<endl;
						character = "";
						symbol= "";
						temp = "";
						next = "";
					}
				}
				
				if(character != ""){
					cout << character <<" is an identifier 4"<<endl;
				}
				
				symbol = "";
				character = "";
				s = "";
			}		
		}	
	}
}
