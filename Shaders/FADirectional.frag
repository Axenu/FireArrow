#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec4 color;

in vec4 pass_Normal;
in vec4 pass_Position;
in vec4 pass_Color;

out vec4 frag_data;

void main() {
    
    //diffuse
    float ambientComponent = 0.5;
    const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);
    
    vec3 normal = normalize(pass_Normal.xyz);
    vec3 lightDir = normalize(-vec3(1,-1,1));
    
    float lambertian = dot(lightDir,normal);
    
    if (lambertian < 0) {
        lambertian = 0;
    }
    
    frag_data = pass_Color * ambientComponent + pass_Color * lambertian;
    frag_data.a = 1.0;
}