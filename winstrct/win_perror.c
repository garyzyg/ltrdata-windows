#include <windows.h>
#include <stdio.h>

void win_perrorA(LPCSTR __errmsg)
{
  fputs(__errmsg, stderr);
}

void win_perrorW(LPCWSTR __errmsg)
{
  fputws(__errmsg, stderr);
}
