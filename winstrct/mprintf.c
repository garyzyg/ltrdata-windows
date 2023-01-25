#include <windows.h>
#include <stdarg.h>

EXTERN_C LPSTR
CDECL
mprintfA(LPCSTR lpMsg, ...)
{
  static LPSTR lpBuffer = NULL;
  va_list Arguments;

  if (lpBuffer) {
    lpBuffer = LocalFree(lpBuffer);
    if (lpBuffer)
      return NULL;
  }

  va_start(Arguments, lpMsg);

  if (!FormatMessageA(
    FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_STRING,
    lpMsg,
    0,
    0,
    (LPSTR)&lpBuffer,
    0,
    &Arguments)) return NULL;

  va_end(Arguments);

  return lpBuffer;
}

EXTERN_C LPWSTR
CDECL
mprintfW(LPCWSTR lpMsg, ...)
{
  static LPWSTR lpBuffer = NULL;
  va_list Arguments;

  if (lpBuffer) {
    lpBuffer = LocalFree(lpBuffer);
    if (lpBuffer)
      return NULL;
  }

  va_start(Arguments, lpMsg);

  if (!FormatMessageW(
    FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_STRING,
    lpMsg,
    0,
    0,
    (LPWSTR)&lpBuffer,
    0,
    &Arguments)) return NULL;

  va_end(Arguments);

  return lpBuffer;
}
