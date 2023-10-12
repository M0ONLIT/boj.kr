#include "testlib.h"

int main()
{
    registerValidation();

    int max=1e8;

    int n = inf.readInt(2, max, "n");
    inf.readSpace();
    int k = inf.readInt(2, n-1, "k");

    inf.readEoln();
    inf.readEof();
    return 0;
}
