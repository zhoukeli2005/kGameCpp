#ifndef _kTexture_h_
#define _kTexture_h_

#include "core/kConfig.h"

k_namespace_begin
render_namespace_begin

enum class E_TEXTURE_FORMAT
{
	E_NONE,
	E_MEM,	// 内存数据
	E_JPG,
	E_PNG
};

struct kTextureInfo
{
	size_t width, height;
	enum  E_TEXTURE_FORMAT format;
	bool has_alpha;
	bool pre_multiply_alpha;
	int bit_per_component;
	
	kTextureInfo()
	: width(0)
	, height(0)
	, format(E_TEXTURE_FORMAT::E_NONE)
	, has_alpha(false)
	, pre_multiply_alpha(false)
	, bit_per_component(8)
	{}
};

class kTexture : public boost::noncopyable, public boost::enable_shared_from_this<kTexture>
{
public:
	// constructor : must create with filename or otherwise create an empty texture
	// when kTexture has been created, its content cannot be changed
	kTexture(const std::string & filename = "");
	
public:
	~kTexture();
	
public:
	GLuint glName() { return texture_; }
	const kTextureInfo& get_info() const { return info_; }
	
private:
	void _load_empty();
	void _load_file();
	void _init_with_data(const unsigned char * data);
	
private:
	GLuint texture_;
	std::string filename_;
	
	kTextureInfo info_;
};

render_namespace_end
k_namespace_end

#endif
