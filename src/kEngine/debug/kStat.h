#ifndef _kStat_h_
#define _kStat_h_

#include "core/kConfig.h"
#include "log/kLog.h"

#include <boost/noncopyable.hpp>

k_namespace_begin
debug_namespace_begin

struct kStat : boost::noncopyable
{
	// stat -- count
	int kNode_count;
	int kVec3_count;
	int kMatrix4x4_count;
	
	// stat -- memory
	int mem;
	
	// constructor
	kStat()
	: kNode_count{0}
	, kVec3_count{0}
	, kMatrix4x4_count{0}
	{
		mem = sizeof(kStat);
	}
	
	// api
	void dump_to_log()
	{
		log::info("kStat Dump Begin:");
		log::info("kNode_count:%d", kNode_count);
		log::info("mem:%d", mem);
	}
	
	// instance
	static kStat & instance()
	{
		static kStat s;
		return s;
	}
};

debug_namespace_end
k_namespace_end

#endif
