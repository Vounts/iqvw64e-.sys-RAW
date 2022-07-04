#include <Windows.h>
#include <TlHelp32.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "intel.hpp"


bool CreateFileFromMemory(const std::wstring& desired_file_path, const char* address, size_t size) {
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size)) {
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}

int main() {
	if (CreateFileFromMemory(L"C:\\testIntel.sys", reinterpret_cast<const char*>(intel_driver_resource::driver), sizeof(intel_driver_resource::driver))) {
		printf("Successfully created intel file!\n");
	}

	return 0;
}