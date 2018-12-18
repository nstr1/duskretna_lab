#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

short ver_am = 0;
struct vert *list[20];
short veco = 0;

struct vert{ short id;
    short degr;
    short used;
    short way;
    struct vert *prev;
    struct edge *edge[10];
};

struct edge{
    short v1id;
    short v2id;
    short wght;
    short used;
    struct vert *v1pt;
    struct vert *v2pt;
};



struct vert *create();                                          // create vert
void edge(struct vert *a, struct vert *b, short weight);  		// edge
void start(struct vert *vert);                                  // 
void dijkstra(struct vert *vert);
void way(struct vert *vert);                                    // min way


int main(){
    
    struct vert *v0 = create();     struct vert *v1 = create();     struct vert *v2 = create();
    struct vert *v3 = create();     struct vert *v4 = create();     struct vert *v5 = create();
    struct vert *v6 = create();     struct vert *v7 = create();     struct vert *v8 = create();
    struct vert *v9 = create();     struct vert *v10 = create();    struct vert *v11 = create();
    struct vert *v12 = create();    struct vert *v13 = create();    struct vert *v14 = create();
    struct vert *v15 = create();    struct vert *v16 = create();    struct vert *v17 = create();
    struct vert *v18 = create();    struct vert *v19 = create();    struct vert *v20 = create();
    struct vert *v21 = create();    struct vert *v22 = create();    struct vert *v23 = create();
    struct vert *v24 = create();    struct vert *v25 = create();    struct vert *v26 = create();
    struct vert *v27 = create();    struct vert *v28 = create();    struct vert *v29 = create();
    
    
    edge(v0,v1,3);   edge(v0,v6,4);   edge(v1,v2,5);   edge(v1,v7,3);
    edge(v2,v3,7);   edge(v2,v8,3);   edge(v3,v4,8);   edge(v3,v9,4);
    edge(v4,v5,5);   edge(v4,v10,4);  edge(v5,v11,1);  edge(v6,v7,6);
    edge(v6,v12,2);  edge(v7,v8,3);   edge(v7,v13,1);  edge(v8,v9,1);
    edge(v8,v14,7);  edge(v9,v10,2);  edge(v9,v15,4);  edge(v10,v11,8);
    edge(v10,v16,1); edge(v11,v17,5); edge(v12,v13,4); edge(v12,v18,3);
    edge(v13,v14,2); edge(v13,v19,1); edge(v14,v15,2); edge(v14,v20,6);
    edge(v15,v16,7); edge(v15,v21,7); edge(v16,v17,7);
    edge(v16,v22,7); edge(v17,v23,7); edge(v18,v19,1); edge(v18,v24,4);
    edge(v19,v20,3); edge(v19,v25,2); edge(v20,v21,1); edge(v20,v26,3);
    edge(v21,v22,1); edge(v21,v27,8); edge(v22,v28,1); edge(v22,v23,5);
    edge(v23,v29,8); edge(v24,v25,3); edge(v25,v26,3); edge(v26,v27,3);
    edge(v27,v28,3); edge(v28,v29,1);

    start(v0);
    printf("\n\n"); way(v29);
    printf("The shortest way is %i", v29->way);
    
}


struct vert *create(){
    struct vert *vert = (struct vert*)
    malloc(sizeof(struct vert));
    vert->id = ver_am; vert->degr = 0;
    vert->used = 0;
    vert->way = SHRT_MAX;
    ver_am++;
    return vert;
}

void edge(struct vert *a, struct vert *b, short weight){
    struct edge *edge = (struct edge*) malloc(sizeof(struct edge));
    edge->v1id = a->id; edge->v2id = b->id; edge->wght = weight;
    edge->v1pt = a; edge->v2pt = b;
    a->edge[a->degr] = edge; a->degr++;
    b->edge[b->degr] = edge; b->degr++;
}

void start(struct vert *vert){
    vert->way = 0; vert->prev = NULL; dijkstra(vert) ;
}

void dijkstra(struct vert *vert){
    list[veco] = vert; vert->used = 1; veco++;
    for (short j = 0; j < veco; j++){
        for (short i = 0; i < list[j]->degr; i++){
            if (list[j]->way + list[j]->edge[i]->wght < list[j]->edge[i]->v2pt->way){
                list[j]->edge[i]->v2pt->prev = list[j];
                list[j]->edge[i]->v2pt->way = list[j]->way + list[j]->edge[i]->wght;
            }
            if (list[j]->way + list[j]->edge[i]->wght < list[j]->edge[i]->v1pt->way){
                list[j]->edge[i]->v1pt->prev = list[j];
                list[j]->edge[i]->v1pt->way = list[j]->way + list[j]->edge[i]->wght;
            }
        }
        for (short i = 0; i < list[j]->degr; i++){
            if (list[j]->edge[i]->v2pt->used == 0) dijkstra(list[j]->edge[i]->v2pt); if (list[j]->edge[i]->v1pt->used == 0) dijkstra(list[j]->edge[i]->v1pt);
        }
    }
}

void way(struct vert *vert){
    if (vert->prev != NULL){
        printf("v%d <-- ", vert->id);
        way(vert->prev);
    }
    else if (vert->prev == NULL)
        printf("v%d\n", vert->id);
}

  