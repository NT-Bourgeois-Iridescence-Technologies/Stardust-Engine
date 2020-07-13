#version 330 core
out vec4 FragColor;

uniform sampler2D tex;

in vec2 uv;
in vec3 color;

uniform int flags;

const int TEX_FLAG = 1;
const int COL_FLAG = 1 << 1;

void main()
{
    vec4 mc = vec4(1.0f);
    
    //mc = texture(tex, uv.xy);
    mc *= vec4(color, 1.0f);
    
    FragColor = mc;

    if(FragColor.a == 0.0f){
        discard;
    }
} 