#include"vecteur3.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#define NBVECT (50000000)

typedef Vecteur3<int> iVect;
typedef Vecteur3<float> fVect;
typedef Vecteur3<double> dVect;

int main(int argc, char * argv[]) {

    int val;
    if(argc == 2)
        val = atoi(argv[1]);
    else
        val = 2;

    int isalt = (int)val;
    float fsalt = (float)val;
    double dsalt = (double)val;

    iVect *tabiVect = new iVect[NBVECT];
    fVect *tabfVect = new fVect[NBVECT];
    dVect *tabdVect = new dVect[NBVECT];
    
    int i;
    clock_t tdebut, tfloat, tint, tdouble;   
    double isumNorm = 0;
    double fsumNorm = 0;
    double dsumNorm = 0;

    tdebut = clock();
    for(i=0;i<NBVECT;i++) {
        tabiVect[i] = iVect(i-isalt,(int)i,i+isalt);
        tabiVect[i].normer(10);
        isumNorm += tabiVect[i].norme();
    }
    delete tabiVect;
    tint = clock();

    for(i=0;i<NBVECT;i++) {
        tabfVect[i] = fVect(i-fsalt,(float)i,i+fsalt);
        tabfVect[i].normer(10);
        fsumNorm += tabfVect[i].norme();
    }
    delete tabfVect;
    tfloat = clock();


    for(i=0;i<NBVECT;i++) {
        tabdVect[i] = dVect(i-dsalt,(double)i,i+dsalt);
        tabdVect[i].normer(10);
        dsumNorm += tabdVect[i].norme();
    }
    delete tabdVect;
    tdouble = clock();


    cout <<fsumNorm <<" " <<dsumNorm <<"" <<isumNorm <<endl;
    cout <<"time int    : " <<((double)tint-tdebut)/CLOCKS_PER_SEC <<endl;
    cout <<"time Float  : " <<((double)tfloat-tint)/CLOCKS_PER_SEC <<endl;
    cout <<"time Double : " <<((double)tdouble-tfloat)/CLOCKS_PER_SEC <<endl;

    return 0;
}
