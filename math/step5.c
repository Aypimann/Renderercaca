/*
/!\/!\/!\
never tested
/!\/!\/!\

TODO : IMPORTANT OPTI : USE GC for regions

5)
découpe des faces:
    On veut une face visible ssi tous ses somets sont visibles.
    on utilise intersec
    TODO
*/

float* intersec2D(float** e1, float** e2);

void divide_faces(float** vertices, int vertices_nb, float** edges, float*** faces_edges, int face_nb){
    float**** sub_faces = malloc(face_nb * sizeof(void*));
    char* f = malloc(0); //TODO
    //TODO use regions
    int i, j;
    float* intersec;
    for(i = 0; i < vertices_nb; i++)
        for(j = i + 1; j < vertices_nb; j++) {
            intersec = intersec2D(vertices[i], vertices[j]);
        }
}

int box(float* e1, float* e2) {
    float e2xmax, e2ymax, e2xmin, e2ymin;
}


int main(int argc, char** argv){
    printf("coucou\n");
    return 0;
}