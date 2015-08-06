#import <Foundation/Foundation.h>
#include "kFile.h"

k_namespace_begin
io_namespace_begin

kFile::kFile(const std::string & filename)
{
	filename_ = filename;
}

kFile::~kFile()
{
	
}

bool kFile::exist()
{
	return true;
}

std::string kFile::read(size_t count)
{
	return std::string{""};
}

std::string kFile::read()
{
	NSString * fname = [NSString stringWithUTF8String:filename_.c_str()];
	NSString * full_path = [[[[NSBundle mainBundle] resourcePath] stringByAppendingString:@"/"] stringByAppendingString:fname];
	NSError * pError = nil;
	NSString * content = [NSString stringWithContentsOfFile:full_path encoding:NSUTF8StringEncoding error:&pError];
	return std::string{[content UTF8String]};
}


io_namespace_end
k_namespace_end
