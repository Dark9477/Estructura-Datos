"""
Benjamin Ortiz Morales
Estructura de datos
26/01/2023
8978145
"""

#Ejercicio 1

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

def sumarValoresMatriz(disp, mat):
	cnt = 0
	for i in range(len(mat)):
		if mat[i][0] in disp:
			lista = disp[mat[i][0]]
			for m in range(len(lista)):
				if lista[m][0] == mat[i][1]:
					cnt += lista[m][1]
	return cnt
