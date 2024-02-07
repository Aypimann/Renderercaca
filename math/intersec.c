#include <stdio.h>
#include <stdlib.h>

float* intersec2D(float** e1, float** e2){

    float m[4] = {
        e1[1][0] - e1[0][0], e2[0][0] - e1[0][0],
        e1[1][1] - e1[0][1], e2[0][1] - e1[0][1]
    };

    float inv_det = m[0]*m[3]-m[1]*m[2];
    if (inv_det == 0) {
        printf("to be continued !");
        return NULL;
    }
    inv_det = 1/inv_det;
    float m_1[4] = {
        m[3] * inv_det,
       -m[1] * inv_det,
       -m[2] * inv_det,
        m[0] * inv_det
    };

    printf("m :   |%f   %f|\n      |%f   %f|\n\n\n", m[0], m[1], m[2], m[3]);
    printf("mm1 : |%f   %f|\n      |%f   %f|\n\n\n", m_1[0], m_1[2], m_1[1], m_1[3]);

    float* p1 = malloc(2* sizeof(float));
    p1[0] = (e2[1][0] - e1[0][0]) * m_1[0] + (e2[1][1] - e1[0][1]) * m_1[1];
    p1[1] = (e2[1][0] - e1[0][0]) * m_1[2] + (e2[1][1] - e1[0][1]) * m_1[3];

    printf("v : |%f|\n    |%f|\n\n\n", p1[0], p1[1]);

    if (p1[0] <= 0 || p1[0] >= 1 - p1[1]) 
        return NULL;
    
    p1[0] = p1[0] / (1-p1[1]);
    p1[1] = p1[0] * m[2] + e1[0][1];
    p1[0] = p1[0] * m[0] + e1[0][0];
    return p1;
}

int main(int argc, char** argv) {

    float pts[10] = {

0.2872233614488351, 2.6866746102120915, 4.843282585757584, 2.440882398917314, 2.348329625124767, 3.28682396564802, 0.4069989349216918, 2.2290487479349235

    };
    float* e1[2] = {pts+0, pts+2};
    float* e2[2] = {pts+4, pts+6};

    printf("e1 :  x: %f   y : %f <-> x: %f   y : %f\n", e1[0][0], e1[0][1], e1[1][0], e1[1][1]);
    printf("e2 :  x: %f   y : %f <-> x: %f   y : %f\n", e2[0][0], e2[0][1], e2[1][0], e2[1][1]);
    printf("\n\n\n");

    float* inte = intersec2D(e1,e2);

    printf("fin fct\n");

    if (inte != NULL)
        printf("\nx : %f, y : %f\n", inte[0], inte[1]);
        //printf("x : %f, y : %f\n", pts[8],pts[9]);
    
    return 0;
}