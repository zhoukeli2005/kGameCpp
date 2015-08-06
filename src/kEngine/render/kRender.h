#ifndef _kRender_h_
#define _kRender_h_

#include "core/kConfig.h"

k_namespace_begin
render_namespace_begin

class kRender : public boost::noncopyable, public boost::enable_shared_from_this<kRender>
{
public:
	kRender() {}
	
public:
	virtual ~kRender() {}
	
public:
	void start();
	
private:
	int dummy_;
};

render_namespace_end
k_namespace_end

#endif

