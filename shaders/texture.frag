#version 330
in highp vec4 vColor;
in highp vec2 vTexCoord;

out highp vec4 fColor;

uniform sampler2D uTexture;

void main()
{
   fColor = texture(uTexture, vTexCoord);
}
