#pragma once

#include <Windows.h>

#include <signal.h>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <memory>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <d3dx9math.h>


using namespace std;

void DebugOut(wchar_t *fmt, ...);

typedef D3DXVECTOR2 Vec2;

#define VECTOR_0 Vec2(0, 0)

vector<string> split(string line, string delimeter = "\t");
wstring ToWSTR(string st);

LPCWSTR ToLPCWSTR(string st);

