#include <zserio/SerializeUtil.h>
#include "top/level/simple/Simple.h"

int main(int argc, char* argv[])
{
    top::level::simple::Simple simple;
    simple.setValue64(UINT64_MAX);

    auto bitBuffer = zserio::serialize(simple);
    auto readSimple = zserio::deserialize<top::level::simple::Simple>(bitBuffer);

    return simple == readSimple ? 0 : 1;
}
