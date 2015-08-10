#ifndef _kEngine_h_
#define _kEngine_h_

#include <boost/noncopyable.hpp>
#include "core/kConfig.h"
#include "log/kLog.h"
#include "node/kNode.h"
#include "math/kSize.h"
#include "render/kRender.h"

k_namespace_begin

class kEngine : public boost::noncopyable
{
// x. singleton
public:
	static kEngine & instance()
	{
		static kEngine * pins = nullptr;
		if(!pins) {
			pins = new kEngine();
		}
		return *pins;
	}
	
// x. engine
public:
	void start(int screen_width, int screen_height);
	
	void update(float timeDelta);
	
	void draw();
	
// x. node
public:
	boost::shared_ptr<render::kRender> render() { return render_; }
	boost::shared_ptr<node::kNode> rootNode() { return rootNode_; }
	
// x. touches
public:
	void touchesBegan();
	
	void touchesMoved();
	
	void touchesCanceled();
	
	void touchesEnded();
	
// x. other
	math::kSize screenSize() { return screenSize_; }
	
// x. members
private:
	boost::shared_ptr<node::kNode> rootNode_;
	
	math::kSize screenSize_;
	
	boost::shared_ptr<render::kRender> render_;
};

k_namespace_end // namespace kengine

#endif /* defined(__kGameCpp__kMain__) */
