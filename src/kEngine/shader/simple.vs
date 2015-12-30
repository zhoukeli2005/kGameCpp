
precision mediump float;

uniform mat4 u_mv;
uniform mat4 u_mvp;

attribute vec3 a_position;
attribute vec2 a_uv0;

varying vec2 v_uv0;

void main(void)
{
	//v_uv0 = a_uv0;
	//gl_Position = u_mvp * vec4(a_position, 1.0);
	gl_Position = vec4(a_position, 1.0);
}