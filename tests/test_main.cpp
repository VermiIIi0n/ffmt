#include "test.hpp"
#include "test_parse.hpp"
#include "test_ffmt.hpp"

backward::SignalHandling sh;

int main()
{
    test_parse();
    test_ffmt();
}