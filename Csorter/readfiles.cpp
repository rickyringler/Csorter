#include <iostream>
#include <fstream>
#include <windows.h>
#include <stack>
#include <vector>
#include <string>

static std::stack<std::wstring> directories;

int ReadDirectoryFiles()
{
	ListFiles(L"C:/Users/User/Downloads/test", L"*", files);
	StackContents();
	return 0;
}

bool ListFiles(std::wstring path, std::wstring mask, std::vector<std::wstring>& files)
{
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA ffd;
	std::wstring spec;
	std::stack<std::wstring> directories;

	directories.push(path);
	files.clear();

	while (!directories.empty())
	{
		path = directories.top();
		spec = path + L"\\" + mask;
		directories.pop();

		hFind = FindFirstFile(spec.c_str(), &ffd);
		if (hFind == INVALID_HANDLE_VALUE)
		{
			return false;
		}
		do
		{
			if (wcscmp(ffd.cFileName, L".") != 0 &&
				wcscmp(ffd.cFileName, L"..") != 0)
			{
				if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					directories.push(path + L"\\" + ffd.cFileName);
					std::cout << ffd.cFileName << std::endl;
				}
				else
				{
					files.push_back(path + L"\\" + ffd.cFileName);
					std::cout << ffd.cFileName << std::endl;
				}
			}
		} while (FindNextFile(hFind, &ffd) != 0);

		if (GetLastError() != ERROR_NO_MORE_FILES)
		{
			FindClose(hFind);
			return false;
		}

		FindClose(hFind);
		hFind = INVALID_HANDLE_VALUE;
	}
	return true;
}
bool StackContents()
{
	for (std::stack<std::wstring> dump = directories; !dump.empty(); dump.pop())
	{
		std::wcout << dump.top() << std::endl;
	}
	std::cout << "(" << directories.size() << ")" << std::endl;
	return true;
}