#include "../library/fft.h"

int main() {
	vi A = vi({ 1,1,1,1,1 });
	vi B = vi({ 1,1,1,1,1 });
	vi ret = multiply(A, B);
	for (auto elem : ret) {
		printf("%d ", elem);
	}
	puts("");
    return 0;
}