#version 330

in vec2 vTexCoordLeft;
in vec2 vTexCoordRight;

uniform sampler2D uTextureLeft;
uniform sampler2D uTextureRight;

out vec4 fColor;

void main(void)
{
    vec4 leftFrag = texture(uTextureLeft, vTexCoordLeft);
    float leftGray = dot(leftFrag.rgb, vec3(0.299, 0.587, 0.114));

    vec4 rightFrag = texture(uTextureRight, vTexCoordRight);
    float rightGray = dot(rightFrag.rgb, vec3(0.299, 0.587, 0.114));

    float diff = rightGray - leftGray;

    // Multiply left and right components for final ourput colour
    fColor = vec4(diff, diff, diff, 1.0);
}
