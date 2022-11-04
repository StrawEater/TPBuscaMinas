% Contesten aquí la pregunta sobre complejidad

- Generalidad

Si se cambiase la estructura Jugadas (originalmente pos x Z) por una matriz que indique
las minas adyacentes a dicha posición, se tendria que cargar constantemente un carga de datos bastante superior
a la actual (estariamos llamando y guardando una especie de tablero todo el tiempo, en vez de los datos relevantes). Por
lo cual, cuanto más grande sea el tablero, mayores serían los datos guardados en jugadas.

A modo de ejemplo, si se jugase por primera vez con la estructura original se guardaria un solo un dato. 
En cambio si se jugase con esta nueva estructura se tendria que guardar n² datos, siendo n
el tamaño de columnas o filas del tablero.

- jugarPLus

El peor de los casos en la función jugarPLus sería jugar una posición en donde no haya minas
adyacentes y que tampoco haya minas adyacentes en las casillas adyacentes a esta ya que se deberia
descubrir  mayor cantidad de casillas (y que, con esta estructura sería cargar varias veces varios tableros de forma simultanea).

En nuestro caso nos encontramos con el problema al verificar si la jugada fue jugada (en nuestro
caso se la llama al menos una vez, o sino varias veces dependiendo si hay un camino libre) y al
guardarla dentro de Jugadas.

Este caso la complejidad sería o(n^k)

- sugerirAutomatico121

En la funcion sugerirAutomatico121 el peor de los casos sería un tablero con varias sugerencias (ya sean al final True o False)
del patron121.

En nuestro caso con que con tan solo se cumpla de que exista una casilla que tenga 2 minas adyacentes y que aquella sea una posición válida (o sea simplemente 
este en el tablero), entraría en el caso de evaluar patron_Y_Asignacion_A_P, la cual llama a los diferentes tipos de patrones posibles (2 casos) y que ésta ultima verifica que no haya sido jugada 
esa posición ni en las adyacentes. Con lo cual se llamaria en el mejor de los casos 2 veces; mientras
que en el peor de los casos seria 6 veces.

En este caso la complejidad seria o (n^k)