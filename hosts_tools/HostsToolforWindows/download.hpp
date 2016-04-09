/*
 * The MIT License(MIT)(redefined)
 *
 * Copyright(c) 2016 Too-Naive E-mail:sweheartiii@hotmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, and to permit persons to
 * whom the Software is furnished to do so, BUT DO NOT SUBLICENSE, AND / OR SELL
 * OF THE SOFTWARE,subject to the following conditions :
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

//download.hpp
//Code:https://raw.githubusercontent.com/Too-Naive/Tools/master/download.hpp

#pragma once

#include <windows.h>
#include <wininet.h>
#include "ptrerr.hpp"

//need wininet.lib

#pragma comment(lib,"wininet.lib")

#define ___userAgent TEXT("Mozilla/4.0 (compatible; Windows NT 6.1)")

/*
bool Func_DownloadDEBUGEx(const TCHAR * url,const TCHAR * file,const DWORD FileAttributes){
	const size_t dwBuffer=2048;		//buffer size
	HINTERNET hWeb,hRequest;		//Internet request handle
	DWORD dwReadByte=0,dwReserved;		//read byte count
	char szBuffer[dwBuffer]="";		//read buff
	HANDLE hdFile=INVALID_HANDLE_VALUE;	//file handle
	//bug check begin
	Func_FastPMNTS(_T("Call InternetOpen()(%ld)\n"),GetLastError());
	if (!(hWeb=InternetOpen(___userAgent,INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0))) return false;
	Func_FastPMNTS(_T("Call InternetOpenUrl()(%ld)\n"),GetLastError());
	if (!(hRequest=InternetOpenUrl(hWeb,url,NULL,0,INTERNET_FLAG_DONT_CACHE,0))){
		Func_FastPMNTS(_T("erin1\n"));
		InternetCloseHandle(hWeb);
		return false;
	}
	Func_FastPMNTS(_T("Call CreateFile()(%ld)\n"),GetLastError());
	if ((hdFile=CreateFile(file,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FileAttributes,NULL))==INVALID_HANDLE_VALUE){
		Func_FastPMNTS("Erro2\n");
		InternetCloseHandle(hWeb);
		InternetCloseHandle(hRequest);
		return false;
	}
	Func_FastPMNTS(_T("Call InternetReadFile()(%ld)\n"),GetLastError());
	//end.
	while (InternetReadFile(hRequest,(PVOID)szBuffer,dwBuffer,&dwReadByte) && dwReadByte)
		WriteFile(hdFile,szBuffer,dwReadByte,&dwReserved,NULL);
	Func_FastPMNTS(_T("return\n"));
	CloseHandle(hdFile);
	InternetCloseHandle(hRequest);
	InternetCloseHandle(hWeb);
	return true;
}

inline bool __fastcall Func_DownloadDEBUG(const TCHAR * url,const TCHAR *file){
	return Func_DownloadDEBUGEx(url,file,FILE_ATTRIBUTE_NORMAL);
}*/

bool Func_DownloadEx(const TCHAR * url,const TCHAR * file,const DWORD FileAttributes){
	const size_t dwBuffer=2048;		//buffer size
	HINTERNET hWeb,hRequest;		//Internet request handle
	DWORD dwReadByte=0,dwReserved;		//read byte count
	char szBuffer[dwBuffer]="";		//read buff
	HANDLE hdFile=INVALID_HANDLE_VALUE;	//file handle
	//bug check begin
	if (!(hWeb=InternetOpen(___userAgent,INTERNET_OPEN_TYPE_PRECONFIG,NULL,NULL,0))) return false;
	if (!(hRequest=InternetOpenUrl(hWeb,url,NULL,0,INTERNET_FLAG_DONT_CACHE,0))){
		InternetCloseHandle(hWeb);
		return false;
	}
	if ((hdFile=CreateFile(file,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FileAttributes,NULL))==INVALID_HANDLE_VALUE){
		InternetCloseHandle(hWeb);
		InternetCloseHandle(hRequest);
		return false;
	}
	//end.
	while (InternetReadFile(hRequest,(PVOID)szBuffer,dwBuffer,&dwReadByte) && dwReadByte)
		WriteFile(hdFile,szBuffer,dwReadByte,&dwReserved,NULL);
	CloseHandle(hdFile);
	InternetCloseHandle(hRequest);
	InternetCloseHandle(hWeb);
	return true;
}

inline bool __fastcall Func_Download(const TCHAR *url,const TCHAR *file){//for backward compatibility
	return Func_DownloadEx(url,file,FILE_ATTRIBUTE_NORMAL);
}


