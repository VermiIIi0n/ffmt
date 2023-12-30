#pragma once
#include "test.hpp"

void test_ffmt()
{
    "ffmt"_test = [] {
        int a = 123;
        double d = 123.321;
        expect("{}"_b == format("{{}"));
        expect("{key}:{value}"_b == format("{{{1}}:{{{0}}", "value", "key"));

        expect("a = +00123"_b == format("a = {:+06}", a));
        expect("a = +00123"_b == format("a = {:+06}", 123));
        expect("a = 123  "_b == format("a = {:<05}", a));
        expect("a = 123  "_b == format("a = {:<05}", 123));
        expect("a = -123 "_b == format("a = {:<05}", -123));
        expect("a = +0"_b == format("a = {:+}", 0));
        expect("a = 0"_b == format("a = {:}", 0));
        expect("0x7b"_b == format("0x{:.x}", a));
        expect("deadbeef"_b == format("{:.x}", 0xdeadbeef));
        // test octal
        expect("173"_b == format("{:.o}", 0x7b));
        expect("-173"_b == format("{:.o}", -0x7b));
        //test binary
        expect("1111011"_b == format("{:.b}", 0x7b));
        expect("-1111011"_b == format("{:.b}", -0x7b));

        expect("true"_b == format("{}", true));
        expect("false"_b == format("{}", false));

        expect("d = +00123.321"_b == format("d = {:+010.3}", d));
        expect("d = 123.321000"_b == format("d = {:<010.3}", 123.321));
        expect("1.23321e2"_b == format("{:.5e}", d));
        expect("0.00123"_b == format("{:.5f}", 0.00123));
        expect("1.0000000000000000000000000"_b == format("{:-.25f}", 1.0));

        uint32_t ptr = 0x00005678;
        expect("00005678"_b == format("{:.p}", ptr));

        uintptr_t uptr = 0x12345678;
        expect(format("{:.p}", uptr) == format("{}", (void*)uptr));

        expect("*****YES*****"_b == format("{:*^13}", "YES"));
    };
}