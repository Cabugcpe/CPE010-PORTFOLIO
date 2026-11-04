#include <iostream>

int sumOfTwoNum(int fNum, int sNum);
void sumOfThreeNum(int fNum, int sNum, int tNum);
void grtrVar (int fNum, int sNum);
bool logicalOperation (bool a, bool b);

int main(){
	// FIRST BULLET
	std::cout << "The sum of the two numbers is: " << sumOfTwoNum(6,7) << std::endl;;
	sumOfThreeNum(6,7,8);
	// SECOND BULLET
	grtrVar (50,49);
	// THIRD BULLET
	logicalOperation (true, false);
}
int sumOfTwoNum(int fNum, int sNum){
	
	int sum = fNum + sNum;
	
	return sum;
}

void sumOfThreeNum(int fNum, int sNum, int tNum){
	std::cout << "The total sum is: " << fNum + sNum + tNum << std::endl;
}

void grtrVar (int fNum, int sNum){
	if (fNum > sNum){
		std::cout<< "The number " << fNum <<" is greater than " << sNum << std::endl;
	}
	else if ( fNum < sNum){
		std::cout<< "The number " << fNum <<" is not greater than " << sNum << std::endl;
	}
	else if ( fNum = sNum){
		std::cout<< "The number " << fNum <<" and " << sNum <<" is equall "<< std::endl;
	}

}

 bool logicalOperation (bool a, bool b){
	std::cout << "AND OPERATOR: ";
	
	if(a && b){
		std::cout << " TRUE "<< std::endl;
	}
	else{
		std::cout << " FALSE "<< std::endl;
	}
	
	std::cout << "OR OPERATOR: ";
	
	if(a || b){
		std::cout << " TRUE "<< std::endl;
	}
	else{
		std::cout << " FALSE "<< std::endl;
	}
	std::cout << "NOT A: ";
	
	if(!a){
		std::cout << " TRUE "<< std::endl;
	}
	else{
		std::cout << " FALSE "<< std::endl;
	}
	
	std::cout << "NOT B: ";
	
	if(!b){
		std::cout << " TRUE "<< std::endl;
	}
	else{
		std::cout << " FALSE "<< std::endl;
	}
	

	return 0;
}
