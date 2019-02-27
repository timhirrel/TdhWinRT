#include "TdhWinRT.h"

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Storage.h>

void TdhWinRT_init() {
	init_apartment(winrt::apartment_type::single_threaded);
//	winrt::init_apartment(winrt::apartment_type::single_threaded);
}

std::string hStringToStd (winrt::hstring inStr) {
	std::wstring str2 = inStr.c_str(); // (str1->Begin());
	std::string str3(str2.begin(), str2.end());
	return str3;
  }

std::string PlatformToStd (Platform::String^ inStr) {
	std::wstring str2(inStr->Begin());
	std::string str3(str2.begin(), str2.end());
	return str3;
}

Platform::String^ StdToPlatform (std::string inStr) {
	std::wstring wid_str = std::wstring(inStr.begin(), inStr.end());
	const wchar_t* w_char = wid_str.c_str();
	return ref new Platform::String(w_char);
}

std::string GetDataPath_uwp() {
	return hStringToStd(winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path());
}

std::string GetExecPath_uwp() {
	return PlatformToStd(Windows::ApplicationModel::Package::Current->InstalledLocation->Path);
}


#include <ppltasks.h>

void DisplayPDF_uwp (std::string pdfStr) {
	Windows::Storage::StorageFolder^ appFolder = Windows::ApplicationModel::Package::Current->InstalledLocation;

	// Get the app's manifest file from the current folder
	concurrency::create_task(appFolder->GetFileAsync(StdToPlatform(pdfStr))).then([=](Windows::Storage::StorageFile^ pdfFile) {
		//Do something with the manifest file  
		Windows::System::Launcher::LaunchFileAsync(pdfFile);
	});
}

