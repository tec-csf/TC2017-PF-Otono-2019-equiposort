# *[Poner aquí el Título del Proyecto]*
---
#### Materia: *Análisis y Diseño de Algoritmos (TC2017)*

#### Semestre: *Otoño 2019*

##### Campus: *Santa Fe*

##### Integrantes:
1. *Luis Antonio García García* *A01021865*
2. *Saúl Montes de Oca Martínez* *A01025975*

---
## 1. Aspectos generales

### 1.1 Requerimientos

A continuación se mencionan los requerimientos mínimos del proyecto, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir el problema a resolver.
* El proyecto deberá utilizar [OpenMP](https://www.openmp.org/) para la implementación del código paralelo.
* Todo el código y la documentación del proyecto debe alojarse en este repositorio de GitHub. Favor de mantener la estructura de carpetas propuesta.

### 1.2 Estructura del repositorio
El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de todo el proyecto
    - README.md			# este archivo
    - secuencial		# Carpeta con la solución secuencial
    - paralelo			# Carpeta con la solución paralela
    - docs              # Carpeta con los documentos, tablas, gráficas, imágenes
```

### 1.3 Documentación  del proyecto

Como parte de la entrega final del proyecto, se debe incluir la siguiente información:

* Descripción del problema a resolver.
* Descripción de la solución secuencial con referencia (enlace) al código secuencial alojado en la carpeta [secuencial](secuencial/).
* Análisis de los inhibidores de paralelismo presente y una explicación de cómo se solucionaron.
* Descripción de la solución paralela con referencia (enlace) al código paralelo alojado en la carpeta [paralelo](paralelo/).
* Tabla de resultados con los tiempos de ejecución medidos para cada variante de la solución secuencial vs. la solución paralela, teniendo en cuenta: 5 tamaños diferentes de las entradas, 5 opciones diferentes de números de CPU (threads), 4 ocpiones diferentes de balanceo (*auto, guided, static, dynamic*).
* Gráfica(s) comparativa(s) de los resultados obtenidos en las mediciones.
* Interpretación de los resultados obtenidos.
* Guía paso a paso para la ejecución del código y replicar los resultados obtenidos.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Descripción del problema

El problema que se busca resolver es conocido originalmente como el problema de las 8 reinas, sin embargo la variente que implementamos consiste en resolver con N reinas, siempre y cuando el número de reinas a colocar sea mayor a 3.
La solución debe estar mostrada en un tablero donde observaremos que las N reinas colocadas no se amenazan entre sí, esto debido a las reglas del ajedrez que dicen que la reina puede moverse a cualquier dirección y con cualquier número de casillas que estén libres. Es así que no deben existir reinas en la misma fila,columna y diagonal.

## 3. Solución secuencial

La solución planteada de forma secuencial consiste en preguntar al usuario cuantas reinas desea colocar. Posterior a eso, el programa crea el tablero con n filas, n columnas y 2n diagonales, siguiendo esto se rellena el tablero con números 1 para que de esta manera entrando a la función que resolvera el problema se puedan checar si valores en la columna,fila o diagonal se repiten, así entonces la función si se repite borrará cualquier valor que afecte a la resolución del problema, finalmente tras acabar con las iteraciones se manda a llamar una función que imprimirá el tablero, esta impresión la hace con un if, en caso de que el valor que quedó fue un 1 entonces se sustituye por una Q indicando que es una reina, de lo contrario se imprime un 0.

## 4. Análisis de los inhibidores del paralelismo

Algunos inhibidores que se detectaron fue en la creación de el tablero, ya que creaba las columnas, filas y diagonales por separado, así como el llenado del tablero, igualmente el for del llenado del tablero se detectó que podría ser un problema que causara un aumento de tiempo de solución.

## 5. Solución paralela

*[Incluya aquí la descripción de la solución paralela.]*

## 6. Tabla de resultados



## 7. Gráfica(s) comparativa(s)

*[Incluya aquí la(s) gráfica(s) comparativa(s).]*

## 8. Interpretación de los resultados

*[Incluya aquí la interpretación de los resultados.]*

## 9. Guía paso a paso

*[Incluya aquí la guía para la ejecución de los códigos.]*

## 10. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar el proyecto y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
