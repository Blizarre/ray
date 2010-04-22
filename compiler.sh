CFLAGS="-O3 -g --fast-math -m64 -march=core2 -Wall"
#CFLAGS="-O0 -ggdb"

rm -f prog *.o

function fail {
    echo "Erreur"
    exit 1
}

echo "Demarrage de la compilation"
g++ $CFLAGS -c test.c -o test.o -c -I /usr/include/SDL/ || fail
g++ $CFLAGS -c simpleSDL.c -o simpleSDL.o -I /usr/include/SDL/ || fail
g++ $CFLAGS -lSDL   simpleSDL.o test.o -o prog || fail

echo "Terminé"
