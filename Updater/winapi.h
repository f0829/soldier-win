#include <Windows.h>
#include <WinInet.h>
#include <winternl.h>
#ifndef __winapi_h
#define __winapi_h

#define CONTAINING_RECORD(address, type, field) ((type *)( (PCHAR)(address) - (ULONG_PTR)(&((type *)0)->field)))

typedef struct _FILE_NAME_INFORMATION {
  ULONG FileNameLength;
  WCHAR FileName[1];
} FILE_NAME_INFORMATION, *PFILE_NAME_INFORMATION;

// WINAPI
typedef HMODULE (WINAPI *LOADLIBRARYA)(__in LPSTR lpFileName);
typedef LOADLIBRARYA *PLOADLIBRARYA;
typedef HMODULE (WINAPI *LOADLIBRARYW)(__in LPWSTR lpFileName);
typedef LOADLIBRARYW *PLOADLIBRARYW;
typedef HMODULE (WINAPI *GETPROCADDRESS)(__in HMODULE hModule, __in LPSTR lpProcName);
typedef GETPROCADDRESS *PGETPROCADDRESS;
typedef INT (WINAPI *MESSAGEBOXA)(__in HWND hWnd, __in LPSTR lpText, __in LPSTR lpCaption, __in UINT uType);
typedef MESSAGEBOXA *PMESSAGEBOXA;

