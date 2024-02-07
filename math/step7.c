/*
/!\/!\/!\
never tested
/!\/!\/!\
*/

#include <stdio.h>

float* mat_vec_scr_to_text(int** tt, int** st){
    //tt is for texture triangle and st is for screen triangle
    //tt and ts are 3-uplets of (x,y) vertices in the same order

    //matrix to apply on normal coordonate to pass in texture coordonates
    float m1[4] = {
        tt[1][0] - tt[0][0], tt[2][0] - tt[0][0], 
        tt[1][1] - tt[0][1], tt[2][1] - tt[0][1]
    };

    //matrix to apply on normal coordonate to pass in screen coordonates
    float m2[4] = {
        st[1][0] - st[0][0], st[2][0] - st[0][0], 
        st[1][1] - st[0][1], st[2][1] - st[0][1]
    };

    float inv_det = 1/(m2[0] * m2[3] - m2[1] * m2[2]);
    //matrix to apply on screen coordonate to pass in normal coordonates
    float m3[4] = {
         m2[3] * inv_det,-m2[1] * inv_det,
        -m2[2] * inv_det, m2[0] * inv_det
    };

    //matrix to apply on screen coordonate to pass in texture coordonates
    //and it's vector (translation comes second) and vector at the end
    float* final_m = malloc(6*sizeof(float));
    final_m[0] = m1[0]*m3[0] + m1[1]*m3[2];   final_m[1] = m1[0]*m3[1] + m1[1]*m3[3];
    final_m[2] = m1[2]*m3[0] + m1[3]*m3[2];   final_m[3] = m1[2]*m3[1] + m1[3]*m3[3];

    final_m [5] = tt[0][0] - st[0][0] * final_m[0] - st[0][1] * final_m[1];
    final_m [6] = tt[0][1] - st[0][0] * final_m[2] - st[0][1] * final_m[3];

    return final_m;
}