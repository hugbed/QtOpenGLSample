#version 330

in vec2 vTexCoordLeft;
in vec2 vTexCoordRight;

uniform sampler2D uTextureLeft;
uniform sampler2D uTextureRight;

out vec4 fColor;

void main(void)
{
    vec4 t0 = texture2D(uTextureLeft, vTexCoordLeft);
    vec4 t1 = texture2D(uTextureRight, vTexCoordRight);
    fColor = mix(t1, t0, 0.5);
}
