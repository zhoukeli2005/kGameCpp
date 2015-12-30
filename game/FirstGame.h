#ifndef _FirstGame_h_
#define _FirstGame_h_

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "kEngine.h"
#include "node/kNodeBox.h"

namespace game {
	
	class FirstGame
	{
	public:
		FirstGame() {}
		
	public:
		~FirstGame() {}
		
	public:
		void start()
		{
			return;
			
			box_ = boost::make_shared<kengine::node::kNodeBox>(10);
			box_->moveZ(-5);

			camera_ = boost::make_shared<kengine::render::kCamera>();
			camera_->moveTo(kengine::math::kVec3(0, 0, 0));
			camera_->lookAt(kengine::math::kVec3(0, 0, -20));
			
			camera_->enable();
			kengine::kEngine::instance().rootNode()->addChild(box_);
		}
		
		void update(float deltaTime)
		{
		//	box_->rotateYBy(degreeToRadian(1));
		}
		
	private:
		boost::shared_ptr<kengine::render::kCamera> camera_;
		boost::shared_ptr<kengine::node::kNodeBox> box_;
	};
}

#endif