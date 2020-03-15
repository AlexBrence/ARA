#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
	ifstream input(s);
	int st;

	if (!input.is_open()) {
		return false;
	}

	while (!input.eof()) {
		input >> st;
		vec.push_back(st);
		while (isspace(input.peek())) input.get();
	}
	input.close();
	return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
	ofstream output("out.txt");

	for (int i = 0; i<velikost; i++)
		output << polje[i] << ' ';
}


int countingSort(vector<int> A, int *B) {
    int min = 0;
    int MAX = 0;

    // Go through numbers, always save the smallest one
    for (int i : A) {
        if (i < min) {
            min = i;
        }
    }


    // If min < 0, go through numbers and add min to them
    if (min < 0) {
        for (int & i : A) {
            i -= min;
        }
    }

    // Look for the max element
    for (int i : A) {
        if (i > MAX) {
            MAX = i;
        }
    }

    int *C = new int[MAX+1];

    // Make all elt in C = 0
    for (int i = 0; i <= MAX; i++) {
        C[i] = 0;
    }


    // For A value make C index++
    for (int i : A) {
        C[i]++;
    }

    // Sum of this one and previous one
    for (int i = 1; i <= MAX+1; i++) {
        C[i] = C[i] + C[i-1];
    }


    for (int i = A.size()-1; i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    if (min < 0) {
        for (int i = 0; i < A.size()-1; i++) {
            B[i] += min;
        }
    }


    delete[] C;

    return *B;
}


int main(int argc, const char* argv[]) {
	vector<int> A;

	if (argc < 3) return 0;
	if (!Branje_Stevil(A, argv[2])) return 0;

    int *B = new int[A.size()-1];
	if (argv[1][0] == '0') {
	    countingSort(A, B);
	}
	else {
		//Roman sort
	}
	Izpis_Stevil(B, A.size());


	delete[] B;
	return 0;
}
