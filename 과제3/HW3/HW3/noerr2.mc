/*
 * 2021 Compiler Testdata 
 */

float arr1[10];
const float f1 = 5;

float div_num(float num, float div){
	float result;
	// save the result
	int p;

	result = num/div;
	
	if(result >3){
		result -= 3;
	}else if(result<3){
		result += 3;
	}else{
		result *= 3;	
	}
	return result;
}


