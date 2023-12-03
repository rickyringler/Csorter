#ifndef readfiles
#define readfiles

#include "readfiles.cpp"
std::vector<std::wstring> files;
int ReadDirectoryFiles()
{
	ListFiles(L"C:/Users/User/Downloads/test", L"*", files);
	StackContents();
	return 0;
}

#endif