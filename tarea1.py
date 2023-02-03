"""
Benjamin Ortiz Morales
Estructura de datos
26/01/2023
8978145
"""

#Ejercicio 1

### Funcion: verificarDiagonales
### Entrada: Matriz cuadrada con numeros enteros
### Salida: Valor booleano
### Proposito: Determinar si la diagonal mayor y menor de una matriz cuadrada son iguales



def verificarDiagonales(mat):
	flag = True
	i = 0
	s2 = -1
	while i < len(mat) and flag:
		if mat[i][i] == mat[i][s2]:
			i += 1
			s2 -= 1
		else:
			flag = False
	return flag


#Ejercicio 2

### Funcion: esCapicua
### Entrada: Lista con numeros enteros
### Salida: valor booleano
### Proposito: Determinar si la lista se lee igual en ambos sentidos

def esCapicua(lista):
	i = 0
	s = -1
	flag = True
	while i < ((len(lista)/2) + 1) and flag:
		if lista[i] == lista[s]:
			i += 1
			s -= 1
		else:
			flag = False
	return flag



#Ejercicio 3

### Funcion: diferenciaListas
### Entrada: 2 listas(listaA, listaB), cada una contiene numeros enteros
### Salida: lista con numeros enteros
### Proposito: retornar una lista con numeros enteros que son la diferencia entre la listaA y listaB


#a

def diferenciaListas(listaA, listaB):
	ans = []
	for i in range(len(listaA)):
		if listaA[i] in listaB:
			listaB.remove(listaA[i])
		else:
			ans.append(listaA[i])
	return ans


#b

### Funcion: leerImprimir
### Entrada:
### Salida:
### Proposito: leer los datos ingresados e imprimirlos segun los lineamientos del problema

def leerImprimir():
	itera = int(input())
	for i in range(itera):
		lisA = []
		lisB = []
		listaA = input()
		listaB = input()
		listaA = listaA.split(" ")
		listaB = listaB.split(" ")
		for ubiA in range(1, int(listaA[0]) + 1):
			lisA.append(int(listaA[ubiA]))
		for ubiB in range(1, int(listaB[0]) + 1):
			lisB.append(int(listaB[ubiB]))
		ans = diferenciaListas(lisA, lisB)

		for w in range(len(ans)):
			if w < len(ans) - 1:
				print(ans[w],end=", ")
			else:
				print(ans[w],end="")
		print()

# Ejercicio 4


### Funcion: primos
### Entrada: numero entero
### Salida: lista con numeros enteros
### Proposito: determinar los numeros primos en el rango de numeros de entrada


def primos(numero):
	ans = []
	for num in range(2, numero +1):
		nume = 2
		flag = True
		cnt = 0
		while nume < numero and flag:
			if num >= nume:
				if num % nume == 0:
					cnt += 1
			else:
				flag = False
			if cnt > 1:
				flag = False
			nume += 1
		if cnt == 1:
			ans.append(num)
	return ans

### Funcion: sumaPrimos
### Entrada: lista de numeros enteros
### Salida: lista con numeros enteros
### Proposito: determinar si la suma de los digitos de la lista de entrada es prima

def sumaPrimos(primo):
	ans = []
	for elem in primo:
		numero = str(elem)
		suma = 0
		for i in range(len(numero)):
			suma += int(numero[i])
		nume = 2
		flag = True
		cnt = 0
		while nume < suma + 1 and flag:
			if suma % nume == 0:
				cnt += 1
			nume += 1
			if cnt > 1:
				flag = False
		if cnt == 1:
			ans.append(int(numero))
	return ans

### Funcion: mostrarPrimos
### Entrada: numero entero
### Salida: 
### Proposito: imprimir segun los lineamientos especificados en el problema los numeros

def mostrarPrimos(numero):
	primo = primos(numero)
	primoSumados = sumaPrimos(primo)
	print("Números primos entre 1 y %d:"%(numero))
	for i in range(len(primo)):
		if i < len(primo) - 1:
			print("--> %d,"%(primo[i]), end = "\n")
		else:
			print("--> %d"%(primo[i]), end = "\n")
	print()
	print("Números entre 1 y %d con suma de dígitos con valor primo:"%(numero))
	for m in range(len(primoSumados)):
		if m < len(primoSumados) - 1:
			print(primoSumados[m], end=", ")
		else:
			print(primoSumados[m], end="")
	print()


#Ejercicio 5

### Funcion: sumarvaloresMatriz
### Entrada: diccionario y matriz
### Salida: numero entero
### Proposito: determinar segun la clave y la posicion en el diccionario la suma de los valores que se encuentran segun la lista

def sumarValoresMatriz(disp, mat):
	cnt = 0
	for i in range(len(mat)):
		if mat[i][0] in disp:
			lista = disp[mat[i][0]]
			for m in range(len(lista)):
				if lista[m][0] == mat[i][1]:
					cnt += lista[m][1]
	return cnt
