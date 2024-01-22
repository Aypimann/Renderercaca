gcc -o bin/app source/app.c source/lib1.c source/imread.c $(sdl2-config --cflags --libs)
echo
echo "compilation ended"
echo
./bin/app
