Algoritmo PartidosPoliticos 
    respuesta <- 'S'  // Inicializamos respuesta para el ciclo
    numCandidatos <- 3 // Número fijo de candidatos
    Dimensionar candidatos[numCandidatos]
    Dimensionar votos[numCandidatos, 5]
    Dimensionar totalVotos[numCandidatos]
    
    // Bucle para preguntar si quiere realizar otra elección
    Mientras respuesta = 'S' O respuesta = 's' Hacer
        // Reiniciar los totales de votos
        Para i <- 1 Hasta numCandidatos Hacer
            totalVotos[i] <- 0
        FinPara
		
        // Ingresar los nombres de los candidatos
        Para i <- 1 Hasta numCandidatos Hacer
            Escribir 'Ingrese el nombre del candidato ', i, ': '
            Leer candidatos[i]
        FinPara
        
        // Generar votos aleatorios para 5 rondas
        Para j <- 1 Hasta 5 Hacer
            Para i <- 1 Hasta numCandidatos Hacer
                votos[i, j] <- Aleatorio(0, 50)  // Generación aleatoria de votos entre 0 y 50
                totalVotos[i] <- totalVotos[i] + votos[i, j]  // Sumar votos de cada ronda
            FinPara
        FinPara
        
        // Mostrar la tabla de votos
        Escribir 'Tabla de votos:'
        Escribir ' Candidato  Ronda 1  Ronda 2  Ronda 3  Ronda 4  Ronda 5  Total '
        Para i <- 1 Hasta numCandidatos Hacer
            Escribir ' ', candidatos[i], '       ', votos[i, 1], '       ', votos[i, 2], '       ', votos[i, 3], '       ', votos[i, 4], '       ', votos[i, 5], '       ', totalVotos[i]
        FinPara
        
        // Determinar el candidato ganador y el perdedor
        maxVotos <- totalVotos[1]
        minVotos <- totalVotos[1]
        ganador <- 1
        perdedor <- 1
        
        Para i <- 2 Hasta numCandidatos Hacer
            Si totalVotos[i] > maxVotos Entonces
                maxVotos <- totalVotos[i]
                ganador <- i
            FinSi
            Si totalVotos[i] < minVotos Entonces
                minVotos <- totalVotos[i]
                perdedor <- i
            FinSi
        FinPara
        
        // Mostrar el ganador y el perdedor
        Escribir 'El candidato ganador es: ', candidatos[ganador], ' con ', maxVotos, ' votos.'
        Escribir 'El candidato con menos votos es: ', candidatos[perdedor], ' con ', minVotos, ' votos.'
        
        // Preguntar si el usuario desea realizar otra elección
        Escribir '¿Desea realizar otra elección? (S/N): '
        Leer respuesta
    FinMientras
FinAlgoritmo
