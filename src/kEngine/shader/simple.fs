
precision mediump float;

uniform sampler2D u_texture0;

varying vec2 v_uv0;

void main(void)
{
	gl_FragColor = texture2D(u_texture0, v_uv0);
}