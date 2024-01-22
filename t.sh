gcc -o app app.c lib1.c imread.c $(sdl2-config --cflags --libs)
echo
echo "compilation ended"
echo
./app