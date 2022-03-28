#include "utils.h"

using namespace UtilityFunctions;

streamsize UtilityFunctions::setPrintingPrecision() {
    streamsize ss = cout.precision();
    cout << fixed;
    cout << setprecision(2);
    return ss;
}

void UtilityFunctions::removePrintingPrecision(streamsize ss) {
    cout << setprecision(ss);
}
