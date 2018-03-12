/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#ifndef TESTPRINTSCANFFLOAT_HPP
#define TESTPRINTSCANFFLOAT_HPP

#include <cstdlib>
#include <cstdio>

void TestPrintScanfFloat()
{
    char *pEnd;
    long int res = strtol("10.023 56", &pEnd, 10);
    double out;
    float fout;
    char *line = "-15.9525 234";
    sscanf(line, "%f %d", &fout, &res);
    printf("out=%g, res=%d", fout, res);
}

#endif
