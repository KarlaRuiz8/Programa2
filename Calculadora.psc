Algoritmo Calculadora

		Definir operadorUno, operadorDos, opcionSeleccionada Como Entero
		Definir resultadoCalculadora Como Real
		Definir salidaMenu Como Caracter
		
		Repetir
			LimpiarPantalla
			Escribir "=== Calculadora ==="
			Escribir "1. Suma (+)"
			Escribir "2. Resta (-)"
			Escribir "3. Multiplicaci�n (*)"
			Escribir "4. Divisi�n (/)"
			Escribir "5. Residuo (%)"
			Escribir "Seleccione una opci�n: "
			Leer opcionSeleccionada
			
			Si opcionSeleccionada >= 1 Y opcionSeleccionada <= 5 Entonces
				Escribir "Ingrese el primer n�mero: "
				Leer operadorUno
				Escribir "Ingrese el segundo n�mero: "
				Leer operadorDos
				
				Segun opcionSeleccionada Hacer
					Caso 1:
						resultadoCalculadora <- operadorUno + operadorDos
					Caso 2:
						resultadoCalculadora <- operadorUno - operadorDos
					Caso 3:
						resultadoCalculadora <- operadorUno * operadorDos
					Caso 4:
						Si operadorDos <> 0 Entonces
							resultadoCalculadora <- operadorUno / operadorDos
						Sino
							Escribir "Error: Divisi�n por cero no permitida."
						FinSi
					Caso 5:
						Si operadorDos <> 0 Entonces
							resultadoCalculadora <- operadorUno MOD operadorDos
						Sino
							Escribir "Error: Divisi�n por cero no permitida."
						FinSi
				FinSegun
				
				Si opcionSeleccionada <> 4 O operadorDos <> 0 Entonces
					Escribir "El resultado es: ", resultadoCalculadora
				FinSi
			Sino
				Escribir "Opci�n inv�lida. Intente de nuevo."
			FinSi
			
			Escribir "�Desea realizar otra operaci�n? (S/N): "
			Leer salidaMenu
		Hasta Que salidaMenu = 'N' O salidaMenu = 'n'
		
		Escribir "Gracias por usar la calculadora."
FinAlgoritmo


