#version 330 core

in vec3 vertex_color;
in vec3 vsPos3;
in float radius;

out vec4 color;

const vec3 lightPos = normalize(vec3(100.0f, 100.0f, 100.0f));
const vec3 specularColor = vec3(1.0f, 1.0f, 1.0f);
const float shininess = 40.0;

float projectZ(float z, float near, float far) {
  // convert true depth z to depth-buffer depth 

  /* assuming this is the projection matrix:
     m = [w, 0, 0, 0;
     0, h, 0, 0;
     0, 0, f/(n-f), n*f/(n-f);
     0, 0, -1, 0]
  */

  return far*(z+near)/(z*(far-near));
}

void main()
{
    // compute normal
    vec3 normal;
    normal.xy = gl_PointCoord * 2 - 1.0;
    float r_sqr = dot(normal.xy, normal.xy);

    if (r_sqr > 1.0 - 1e-6) 
        discard;
    normal.z = sqrt(1.0 - r_sqr);
    normal = normalize(normal);
    
    vec3 sphereSurfacePos = vsPos3 + normal.xyz * radius; 
    float depthZ = projectZ(sphereSurfacePos.z, 0.1, 1000.0);
    gl_FragDepth = depthZ;

    // diffusion
    vec3 lightDir = normalize(lightPos - sphereSurfacePos);
    float diffuse = max(0.0f, dot(normal, lightDir));

    // phong
    vec3 viewDir = normalize(-sphereSurfacePos);
    vec3 halfDir = normalize(lightDir + viewDir);
    float specAngle = max(dot(halfDir, normal), 0.0);
    float specular = pow(specAngle, shininess);

    color = vec4(vertex_color * diffuse /* + specularColor * specular */, 1.0f);
}
