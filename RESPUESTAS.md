% Contesten aquí la pregunta sobre complejidad

- Generalidad

Si se cambiase la estructura Jugadas (originalmente pos x Z) por una matriz que indique
las minas adyacentes a dicha posición, se tendria que cargar constantemente una carga de datos bastante superior
a la actual (estariamos llamando y guardando una especie de tablero todo el tiempo, en vez de los datos relevantes). Por
lo cual, cuanto más grande sea el tablero, mayores serían los datos guardados en jugadas.

A modo de ejemplo, si se jugase por primera vez con la estructura original se guardaria un solo un dato. 
En cambio si se jugase con esta nueva estructura se tendria que guardar n² datos, siendo n
el tamaño de columnas o filas del tablero.

No obstante, al ya poseer esta estructura, podriamos modificar las funciones jugarPlus y sugerirAutomatico121 ya que el
chequeo de esJUgada (dichas funciones lo requieren) sería más sencilla, y directamente podriamos crear una función que verifique 
si esa jugada es "-1" (indica si fue o todavia no fue jugada esa casilla)

- jugarPLus

En dicha función, si la cambiasemos de forma que corresponda con esta  nueva estructura modificariamos el for de la misma por
otra funcion que recorra las minas adyacentes a la jugada y que desbloquease las jugadas que corresponde a "-1".

La misma tendria una complejidad de o(n²)


- sugerirAutomatico121

En esta función, se haria más sencillo el chequeo de esJugada ya que se eliminarian los fo de la misma, y toda la función 
sugerirAutomatico solo tendria una sola llamada for en getPosIndexEnBanderitas, con lo cual la complejidad en el peor de los 
casos sería o(n)
