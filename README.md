# PRO2-FIB-PracticaADN
University project done during the PRO2 subject in FIB, UPC. 2016-2017

Grade: **10.0**.

# How to run

First, execute make in the console:
```
make
```

then, run the program generated in console with the command:
```
./program.exe
```

# Statement
# Jutge.org

The Virtual Learning Environment for Computer Programming

## Pràctica de PRO2 - Primavera 2017 - lliurament definitiu X84905 ca

**En negreta s’indiquen les novetats respecte el problema del Jutge per fer el lliurament provisional de la pràctica.**

Aquest és el problema de Jutge que permet fer **el lliurament definitiu de la pràctica.**

Avisos importants:

- **Tothom ha de lliurar la seva pròpia pràctica.**
- **Un únic integrant designat de cada equip ha de lliurar el treball en equip.**
- **Només avaluarem el darrer enviament realitzat dins el termini establert.**
-  **No superar cap joc de proves suposa una nota de zero de tota la pràctica.**
- **Recomanem fer servir el lliurament per la pràctica provisional fins a tenir enllestida la pràctica definitiva.**

## Entrada

Una seqüència d’instruccions seguint el format de l’enunciat de la pràctica i del joc de proves public.

## Sortida

El seu resultat seguint el format de l’enunciat de la pràctica i del joc de proves public.

## Observació

El Jutge prova el vostre lliurament mitjanc ̧ant 4 jocs de proves:

- sample: el joc de proves p ́ublic.
- privat1: joc de proves privat que fa emfasi en l’operacio de reproduccio.
- privat2: joc de proves privat que fa emfasi en l’operacio d’arbre genealogic per nivells.
- privat3: joc de proves privat que fa emfasi en l’operacio d’arbre genealogic completable.

Son els mateixos jocs de proves que els de la practica provisional.

En un fitxer de nompractica.tar heu de lliurar

- Els fitxers .hh i .cc **de les classes que heu implementat (amb els comentaris de Doxygen escaients)**.
- El fitxer Makefile (l’usarem per generar el fitxer executable i provar-lo).
- **Un únic integrant designat de cada equip ha de lliurar un fitxer** zip **amb el treball en equip seguint les instruccions que trobareu al document sobre la competència de treball en equip a la pagina web de l’assignatura.**


- Un fitxer **html.zip**, obtingut zipejant la carpeta html del doxygen generat a partir dels .cc i els .hh dels m`oduls. La documentaci ́o en Doxygen no sols ha de cobrir la part p ́ublica de les classes (com al lliurament de l’especificacio) sinó tambe la part privada (atributs i metodes privats). 

Tingueu en compte les restriccions seg ̈uents:

- El modul que conte la funció main s’ha de dir program.cc.
- El Makefile ha de generar un executable de nomprogram.exe.
- Recomanem que useu les opcions de compilaci ́o del Jutge de PRO2 (vegeu Documentation→Compilers→PRO2 a [http://www.jutge.org).] http://www.jutge.org).)
- No usar l’opcio -DGLIBCXXDEBUG o no usar-la correctament serà fortament penaitzat.

Produïu el fitxer .tar amb la comanda

tar -cvf practica.tar fitxer1 fitxer2 fitxer ...

des del directori on es troben els fitxers que heu de lliurar. Poseu aquesta instruccio en el vostre Makefilede forma que es pugui generar el .tar executant make practica.tar.

Amb aixo reduireu la possibilitat d’error en enviaments successius. El Jutge no accepta.tar on els fitxers a lliurar es troben dins de carpetes. Recomanem usar GNU tarper reduir el risc que el .tar singui incompatible amb el Jutge.

**Exemple d’entrada**
```
5 
3 6 7 6 7 6
5 3

3
a1
X
0 1 1 1 0
0 0 1 0 1
1 1 1 1 1 0  
0 0 0 1 1 1
1 1 1 0 1 1 0 
0 1 1 0 1 0 0
0 1 1 1 0 0  
1 0 0 1 1 0
1 1 1 0 1 1 0 
0 1 1 0 1 1 1
1 1 1 1 1 0  
0 1 0 1 0 0

a2
X
0 1 1 0 1
1 1 0 0 0
0 1 1 1 0 0  
1 0 0 1 1 0
1 1 1 0 1 1 0 
0 1 1 0 1 1 1
1 1 1 1 1 0  
0 1 0 1 0 0
1 1 1 1 1 0 0 
0 0 1 1 1 0 0
1 1 1 0 1 1  
0 0 1 1 0 1

b3
Y
1 0 1 0 0 
1 0 0
1 1 1 1 1 0  
1 1 0 1 1 0
1 1 1 0 1 1 0 
0 1 1 0 1 0 0
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 0 0 1 0 
0 0 0 0 1 1 1
1 1 1 0 1 1  
0 0 1 1 0 1

anadir_individuo
b4
Y
1 1 0 0 1 
0 1 0
1 0 0 0 1 0  
1 1 1 1 1 1
0 0 0 0 0 0 0 
1 0 1 0 1 1 1
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 1 1 1 0 
0 1 1 0 1 0 0
1 1 1 1 1 0  
0 0 0 1 1 1

anadir_individuo
a2
Y
1 1 0 0 1 
0 1 0
1 0 0 0 1 0  
1 1 1 1 1 1
0 0 0 0 0 0 0 
1 0 1 0 1 1 1
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 1 1 1 0 
0 1 1 0 1 0 0
1 1 1 1 1 0  
0 0 0 1 1 1

escribir_poblacion

