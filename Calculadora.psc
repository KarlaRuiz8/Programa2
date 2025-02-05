Algoritmo Calculadora

		Definir operadorUno, operadorDos, opcionSeleccionada Como Entero
		Definir resultadoCalculadora Como Real
		Definir salidaMenu Como Caracter
		
		Repetir
			LimpiarPantalla
			Escribir "=== Calculadora ==="
			Escribir "1. Suma (+)"
			Escribir "2. Resta (-)"
			Escribir "3. Multiplicación (*)"
			Escribir "4. División (/)"
			Escribir "5. Residuo (%)"
			Escribir "Seleccione una opción: "
			Leer opcionSeleccionada
			
			Si opcionSeleccionada >= 1 Y opcionSeleccionada <= 5 Entonces
				Escribir "Ingrese el primer número: "
				Leer operadorUno
				Escribir "Ingrese el segundo número: "
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
							Escribir "Error: División por cero no permitida."
						FinSi
					Caso 5:
						Si operadorDos <> 0 Entonces
							resultadoCalculadora <- operadorUno MOD operadorDos
						Sino
							Escribir "Error: División por cero no permitida."
						FinSi
				FinSegun
				
				Si opcionSeleccionada <> 4 O operadorDos <> 0 Entonces
					Escribir "El resultado es: ", resultadoCalculadora
				FinSi
			Sino
				Escribir "Opción inválida. Intente de nuevo."
			FinSi
			
			Escribir "¿Desea realizar otra operación? (S/N): "
			Leer salidaMenu
		Hasta Que salidaMenu = 'N' O salidaMenu = 'n'
		
		Escribir "Gracias por usar la calculadora."
FinAlgoritmo


