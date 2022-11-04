% Contesten aquí la pregunta sobre complejidad

- Generalidad

Si se cambiase la estructura Jugadas (originalmente pos x Z) por una matriz que indique
las minas adyacentes a dicha posición, se tendria que cargar al inicio una carga de datos bastante superior
a la actual (estariamos llamando y guardando una especie de tablero). Por
lo cual, cuanto más grande sea el tablero, mayores serían los datos guardados en jugadas.

A modo de ejemplo, si se jugase con un tablero de n elementos, se tendria que inicializar el juego cargando una matriz de jugadas con el mismo tamaño, aumentando la carga inical n veces que la actual, donde solo se define un vector vacio sin tomar en cuenta n.

No obstante, al ya poseer esta estructura, podriamos modificar las funciones jugarPlus y sugerirAutomatico121 ya que el
chequeo de esJugada (dichas funciones lo requieren) sería más sencilla, y directamente podriamos crear una función que verifique 
si esa posicion es "-1", indicando si fue o no jugada. Esto reduciria la complejidad de esJugada, originalmente la lonjitud de j y en su peor caso n, a 1 independientemente del tamblero.  

- jugarPLus

En dicha función, si la cambiasemos de forma que corresponda con esta nueva estructura su complejidad en el peor caso posible disminuiria de forma significativa. Esto sucede porque su complejidad viene de la funcion EsJugada, la cual tiene que chequear todo el vector jugadas cada vez, teniendo complejidad longitud de j. Si la estructura de j fuera una matriz, la complejidad de chequear que una posicion es o no jugada se vuelve 1, bajando la complejidad de cada ciclo a 1. Es decir, la complejidad en su peor caso se convertiria en n.

- sugerirAutomatico121

En esta función en el peor caso la complejidad seria la misma, o sea O(n²), esto debido a que el peor caso seria cuando todas menos una de las casillas de la matriz son banderitas. Esto se debe a que en nuestro algoritmo buscamos por todo el tablero alguna casilla jugada que tenga 2 minas adyacentes, si la unica posicion jugada es la ultima en verse el tablero se tendra que recorrer por completo, a su vez la funcion esJugada pasaria a tener complejidad 1 y noEsBanderita, que depende de getPosIndexEnBanderitas, tendra complejidad n-1, el ciclo inicial siempre tendra complejidad n porque deberia recorrer toda la matriz para chequear si la posicion fue jugada. Por lo tanto la cuenta seria n*(n-1) que es n²-n que pertenece a O(n²).
