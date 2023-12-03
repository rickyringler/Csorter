#include <iostream>
#include <fstream>
#include <windows.h>
#include <stack>
#include <vector>
#include <string>

#include "readfiles.hpp"


std::string sys_download_file_path = "C:/Users/User/Downloads/test";
std::string* ptr_sys = &sys_download_file_path;


int main(int argc, char* argv[])
{
	ReadDirectoryFiles();
	/*
	if(ListFiles(L"C:/Users/User/Downloads/test", L"*", files))
	{
		for(std::vector<std::wstring>::iterator it = files.begin();
			it !=files.end();
			++it)
		{
			std::wcout << it->c_str() << std::endl;

		}	
		
		for (const std::wstring& i : files)
		{
			//std::cout << "file" << std::endl;
		}
	}
	*/

	return 0;
}