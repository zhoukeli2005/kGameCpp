#include "kEngine.h"
#include "io/kFile.h"
#include "log/kLog.h"

#include "render/kOpenGLCapability.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

k_namespace_begin

void kEngine::start(int w, int h)
{
	rootNode_ = boost::make_shared<node::kNode>();
	
	render::kOpenGLCapability openglCapability;
	
	screenSize_.w = w;
	screenSize_.h = h;
	
	render_ = boost::make_shared<render::kRender>();
	render_->start();
	
	return;
}

void kEngine::update(float timeDelta)
{
}

void kEngine::draw()
{
	render_->draw();
}

void kEngine::touchesBegan()
{
	
}

void kEngine::touchesCanceled()
{
	
}

void kEngine::touchesMoved()
{
	
}

void kEngine::touchesEnded()
{
	
}

k_namespace_end