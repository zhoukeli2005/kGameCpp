#ifndef _kLog_h_
#define _kLog_h_

#include "core/kConfig.h"

k_namespace_begin
log_namespace_begin

#define info(format, ...)  log("[Info][%s]<%s>(%d):" format, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define debug(format, ...) log("[Debug][%s]<%s>(%d):" format, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define warn(format, ...)  log("[Warn][%s]<%s>(%d):" format, __FILE__, __func__, __LINE__, ##__VA_ARGS__)
#define error(format, ...) log("[Error][%s]<%s>(%d):" format, __FILE__, __func__, __LINE__, ##__VA_ARGS__)

void log(const char * format, ...);

log_namespace_end
k_namespace_end

#endif
