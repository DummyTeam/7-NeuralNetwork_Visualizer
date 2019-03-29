#include "Core.h"
#include "Xor.h"

int main() {
	// Initialize random seed
	srand(24);

	// Neural Network for XOR 
	Xor* x = new Xor("data.data", 0.1, 52000);
	x->train();
	x->viewNetwork();

	system("pause");
	return 0;
}
