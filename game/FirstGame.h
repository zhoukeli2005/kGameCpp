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
			boost::shared_ptr<kengine::node::kNode> box = boost::make_shared<kengine::node::kNodeBox>(10);
			kengine::kEngine::instance().rootNode()->addChild(box);
		}
	};
}

#endif