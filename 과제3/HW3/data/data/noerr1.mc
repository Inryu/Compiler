/*
 * 2021 Compiler Testdata 
 */

//global variables
const int input = 5;
int intarray[10];
float floatarray[10];

int fibonacci(int a) { 
	int result_fibo = 0;
	int first, second;
	int i;

	first = 1;
	second = 1;
	i = 3;

	while (i <= a) {
		result_fibo = first + second;
		i++;
		first = second;
		second = result_fibo;
	}
	return result_fibo;
}

float triangle(int width, int height) {
	float result_tri;
	result_tri = width * height / 2.0;
	return result_tri;
}

int main() {
	int fibo;
	float tri;

	if (input >= 3) 
		fibo = fibonacci(input);
	
	else 
		fibo = fibonacci(input + 3);
	

	tri = triangle(input, input);
	
	return 0;
}