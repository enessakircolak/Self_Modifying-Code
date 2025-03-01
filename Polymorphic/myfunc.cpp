#include <windows.h>
#include <stdio.h>
#include <wincrypt.h>
#include <string>
#include <iostream>
#include <iomanip> 
#include <cctype>  
//------------------------------|| 
//                              ||
//                              ||
// @author: esc                 ||
// @Project: Polymorphic code   ||
// @web: enessakircolak.com.tr  ||
//                              ||
// ⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔⛔ ||
//	                            ||
// Note:🚨                      ||
// This program will not work   ||
// properly other than x86 arch ||
//                              ||
//                              ||
// -----------------------------||
//▄︻テ══━一x86



using namespace std;

// void hexdump(unsigned char* data, int size) { 
// 	const int bytesPerLine = 16;

// 	for (int i = 0; i < size; i += bytesPerLine) {
// 		cout << setw(8) << setfill('0') << hex << i << "  ";

// 		for (int j = 0; j < bytesPerLine; ++j) {
// 			if (i + j < size) {
// 				cout << setw(2) << setfill('0') << (int)data[i + j] << " ";
// 			}
// 			else {
// 				cout << "   ";
// 			}
// 		}

// 		cout << " |";
// 		for (int j = 0; j < bytesPerLine; ++j) {
// 			if (i + j < size) {
// 				unsigned char c = data[i + j];
// 				if (isprint(c)) {
// 					cout << c; 
// 				}
// 				else {
// 					cout << '.'; 
// 				}
// 			}
// 		}
// 		cout << "|" << endl;
// 	}
// }

struct sender {
	int* textBaseAdress;
	int size;
	int* entryPoint;
	int entryOffset;
	int rawTextoffset;
	int architecture;
};

extern "C" {
	sender PeParser(char*);  // C
}
extern "C" {
	void writeToFile(int*, int, char*);  // C 
}



	sender PeParser(char* getFileName)
	{

		std::string filename = (string)getFileName;


		HANDLE loadFile = CreateFileA(filename.c_str(), GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

		//check handle
		if (loadFile == INVALID_HANDLE_VALUE)
		{
			printf("[!] Failed to get a handle to the file - Error Code (%d)\n", GetLastError());
			printf(" filename -> %s\n", filename);
			CloseHandle(loadFile);
			exit(1);
		}

		DWORD nNumberOfBytesToRead = GetFileSize(loadFile, NULL);
		LPVOID lpBuffer = HeapAlloc(GetProcessHeap(), 0, nNumberOfBytesToRead);

		DWORD lpNumberOfBytesRead = { 0 };
		if (!ReadFile(loadFile, lpBuffer, nNumberOfBytesToRead, &lpNumberOfBytesRead, NULL))
		{
			printf("[!] Failed to read the file - Error Code (%d)\n", GetLastError());
			CloseHandle(loadFile);
			exit(1);
		}


		int* data;
		sender senderVar;

		
		// READFILE FUNCTION BEGIN		
		int* peHeader = (int*)lpBuffer + ((int)((PIMAGE_DOS_HEADER)lpBuffer)->e_lfanew) / 4;
		if (((PIMAGE_NT_HEADERS32)peHeader)->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC) {
			cout << "usta biz x86 bakiyoruz\n" << endl;
			//senderVar.architecture == 0x64;
			exit(1);
		}
		//else {
		//	senderVar.architecture == 0x32;
		//}

		PIMAGE_SECTION_HEADER imageSectionHeader = { 0 };
		imageSectionHeader = (PIMAGE_SECTION_HEADER)(peHeader + sizeof(IMAGE_NT_HEADERS32) / 4);
		DWORD textBegin = imageSectionHeader->PointerToRawData;

		unsigned char* TextSection = (unsigned char*)((int*)lpBuffer + textBegin / 4);
		//DWORD rawentrypoint = ((PIMAGE_NT_HEADERS32)peHeader)->OptionalHeader.AddressOfEntryPoint - ((PIMAGE_NT_HEADERS32)peHeader)->OptionalHeader.BaseOfCode + imageSectionHeader->PointerToRawData;	// entrypoint - 0x1000 + 0x400
		
		senderVar.textBaseAdress = (int*)TextSection;
		senderVar.size = imageSectionHeader->SizeOfRawData;
		senderVar.entryOffset = (((PIMAGE_NT_HEADERS32)peHeader)->OptionalHeader.AddressOfEntryPoint - ((PIMAGE_NT_HEADERS32)peHeader)->OptionalHeader.BaseOfCode + imageSectionHeader->PointerToRawData);
		senderVar.entryPoint = (int*)((unsigned char*)((int*)lpBuffer + senderVar.entryOffset / 4));
		senderVar.rawTextoffset = textBegin;

		CloseHandle(loadFile);

		return senderVar;
	}

void writeToFile(int* textModifiedBuffer, int size, char* getFileName) {

	std::string filename = (string)getFileName;
	HANDLE loadFile = CreateFileA(filename.c_str(), GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//check handle
	if (loadFile == INVALID_HANDLE_VALUE)
	{
		printf("[!] Failed to get a handle to the file - Error Code (%d)\n", GetLastError());
		CloseHandle(loadFile);
		exit(1);
	}

	DWORD nNumberOfBytesToRead = GetFileSize(loadFile, NULL);
	LPVOID lpBuffer = HeapAlloc(GetProcessHeap(), 0, nNumberOfBytesToRead);

	DWORD lpNumberOfBytesRead = { 0 };
	if (!ReadFile(loadFile, lpBuffer, nNumberOfBytesToRead, &lpNumberOfBytesRead, NULL))
	{
		printf("[!] Failed to read the file - Error Code (%d)\n", GetLastError());
		CloseHandle(loadFile);
		exit(1);
	}

	// GAME ZONE

	int* peHeader = (int*)lpBuffer + ((int)((PIMAGE_DOS_HEADER)lpBuffer)->e_lfanew) / 4;

	PIMAGE_SECTION_HEADER imageSectionHeader = { 0 };

	imageSectionHeader = (PIMAGE_SECTION_HEADER)(peHeader + sizeof(IMAGE_NT_HEADERS32) / 4);


	DWORD textBegin = imageSectionHeader->PointerToRawData;

	unsigned char* finalArray = (unsigned char*)lpBuffer; // original file pointer
	unsigned char* bytePtr = (unsigned char*)textModifiedBuffer; // it hold changed text section

	for (int i = textBegin, j = 0; i < size + textBegin; i++, j++) { // it will start from the 
		finalArray[i] = bytePtr[j]; // this will write only text section to original file
	}

	// GAME ZONE END


	char Createfilename[50] = "output.exe";
	FILE* file = fopen("output.exe", "r");
	int counter = 1;

	// if it exist, create new one
	while (file != NULL) {
		fclose(file);
		sprintf(Createfilename, "output(%d).exe", counter++);
		file = fopen(Createfilename, "r");
	}

	file = fopen(Createfilename, "wb");
	if (file == NULL) {
		perror("File couldn't open\nProbably it is open :)");
		exit(1);
	}

	
	fwrite(lpBuffer, 1, lpNumberOfBytesRead, file);

	fclose(file);
	std::cout << "File saved as: " << Createfilename << std::endl;

}