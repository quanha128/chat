raytracer: array.o camera.o color.o geometry.o light.o main.o material.o mesh.o png_render.o ray.o vector.o scene.o surface.o raytracer.o
	gcc -Wall -fopenmp -O3 $^ -lpng -lm -o raytracer

%.o: %.c
	gcc -Wall -c -fopenmp -O3 $< -lpng -lm -o $@

array.o: array.c array.h
camera.o: camera.c camera.h
color.o: color.c color.h
geometry.o: geometry.c geometry.h
light.o: light.c light.h
main.o: main.c
material.o: material.c material.h
mesh.o: mesh.c mesh.h
png_render.o: png_render.c png_render.h
ray.o: ray.c ray.h
vector.o: vector.c vector.h
scene.o: scene.c scene.h
surface.o: surface.c surface.h
raytracer.o: raytracer.c raytracer.h

clean:
	rm -f *.o output.png raytracer