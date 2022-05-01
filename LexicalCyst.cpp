#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
#include<fstream>
#include<string>

using namespace std;

bool isOperator(string input) {
	string arr[] = { "+", "-", "*", "/", "^", "&&", "||", "&", "|", "=",
					 "==", "%", "++", "--", "+=", "-=", "*=", "/=", "%="
					};	
	for(int i = 0; i < 20; i++){
		if(arr[i] == input) {
			return true;
		}
	}
    return false;
}

bool isKeyword(string input) {
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
                     "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    				};

    for (int i = 0; i < 84; i++) {
        if (arr[i] == input) {
            return true;
        }
    }
    return false;
}

bool isConstant(string input) {
    return true;
}

bool isSymbol(string input) {
    return true;
}


//Last else
bool isIdentifier(string input) {
    return true;
}

int main() {
    ifstream file("prog.txt");
    string x;
    string code = "";

    while (getline(file, x)) {
        code += x;
    }

    string s = "";

    for (int i = 0; i <= code.size(); i++) {
        if (code[i] != ' ') {
            s += code[i];
        } else {
            if (isKeyword(s)) {
                cout << s << " is a keyword" << endl;
                s = "";
            }
            else if (isOperator(s)){
                cout << s << " is an operator" << endl;
                s = "";
            } else {
            	cout << s << " is a bitch " << endl;
            	s = "";
			}
        }
    }
}
