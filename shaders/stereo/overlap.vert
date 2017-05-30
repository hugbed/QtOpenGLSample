#version 330
layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

uniform float uHorizontalShift = 0.0;
uniform float uAspectRatio = 0.8;

out vec2 vTexCoordLeft;
out vec2 vTexCoordRight;

void main()
{
  gl_Position = vec4(position.x, position.y * uAspectRatio, position.z, 1.0);
  vTexCoordLeft = vec2(texCoord.x + uHorizontalShift, texCoord.y);
  vTexCoordRight = vec2(texCoord.x - uHorizontalShift, texCoord.y);
}
