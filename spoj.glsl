float[] arr = float[] (1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
    // Normalized pixel coordinates (from 0 to 1)
    vec2 uv = fragCoord/iResolution.xy*vec2(3);
    
    // Time varying pixel color
    vec3 col = vec3(0, 0, 0);//0.5 + 0.5*cos(iTime+uv.xyx+vec3(0,2,4));
        //arr[8] = 0.0;
        int k = 3;
        int l = 3;
        float centx = (float(k) - 1.0f) * 0.5f;
        int x = int(uv.x);
        int y = int(uv.y);
            if(y < l) {
                if(x < k) {
                for(float a = 0.0; a < cos(iTime * 10.0) + 1.0; a+=0.5f){
                        int xo = x, yo = y;
                        int st = (float(yo) > (float(l) - 1.0f) * 0.5f) ? (l - 1 - y) : y;
                        if (float(yo) < (float(l) - 1.0f) * 0.5f) {
                            if (xo + 1 < k)
                                xo++;
                        }
                        else if (float(yo) > (float(l) - 1.0f) * 0.5f) {
                            if (xo > 0)
                                xo--;
                        }

                        if (x <= st && x != y) {
                            xo = x;
                            yo--;
                        }
                        if (x >= k - st - 1 && y != l - (k - x)) {
                            xo = x;
                            yo++;
                        }

                        if (centx == float(x) && float(y) >= centx && float(y) < float(l) - centx) {
                            xo = x;
                            yo = y;
                        }

                        col.r = arr[yo * k + xo] / 10.0f;
                        arr[y * k + x] = arr[yo * k + xo] / 10.0f;
                    }
                   /* else{
                        col.r = arr[y * k + x] / 10.0f;
                    }*/
                }
            }


    // Output to screen
    fragColor = vec4(col,1.0);
}
