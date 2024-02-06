gcc -o bin/app source\ code/app.c source\ code/lib1.c source\ code/imread.c $(sdl2-config --cflags --libs)
echo
echo "compilation ended"
echo
./bin/app "./resources/test3.ayp"