reproduccion_sexual
a1 b3 c1
0 1 2
1 1 3
1 0 5
1 1 4
0 0 3
1 1 4

reproduccion_sexual
a2 b4 d2
1 1 1
0 0 3
1 0 4
0 0 4
1 1 3
0 1 2

reproduccion_sexual
a0 b4 d3
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

escribir_poblacion

reproduccion_sexual
c1 b3 w6
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

reproduccion_sexual
c1 d2 e1
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

escribir_poblacion

escribir_arbol_genealogico
d1 

escribir_arbol_genealogico
c1 

completar_arbol_genealogico
d1 $ $

completar_arbol_genealogico
c1 $ $

completar_arbol_genealogico
e1 $ c1 $ $

anadir_individuo
m1
X
1 1 0 0 1 
0 1 0 0 1
1 0 0 0 1 0  
1 1 1 1 1 1
0 0 0 0 0 0 0 
1 0 1 0 1 1 1
0 1 1 1 0 0  
1 0 0 1 1 0
1 0 1 1 1 1 0 
0 1 1 0 1 0 0
1 1 1 1 1 0  
0 0 0 1 1 1

reproduccion_sexual
m1 c1 e1
0 1 2
1 1 3
1 0 5
0 0 4
1 1 3
0 1 2

reproduccion_sexual
m1 c1 h1
1 0 2
1 1 3
1 0 2
0 0 4
1 1 3
0 1 2

escribir_genotipo
h1

escribir_poblacion

completar_arbol_genealogico
e1 c1 $ $ $

escribir_genotipo
b4

escribir_genotipo
c1

escribir_genotipo 
nemo

escribir_genotipo
d2

acabar
```

**Exemple de sortida**
```
anadir_individuo b4
anadir_individuo a2
  error
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
reproduccion_sexual a1 b3 c1
reproduccion_sexual a2 b4 d2
reproduccion_sexual a0 b4 d3
  error
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
  c1 XY (b3,a1)
  d2 XY (b4,a2)
reproduccion_sexual c1 b3 w6
  no es posible reproduccion
reproduccion_sexual c1 d2 e1
  no es posible reproduccion
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
  c1 XY (b3,a1)
  d2 XY (b4,a2)
escribir_arbol_genealogico d1
  error
escribir_arbol_genealogico c1
  Nivel 0: c1
  Nivel 1: b3 a1
completar_arbol_genealogico d1
  no es arbol parcial
completar_arbol_genealogico c1
  c1 *b3* $ $ *a1* $ $
completar_arbol_genealogico e1
  no es arbol parcial
anadir_individuo m1
reproduccion_sexual m1 c1 e1
reproduccion_sexual m1 c1 h1
escribir_genotipo h1
  X: 0 1 0 0 1
  X: 0 1 0 1 0
  1.1: 1 1 1 1 1 1
  1.2: 1 1 0 1 1 1
  2.1: 1 0 1 0 1 1 0
  2.2: 0 1 1 0 1 1 1
  3.1: 0 1 1 1 1 0
  3.2: 1 0 0 1 0 0
  4.1: 0 1 1 0 1 1 0
  4.2: 1 0 1 0 1 0 0
  5.1: 1 1 1 1 0 0
  5.2: 0 0 1 1 1 0
escribir_poblacion
  a1 XX ($,$)
  a2 XX ($,$)
  b3 XY ($,$)
  b4 XY ($,$)
  c1 XY (b3,a1)
  d2 XY (b4,a2)
  e1 XY (c1,m1)
  h1 XX (c1,m1)
  m1 XX ($,$)
completar_arbol_genealogico e1
  e1 c1 *b3* $ $ *a1* $ $ *m1* $ $
escribir_genotipo b4
  X: 1 1 0 0 1
  Y: 0 1 0
  1.1: 1 0 0 0 1 0
  1.2: 1 1 1 1 1 1
  2.1: 0 0 0 0 0 0 0
  2.2: 1 0 1 0 1 1 1
  3.1: 0 1 1 1 0 0
  3.2: 1 0 0 1 1 0
  4.1: 1 0 1 1 1 1 0
  4.2: 0 1 1 0 1 0 0
  5.1: 1 1 1 1 1 0
  5.2: 0 0 0 1 1 1
escribir_genotipo c1
  X: 0 1 0 1 0
  Y: 1 0 1
  1.1: 0 0 0 1 1 0
  1.2: 1 1 0 1 1 1
  2.1: 0 1 1 0 1 1 0
  2.2: 1 1 1 0 1 0 0
  3.1: 1 0 0 1 1 0
  3.2: 1 0 0 1 1 0
  4.1: 1 1 1 0 0 1 0
  4.2: 1 0 1 0 1 1 0
  5.1: 0 1 0 1 0 1
  5.2: 0 0 1 1 0 0
escribir_genotipo nemo
  error
escribir_genotipo d2
  X: 1 1 0 0 0
  Y: 0 1 0
  1.1: 0 1 1 0 1 0
  1.2: 1 0 0 1 0 0
  2.1: 0 1 1 0 0 0 0
  2.2: 0 0 0 0 1 1 1
  3.1: 1 1 1 1 0 0
  3.2: 0 1 1 1 1 0
  4.1: 0 0 1 0 1 0 0
  4.2: 0 1 1 1 1 0 0
  5.1: 1 1 0 1 1 1
  5.2: 0 0 1 0 1 1
acabar
```
**Informació del problema**

Autor : PR

Generaci ́o : 2017-05-18 17:55:

©Jutge.org, 2006–2017.

[http://jutge.org](http://jutge.org)


