#include <stdio.h>
#include <stdlib.h>

float* intersec2D(float** l1, float** l2){
    float* m = malloc(4*sizeof(float)); 
    m[0] = l1[1][0] - l1[0][0];
    m[2] = l1[1][1] - l1[0][1];
    m[1] = l2[0][0] - l1[0][0];
    m[3] = l2[0][1] - l1[0][1];
    float* m_1 = malloc(4*sizeof(float));
    float inv_det = m[0]*m[3]-m[1]*m[2];
    if (inv_det == 0) {
        printf("to be continued !");
        return NULL;
    }
    inv_det = 1/inv_det;
    m_1[0] = m[4] * inv_det;
    m_1[1] =-m[1] * inv_det;
    m_1[2] =-m[2] * inv_det;
    m_1[4] = m[0] * inv_det;

    float* p1 = malloc(2*sizeof(float));
    p1[0] = l2[1][0] * m[0] + l2[1][1] * m[1];
    p1[1] = l2[1][0] * m[2] + l2[1][1] * m[3];
    int b = p1[0] > 0 && p1[0] < 1 - p1[1];
    if (b) p1[0] = p1[0] / (1-p1[1]);
    printf("b : %d   x : %f    y :%f\n",b,p1[0],p1[1]);
    p1[1] = p1[0] * m[1] + l1[0][0];
    p1[0] = p1[0] * m[0] + l1[0][0];
    free(m);
    free(m_1);
    if (b) return p1;
    return NULL;
}

int main(int argc, char** argv) {
    float pts[10] = {2.16, 2.91, 4.11, 2.42, 1.38, 1.32, 4.4, 4.1, 2.88, 2.73};
    float* l1[2] = {pts+0, pts+2};
    float* l2[2] = {pts+4, pts+6};

    float* inte = intersec2D(l1,l2);

    if (inte != NULL)
        printf("\nx : %f, y : %f\n", inte[0], inte[1]);
    
    return 0;
}