typedef VOID (WINAPI *OUTPUTDEBUGSTRINGA)(__in LPSTR lpOutputString);
typedef DWORD (WINAPI *GETFILESIZE)(__in HANDLE hFile, __out LPDWORD lpFileSizeHigh);
typedef LPVOID (WINAPI *VIRTUALALLOC)(__in LPVOID lpAddress, __in SIZE_T dwSize, __in DWORD flAllocationType, __in DWORD flProtect);
typedef BOOL (WINAPI *CLOSEHANDLE)(__in HANDLE hObject);
typedef VOID (WINAPI *SLEEP)(__in DWORD dwSec);
typedef VOID (WINAPI *EXITPROCESS)(__in DWORD uExitReason);
typedef HINSTANCE (WINAPI *SHELLEXECUTEW)(__in HWND hwnd, __in LPWSTR lpOperation, __in LPWSTR lpFile, __in LPWSTR lpParameters, __in LPWSTR lpDirectory, __in INT nShowCmd);
typedef DWORD (WINAPI *GETSHORTPATHNAMEW)(__in LPWSTR lpszLongPath, __in LPWSTR lpszShortPath, __in DWORD cchBuffer);
typedef DWORD (WINAPI *GETMODULEFILENAMEW)(__in HMODULE hModule, __out LPWSTR lpFilename, __in DWORD nSize);
typedef DWORD (WINAPI *GETMODULEFILENAMEA)(__in HMODULE hModule, __out LPSTR lpFilename, __in DWORD nSize);
typedef NTSTATUS (WINAPI *NTQUERYOBJECT)(__in HANDLE Handle, __in OBJECT_INFORMATION_CLASS ObjectInformationClass, __in PVOID ObjectInformation, __in ULONG ObjectInformationLength, __out PULONG ReturnLength);
typedef NTSTATUS (WINAPI *NTQUERYINFORMATIONFILE)(__in HANDLE FileHandle, __out PIO_STATUS_BLOCK IoStatusBlock, __out PVOID FileInformation, __in ULONG Length, __in FILE_INFORMATION_CLASS FileInformationClass);
typedef HANDLE (WINAPI *FINDFIRSTURLCACHEENTRYA)(__in LPSTR lpszUrlSearchPattern, __out LPINTERNET_CACHE_ENTRY_INFO lpFirstCacheEntryInfo, __in LPDWORD lpcbCacheEntryInfo);
typedef BOOL (WINAPI *FINDNEXTURLCACHEENTRYA)(__in HANDLE hEnumHandle, __out LPINTERNET_CACHE_ENTRY_INFO lpNextCacheEntryInfo, __in LPDWORD lpcbCacheEntryInfo);
typedef BOOL (WINAPI *DELETEURLCACHEENTRYA)(__in LPSTR lpszUrlName);
typedef BOOL (WINAPI *FINDCLOSEURLCACHE)(__in HANDLE hEnumHandle);
typedef HRESULT (WINAPI *URLDOWNLOADTOFILEA)(__in LPUNKNOWN pCaller, __in LPSTR szURL, __in LPSTR szFileName, __in DWORD dwReserved, __in LPBINDSTATUSCALLBACK lpfnCB);
typedef BOOL (WINAPI *SHGETSPECIALFOLDERPATHW)(__in HWND hwndOwner, __out LPWSTR lpszPath, __in int csidl, __in BOOL fCreate);
typedef BOOL (WINAPI *SHGETSPECIALFOLDERPATHA)(__in HWND hwndOwner, __out LPSTR lpszPath, __in int csidl, __in BOOL fCreate);
typedef DWORD (WINAPI *GETSHORTPATHNAMEA)(__in LPSTR lpszLongPath, __out LPSTR lpszShortPath, __in DWORD cchBuffer);
typedef DWORD (WINAPI *GETFILEATTRIBUTESW)(__in LPWSTR strFileName);
typedef LONG (WINAPI *REGOPENKEYEXW)(__in HKEY hKey, __in LPWSTR lpSubKey, __in DWORD ulOptions, __in REGSAM samDesired, __out PHKEY phkResult);
typedef LONG (WINAPI *REGQUERYVALUEEXW)(__in HKEY hKey, __in LPWSTR lpValueName, __in LPDWORD lpReserved, __out LPDWORD lpType, __out LPWSTR lpData, __out LPDWORD lpcbData);
typedef BOOL (WINAPI *DELETEFILEA)(__in LPSTR lpFileName);
typedef BOOL (WINAPI *GETURLCACHEENTRYINFOA)(__in LPSTR lpszUrlName, __out LPINTERNET_CACHE_ENTRY_INFOA lpCacheEntryInfo, __in LPDWORD lpcbCacheEntryInfo);
typedef HINTERNET (WINAPI *INTERNETOPENA)(__in LPSTR lpszAgent, __in DWORD dwAccessType, __in LPSTR lpszProxyName, __in LPSTR lpszProxyBypass, __in DWORD dwFlags);
typedef HINTERNET (WINAPI *INTERNETOPENURLA)(__in HINTERNET hInternet, __in LPSTR lpszUrl, __in LPSTR lpszHeaders,  __in DWORD dwHeadersLength, __in DWORD dwFlags, __in DWORD_PTR dwContext);
typedef BOOL (WINAPI *HTTPQUERYINFOA)(__in HINTERNET hRequest, __in DWORD dwInfoLevel, __inout LPVOID lpvBuffer, __inout LPDWORD lpdwBufferLength, __inout LPDWORD lpdwIndex);
typedef BOOL (WINAPI *INTERNETREADFILE)(__in HINTERNET hFile, __out LPVOID lpBuffer, __in DWORD dwNumberOfBytesToRead, __out LPDWORD lpdwNumberOfBytesRead);
typedef BOOL (WINAPI *INTERNETREADFILEEXA)(__in HINTERNET hFile, __in LPINTERNET_BUFFERS lpBuffersOut, __in DWORD dwFlags, __in DWORD dwContext);
typedef HANDLE (WINAPI *CREATEFILEA)(__in LPSTR lpFileName, __in DWORD dwDesiredAccess, __in DWORD dwShareMode, __in LPSECURITY_ATTRIBUTES lpSecurityAttributes, __in DWORD dwCreationDisposition, __in DWORD dwFlagsAndAttributes, __in HANDLE hTemplateFile);
typedef BOOL (WINAPI *WRITEFILE)(__in HANDLE hFile, __in LPCVOID lpBuffer, __in DWORD nNumberOfBytesToWrite, __out LPDWORD lpNumberOfBytesWritten, __in LPOVERLAPPED lpOverlapped);
typedef UINT (WINAPI *ATOI)(__in LPSTR string);
typedef DWORD (WINAPI *WCSTOMBS)(__inout LPSTR lpStr, __in LPWSTR lpWstr, __in DWORD count);
typedef DWORD (WINAPI *GETTEMPPATHW)(__in DWORD dwSize, __out LPWSTR lpBuffer);
typedef DWORD (WINAPI *GETTEMPPATHA)(__in DWORD dwSize, __out LPSTR lpBuffer);
typedef UINT (WINAPI *GETTEMPFILENAMEA)(__in LPSTR strPathName, __in LPSTR strPrefixString, __in UINT dwUnique, __out LPSTR strTempFileName);
typedef UINT (WINAPI *GETTEMPFILENAMEW)(__in LPWSTR strPathName, __in LPWSTR strPrefixString, __in UINT dwUnique, __out LPWSTR strTempFileName);
typedef BOOL (WINAPI *VIRTUALFREE)(__in LPVOID lpAddress, __in SIZE_T dwSize, __in DWORD dwFreetype);
typedef LPWSTR (WINAPI *STRRCHRW)(__in LPWSTR strStart, __in LPWSTR strEnd, __in WCHAR wMatch);
typedef LPSTR (WINAPI *STRRCHRA)(__in LPSTR strStart, __in LPSTR strEnd, __in CHAR wMatch);
typedef INT (WINAPI *STRCMPIW)(__in LPWSTR str1, __in LPWSTR str2);
typedef INT (WINAPI *STRCMPIA)(__in LPSTR str1, __in LPSTR str2);
typedef HANDLE (WINAPI *CREATEFILEW)(__in LPWSTR lpFileName, __in DWORD dwDesiredAccess, __in DWORD dwShareMode, __in LPSECURITY_ATTRIBUTES lpSecurityAttributes, __in DWORD dwCreationDisposition, __in DWORD dwFlagsAndAttributes, __in HANDLE hTemplateFile);
typedef INT (_cdecl *WNSPRINTFA)(__out LPSTR strDest, __in INT cchDest, __in LPSTR strFormat, __in ...);
typedef BOOL (WINAPI *CREATEPROCESSA)(_In_opt_ LPCTSTR lpApplicationName, 
	_Inout_opt_  LPTSTR lpCommandLine, 
	_In_opt_   LPSECURITY_ATTRIBUTES lpProcessAttributes,
  _In_opt_     LPSECURITY_ATTRIBUTES lpThreadAttributes,
  _In_         BOOL bInheritHandles,
  _In_         DWORD dwCreationFlags,
  _In_opt_     LPVOID lpEnvironment,
  _In_opt_     LPCTSTR lpCurrentDirectory,
  _In_         LPSTARTUPINFO lpStartupInfo,
  _Out_        LPPROCESS_INFORMATION lpProcessInformation
);
typedef DWORD (WINAPI *EXPANDENVIRONMENTSTRINGA)( _In_ LPSTR lpSrc, _Out_opt_ LPSTR lpDst, _In_ DWORD nSize);
#endif // __winapi_h