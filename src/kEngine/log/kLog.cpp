#include "kLog.h"

#include <stdarg.h>
#include <stdio.h>
#include <memory.h>

#include <iostream>

k_namespace_begin
log_namespace_begin

void log(const char * format, ...)
{
	va_list va;
	va_start(va, format);
	
	static char buff[1024];
	memset(buff, 0, sizeof(buff));
	
	vsprintf(buff, format, va);
	
	buff[1023] = '\0';
	
	std::cout << buff << std::endl;
}

log_namespace_end
k_namespace_end