#pragma once

#include <string>

__declspec(dllexport) void TdhWinRT_init();

__declspec(dllexport) std::string GetDataPath_uwp();

__declspec(dllexport) std::string GetExecPath_uwp();

__declspec(dllexport) void DisplayPDF_uwp (std::string);
