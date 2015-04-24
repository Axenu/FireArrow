#version 400 core

in vec2 in_Position;
//uniform mat4 modelMatrix;
//uniform mat4 viewProjectionMatrix;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;

out vec2 pass_UV;

void main() {
    vec4 pos = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 0.0, 1.0);
    pos /= pos.w;
    pass_UV = (pos.xy + vec2(1,1))/2;
//    pass_UV.x /= 1024;
//    pass_UV.y /= 720;
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(in_Position, 0.0, 1.0);
}