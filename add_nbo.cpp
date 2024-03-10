#include <iostream>
#include <cstdint>
#include <cstdio>
#include <netinet/in.h>  

using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <file1> <file2>" << endl;
        return 1;
    }

    uint32_t n1, n2;

    FILE *file1 = fopen(argv[1], "rb");
    if (!file1) {
        cerr << "Error: '" << argv[1] << "' doesn't exist" << endl;
        return 1;
    }
    if (fread(&n1, sizeof(n1), 1, file1) != 1) {
        cerr << "Error: Reading error from " << argv[1] << endl;
        fclose(file1);
        return 1;
    }
    fclose(file1);

    FILE *file2 = fopen(argv[2], "rb");
    if (!file2) {
        cerr << "Error: '" << argv[2] << "' doesn't exist" << endl;
        return 1;
    }
    if (fread(&n2, sizeof(n2), 1, file2) != 1) {
        cerr << "Error: Reading error from " << argv[2] << endl;
        fclose(file2);
        return 1;
    }
    fclose(file2);

    // host byte order로 변환
    n1 = ntohl(n1);
    n2 = ntohl(n2);

    uint32_t sum = n1 + n2;

    // 덧셈 출력
    cout << n1 << "(0x" << hex << n1 << dec << ") + " << n2 << "(0x" << hex << n2 << dec << ") = " << sum << "(0x" << hex << sum << dec << ")" << endl;

    return 0;
}