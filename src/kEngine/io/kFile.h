#ifndef _kFile_h_
#define _kFile_h_

#include <boost/noncopyable.hpp>
#include <string>

#include "core/kConfig.h"

k_namespace_begin
io_namespace_begin

class kFile : public boost::noncopyable
{
// constructor
public:
	kFile(const std::string & filename);
	
// destructor
public:
	~kFile();
	
// api
public:
	bool exist() { return exist_; }
	
	const std::string & filename() { return filename_; }
	const std::string & fullname() { return fullname_; }
	
	std::string read(size_t count);
	std::string read();
	
	size_t size();
	const char * data();
	
// members
private:
	std::string filename_;
	std::string fullname_;
	bool exist_;
	
	void * platform_;
};

io_namespace_end
k_namespace_end

#endif /* defined(__kGameCpp__kFile__) */
