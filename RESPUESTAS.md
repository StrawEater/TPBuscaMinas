% Contesten aquí la pregunta sobre complejidad

- Generalidad

Si se cambiase la estructura Jugadas (originalmente pos x Z) por una matriz que indique
las minas adyacentes a dicha posición, se tendria que cargar al inicio una carga de datos bastante superior
a la actual (estariamos llamando y guardando una especie de tablero). Por
lo cual, cuanto más grande sea el tablero, mayores serían los datos guardados en jugadas.

A modo de ejemplo, si se jugase con un tablero de n elementos, se tendria que inicializar el juego cargando una matriz de jugadas con el mismo tamaño, aumentando la carga inical n veces que la actual, donde solo se define un vector vacio sin tomar en cuenta n.

No obstante, al ya poseer esta estructura, podriamos modificar las funciones jugarPlus y sugerirAutomatico121 ya que el
chequeo de esJugada (dichas funciones lo requieren) sería más sencilla, y directamente podriamos crear una función que verifique 
si esa posicion es "-1", indicando si fue o no jugada. Esto reduciria la complejidad de esJugada, originalmente la lonjitud de j y en su peor caso n, a 1 independientemente del tablero.  


- jugarPLus

En dicha función, si la cambiasemos de forma que corresponda con esta nueva estructura su complejidad no disminuiría. El peor caso sería un tablero sin bombas y con banderas que se encontrarían distribuidas en forma de un tablero de ajedrez.

Por ejemplo:

                                   ┌───┬───┬───┐
                                   | B │ 0 │ B │
                                   ├───┼───┼───┤
                                   │ 0 │ B │ 0 │
                                   ├───┼───┼───┤
                                   │ B │ 0 │ B │
                                   └───┴───┴───┘

Si se fuera a jugar una posición sin banderas, el codigo se correría n veces (1 vez por cada celda), con una complejidad igual a la que se tiene para verificar si una celda es bandera o no. La cual es igual a la cantidad de banderas en el tablero correspondiente, que sería n/2 o (n-1)/2 dependiendo si n es par o impar, respectivamente. 

Entonces, se corre n veces un codigo con complejidad n/2 o (n-1)/2, lo cual daría una complejidad de n²/2 o (n²-n)/2, que sería equivalente a O(n²).


- sugerirAutomatico121

En esta función en el peor caso la complejidad seria la misma, o sea O(n²), esto debido a que el peor caso seria cuando todas menos una de las casillas de la matriz son banderitas. Esto se debe a que en nuestro algoritmo buscamos por todo el tablero alguna casilla jugada que tenga 2 minas adyacentes, si la unica posicion jugada es la ultima en verse el tablero se tendra que recorrer por completo, a su vez la funcion esJugada pasaria a tener complejidad 1 y noEsBanderita, que depende de getPosIndexEnBanderitas, tendra complejidad n-1, el ciclo inicial siempre tendra complejidad n porque deberia recorrer toda la matriz para chequear si la posicion fue jugada. Por lo tanto la cuenta seria n*(n-1) que es n²-n que pertenece a O(n²).
