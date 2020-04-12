== FUNCIONES EXPLICADAS ==

1. crearCentroComercial(int * fil, int * col)
Recibe la cantidad de pisos y locales por piso que tendrá el 
centro comercial.
Retorna el centro comercial.
Se usa memoria dinámica y paso por referencia.

2. agregarLocal(int fil, int col, Local ** centroComercial)
Recibe el tamaño del centro comecial (fil y col) y el
centro comercial.
No retorna pues es void.
Se hace uso de enums (disponible y noDisponible)

3.eliminarLocal(int fil, int col, Local ** centroComercial)
Recibe el tamaño del centro comecial (fil y col) y el
centro comercial.
No retorna pues es void.

4. verTodosLocales(int fil, int col, Local ** centroComercial)
Recibe el tamaño del centro comecial (fil y col) y el
centro comercial.
No retorna pues es void.
Imprime todos los locales arrendados.
Se hace uso de bucles.

5.cantidadLocalesDisponibles(int fil, int col, Local ** centroComercial, int i, int j, int counter)
Recibe el tamaño del centro comecial (fil y col), el
centro comercial, y los valores de i, j, y counter. Siendo i y j
usadas para iterar y counter para contar los locales disponibles.
Retorna counter, esto es, el número de locales disponibles.
Usa recursividad.

6. verLocalesDisponibles(int fil, int col, Local ** centroComercial, int i, int j)
Recibe el tamaño del centro comecial (fil y col), el
centro comercial, y los valores de i y j. Siendo i y j
usadas para iterar.
Muestra info de los locales disponibles.
Usa recursividad.

7. modificarNombreLocal(int fil, int col, Local ** centroComercial)
Recibe el tamaño del centro comecial (fil y col) y el
centro comercial.
Modifica el nombre de un local que se encuentre arrendado.
Se hace uso de enums.

8. menu()
No recibe nada, es simplemente el menu que imprime las opciones.

Parcial 2: Daniel Caicedo Jaramillo