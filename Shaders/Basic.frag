#version 150 core

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform vec4 color;
uniform vec3 cameraPosition;

in vec4 pass_Normal;
in vec4 pass_Position;

out vec4 frag_data;

void main() {
//	float cosine = dot(pass_Normal, normalize(vec4(cameraPosition,0) - pass_Position));
//    float factor = max(cosine, 0)/pow(distance(pass_Position, vec4(cameraPosition, 0)), 1) * 2;

    float ambientComponent = 0.5;
    const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);
    
    vec3 normal = normalize(pass_Normal.xyz);
    vec3 lightDir = normalize(-vec3(1,-1,1));
    
    float lambertian = dot(lightDir,normal);
    
    if (lambertian < 0) {
        lambertian = 0;
    }
    
    frag_data = color * ambientComponent + color * lambertian;
    frag_data.a = 1.0;
    
//    frag_data = vec4(color.r * factor,color.g * factor,color.b * factor,color.a);
//    frag_data = vec4(pass_Normal.xyz, 1);
}