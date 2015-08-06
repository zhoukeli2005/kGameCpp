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
	bool exist();
	
	std::string read(size_t count);
	std::string read();
	
// members
private:
	std::string filename_;
};

io_namespace_end
k_namespace_end

#endif /* defined(__kGameCpp__kFile__) */
