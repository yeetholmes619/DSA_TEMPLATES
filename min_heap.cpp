#include<iostream>
using namespace std;
template<class T>
void swp(T &a, T &b) {
	T c = a;
	a = b;
	b = c;
}
template<class T>
class MinHeap {
public:
	int size = 0;
	T arr[10000] = { -1};
	void fill(int n) {
		size = n;
		for (int i = 0; i < n; i++) cin >> arr[i];
	}
	void heapify() {
		int n = size;
		for (int i = n / 2 - 1; i > -1; i--) {
			int j = 2 * i + 1;
			while (j < n) {
				if (j < n - 1)
					if (arr[j + 1] < arr[j]) j++;
				if (arr[i] > arr[j]) {
					swp(arr[i], arr[j]);
					i = j;
					j = 2 * i + 1;
				}
				else break;
			}
		}
	}
//template<class T>
	void insert(T b) {
		T hold = b;
		int k = size;
		while ((arr[(k - 1) / 2] > hold) and (k != 0)) {
			arr[k] = arr[(k - 1) / 2];
			k = (k - 1) / 2;
		}
		arr[k] = hold;
		size++;
	}
//template<class T>
	T del() {
		T ret = arr[0];
		swp(arr[size - 1], arr[0]);
		// arr[size-1] ^= arr[0];
		// arr[0] ^= arr[size-1];
		// arr[size-1] ^= arr[0];
		int i = 0;
		while (2 * i + 1  < size - 1) {
			if (2 * i + 1 == size - 2) {
				if (arr[i] > arr[2 * i + 1]) {
					swp(arr[i], arr[2 * i + 1]);
					// arr[i] ^= arr[2*i + 1];
					// arr[2*i + 1] ^= arr[i];
					// arr[i] ^= arr[2*i +1];
					i = 2 * i + 1;
				}
				else break;
			}


			else if (arr[2 * i + 1] <= arr[2 * i + 2]) {
				if (arr[i] > arr[2 * i + 1]) {
					swp(arr[i], arr[2 * i + 1]);
					// arr[i] ^= arr[2*i + 1];
					// arr[2*i + 1] ^= arr[i];
					// arr[i] ^= arr[2*i +1];
					i = 2 * i + 1;
				}
				else break;
			}
			else {
				if (arr[i] > arr[2 * i + 2]) {
					swp(arr[i], arr[2 * i + 1]);
					// arr[i] ^= arr[2*i + 2];
					// arr[2*i + 2] ^= arr[i];
					// arr[i] ^= arr[2*i + 2];
					i = 2 * i + 2;
				}
				else break;
			}
		}
		size--;
		return ret;
	}

	void printer() {
		for (int i = 0; i < size; i++) cout << arr[i] << " ";
		cout << "\n";
	}

	void printfull(int n) {
		for (int i = 0; i < n; i++) cout << arr[i] << " ";
		cout << "\n";
	}
};

int main() {
	int n;
	cin >> n;
	MinHeap<int> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		m.insert(k);
		//m.printer();
	}
	for (int i = 0; i < n - 1; i++) {
		m.del();
		m.printfull(n);
	}
    m.printfull(n);
}
