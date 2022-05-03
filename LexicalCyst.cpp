#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include<string>
#include<map>
#include<iomanip>

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

map<string, int> lexMap;

int characterCounter(string str){
	map<string, int>:: iterator itr = lexMap.find(str);
	
	if( lexMap.find(str) == lexMap.end()){
		lexMap.insert(pair<string,int>(str,1));	
	}else{
		lexMap.at(str) += 1;
	}		
}

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

bool isConstant(string a){
    for (int i = 0; i < a.length(); i++){
        if (isdigit(a[i]) == false)
            return false;
    }
    return true;
}

void summaryTable(){
	map<string, int>:: iterator itr;
	cout<<"\t\t\tSUMMARY TABLE\n\n";
	cout<<setw(20)<<"Token"<<setw(10)<<"\t\tType\t\t\tOccurance"<<endl;
	for(itr = lexMap.begin(); itr != lexMap.end(); ++itr){
		if(isKeyword(itr->first)){
			cout<<setw(20)<<itr->first<<setw(10)<<"\t\tkeyword\t\t\t"<<itr->second<<endl;
		}else if(isOperator(itr->first)){
			cout<<setw(20)<<itr->first<<setw(10)<<"\t\toperator\t\t"<<itr->second<<endl;
		}else if(isSymbol(itr->first)){
			cout<<setw(20)<<itr->first<<setw(10)<<"\t\tsymbol\t\t\t"<<itr->second<<endl;
		}else if(isIgnore(itr->first)){
			
		}else if(isCondition(itr->first)){
			cout<<setw(20)<<itr->first<<setw(10)<<"\t\tcondition\t\t\t"<<itr->second<<endl;
		}else if(isConstant(itr->first)){
			cout<<setw(20)<<itr->first<<setw(10)<<"\t\tconstant\t\t"<<itr->second<<endl;
		}else{
			
		}				
	}
	
	
}

int main (){
	
	ifstream file("prog.txt");
	string x, code="", s="", character="", symbol="", temp="", next="";	
	
	while (getline(file, x)) {
		code += " ";
		code += x;
		code += " ";
	}

	for (int i = 0; i < code.size(); i++) {
		
		if (code[i] != ' ') {
			s += code[i];
		}else {
			if (isOperator(s)) {
				characterCounter(s);
				cout << s <<" is an operator"<<endl;
				s = "";
			}else if (isKeyword(s)) {
				characterCounter(s);
				cout << s <<" is a keyword"<<endl;
				s = "";	
			}else if (isSymbol(s)) {
				characterCounter(s);		
				cout << s <<" is a symbol"<<endl;
				s = "";	
			}else if (isIgnore(s)) {
				s = "";
			}else if (isConstant(s)) {
				characterCounter(s);
				cout << s <<" is a constant"<<endl;
				s = "";	
			}else if (isCondition(s)) {
				characterCounter(s);
				cout << s << "is a conditional statement" << endl;
				s = "";
			}else {
				for (int j = 0; j < s.size(); j++){
					temp += symbol; 
					character += s[j];
					symbol += s[j];
					next += s[j+1];
					
					if (isKeyword(character)) {
						characterCounter(character);
						cout << character <<" is a keyword"<<endl;
						symbol = "";
						character = "";	
					}
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
								characterCounter(character);
								cout << character <<" is a constant"<<endl;
								cout << symbol <<" is a symbol"<<endl;
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
							characterCounter(character);
							cout << character <<" is an identifier"<<endl;
							character = "";
						}
						if(isSymbol(symbol) && isSymbol(next) && !isSymbol(temp)){
							character = "";
				   			continue;	
						}
						characterCounter(symbol);
						cout << symbol <<" is a symbol"<<endl;
						character = "";
						symbol= "";
						temp = "";
						next = "";
					}else if(isOperator(symbol)){
						if(character != symbol  && !isOperator(character)){
							character[character.length()-1] = 0; character.erase(character.end()-1);
							characterCounter(character);
							cout << character <<" is an identifier"<<endl;
							character = "";
						}
						if(isOperator(symbol) && isOperator(next) && !isOperator(temp)){
							character = "";
							continue;
						}
						characterCounter(symbol);
						cout << symbol <<" is a operator"<<endl;
						character = "";
					}else{
						characterCounter(character);
						cout << character <<" is an identifier"<<endl;
						character = "";
						symbol= "";
						temp = "";
						next = "";
					}
				}
				
				if(character != ""){
					characterCounter(character);
					cout << character <<" is an identifier"<<endl;
				}
				
				symbol = "";
				character = "";
				s = "";
			}		
		}	
	}

	summaryTable();

}
