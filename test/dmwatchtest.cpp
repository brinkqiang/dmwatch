
#include "dmwatch.h"

int main( int argc, char* argv[] ) {

    dmwatch_interface* module = dmwatchGetModule();
    if (module)
    {
        module->Release();
    }
    return 0;
}
