#include <stdio.h>

float* mat_vec_scr_to_text(int** tt, int** st){
    float mat_vec_nrm_to_text[6] = {
        tt[1][0] - tt[0][0], tt[2][0] - tt[0][0], 
        tt[1][1] - tt[0][1], tt[2][1] - tt[0][1],

        tt[0][0], tt[0][1]
    };

    float mat_vec_nrm_to_scr[4] = {
        st[1][0] - st[0][0], st[2][0] - st[0][0], 
        st[1][1] - st[0][1], st[2][1] - st[0][1]
    };

    float inv_det = 1/(mat_vec_nrm_to_scr[0] * mat_vec_nrm_to_scr[3] - mat_vec_nrm_to_scr[1] * mat_vec_nrm_to_scr[2]);

    float mat_vec_scr_to_nrm[4] = {
         mat_vec_nrm_to_scr[3] * inv_det,-mat_vec_nrm_to_scr[1] * inv_det,
        -mat_vec_nrm_to_scr[2] * inv_det, mat_vec_nrm_to_scr[0] * inv_det,

        -st[0][0], -st[0][1]
    };

    float prod[6] = {
        
    };
}

int main(int argc, char** argv){
    printf("coucou\n");
    return 0;
}