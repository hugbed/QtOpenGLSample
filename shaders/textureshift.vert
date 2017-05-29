#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

uniform float uHorizontalShift;

out vec2 vTexCoord;

void main()
{
  gl_Position = vec4(position, 1.0);
  vTexCoord = vec2(texCoord.x + uHorizontalShift, texCoord.y);
}
