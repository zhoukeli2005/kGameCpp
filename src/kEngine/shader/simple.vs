
precision mediump float;

uniform mat4 u_mvp;

attribute vec3 a_position;

varying vec4 v_color;

void main(void)
{
	v_color = vec4(0.0, 0.0, 1.0, 0.2);
	gl_Position = u_mvp * vec4(a_position, 1.0);
}