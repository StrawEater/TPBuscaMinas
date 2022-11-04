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
chequeo de esJugada (dichas funciones lo requieren) sería más sencilla, y directamente podriamos crear una función que verifique 
si esa jugada es "-1" (indica si fue o todavia no fue jugada esa casilla)

- jugarPLus

En dicha función, si la cambiasemos de forma que corresponda con esta  nueva estructura se debería modificar el for de la misma por
otra función que recorra las minas adyacentes a la jugada y que desbloquease las jugadas adyacentes que correspondan a "-1".

La misma tendria una complejidad de o(n²) y depende del largo del tablero


- sugerirAutomatico121

En esta función en el peor caso la complejidad seria lo mismo, o sea O(n²), esto debido a que el peor caso seria cuando todas menos una de las casillas de la matriz son banderitas. Esto se debe a que en nuestro algoritmo buscamos por todo el tablero alguna casilla jugada que tenga 2 minas adyacentes, si la unica posicion jugada es la ultima en verse el tablero se tendra que recorrer por completo, a su vez la funcion esJugada pasaria a tener complejidad 1 y noEsBanderita, que depende de getPosIndexEnBanderitas, tendra complejidad n-1, el ciclo inicial siempre tendra complejidad n porque deberia recorrer toda la matriz para chequear si la posicion fue jugada. Por lo tanto la cuenta seria n*(n-1) que es n²-n que pertenece a O(n²), que en nuestras notaciones(que tomamos n = t²) seria O(t⁴). 
