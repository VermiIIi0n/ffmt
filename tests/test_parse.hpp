#pragma once
#include "test.hpp"

void test_parse()
{
    "parse"_test = [] {
        HolderContainer phs;
        char fmt[] = "a = {{ {0:^+020.3}, {{} {1:.e}, {}";
        parse(phs, fmt);

        expect(0_u == phs[0].index);
        expect(true == phs[0].escape);

        expect(0_u == phs[1].index);
        expect(false == phs[1].escape);
        expect(20_u == phs[1].padding);
        expect(3_u == phs[1].precision);
        expect(Center == phs[1].align);
        expect(DefaultFormat == phs[1].format);
        expect('0' == phs[1].fill);
        expect(true == phs[1].show_positive);
        expect(7_u == phs[1].begin);
        expect(18_u == phs[1].end);
        
        expect(1_u == phs[3].index);
        expect(false == phs[3].escape);
        expect(0_u == phs[3].padding);
        expect(6_u == phs[3].precision);
        expect(Right == phs[3].align);
        expect(Scientific == phs[3].format);
        expect(' ' == phs[3].fill);
        expect(false == phs[3].show_positive);
        expect(24_u == phs[3].begin);
        expect(30_u == phs[3].end);
    };
}