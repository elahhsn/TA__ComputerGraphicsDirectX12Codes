#include <bits/stdc++.h>
using namespace std;


#define SIZE 5
template <class T> class STACK{
	public:
		STACK();
		void push(T element);
		T pop();
		T topElement();
		bool isfull();
		bool isempty();
		
	private:
		int top;
		T stck[SIZE];	
};

template <class T> STACK<T>::STACK(){
	top=-1;
}
template <class T> void STACK<T>::push(T elem){
	if(isfull()){
		cout<<"its full."<<endl;
	}
	top=top+1;
	stck[top]=elem;
}
template <class T> T STACK<T>::pop(){
	if(isempty()){
		cout<<"its empty."<<endl;
		
	}
	else{
		return stck[top--];
	}
}
template <class T> bool STACK<T>::isfull(){
	if(top==(SIZE=1)){
		return 1;
	}
	else 
		return 0;
}
template <class T> void STACK<T>::isempty(){
	return (top==-1);
}

template <class T> T STACK<T>::topElement(){
	return stck[top];
}
//return the precedence of operator
int precedence(char elmnt){
	if(elmnt=='^'){
		return 3;
	}
	else if(elmnt=='/' || elmnt=='*'){
		return 2;
	}
	else if(elmnt=='+' || elmnt=='-'){
		return 1;
	}
	else
		return -1;
	
}
//function to return associativity of operator
char associativity(char elmnt){
	if(elmnt=='^'){
		return 'R';
	}
	return 'L';//default to left_associativity
}
void infixToPostfix(string inputt){
	STACK<char> ST;
	string result;
	
	for(int i=0 ; i<inputt.length() ; i++){
		char toSavein=inputt[i];
		//if the scanned character is an operand add it to the output
		if((toSavein>='a' && toSavein<='z') || (toSavein<='A' && toSavein>='Z') || (toSavein>='0' && toSavein<='9')){
			result+=toSavein;
		}		
		
		//if its "(" push it to stack
		else if(toSavein='('){
			ST.push('(')
					}
		//if its ")" pop and add to result until an "("
		else if(toSavein==')'){
			
			while(stck.topElement()!='('){
				result+=stck.topElement();
				stck.pop();
			}
			stck.pop();
		}
		else{
			while((!stck.isempty() && precedence(inputt[i])<precedence(stck.topElement()) ) || (!stck.isempty() && precedence(inputt[i])
			==precedence(stck.topElement()) && associativity(inputt[i])=='L'){
				result+=stck.topElement();
				stck.pop();
			} 
			stck.push(toSavein)
		}
		
		
	}
	//pop all the remaining 
	while(!stck.isempty()){
		result+=stck.topElement();
		stck.pop();
	}
	
	cout<<result<<endl;
}


int main(){
	string me="a-d*(b^c+e)^(g+v*y)-o";
	infixToPostfix(me);
	
	}
	