import random


def gen_km_antes():
    return random.randint(250, 380)


# Diccionarió que tendrá todos los dias con los taxis
semana = {}
# Ciclo que recorre los 7 dias de la semana
for dia in range(1, 8):
    taxis = []
    # Ciclo [a,b) para generar los kilometros recorridos para cada taxi
    for i in range(1, 11):
        # Se asigna el km inical llamando a la función
        taxis.append(gen_km_antes())
    # Se añade al diccionario un dia como clave y los taxis como valor
    semana["Dia"+str(dia)] = taxis

# Imprime la semana generada aleatoriamente
print("\n### Semana generada aleatoriamente ###")
for dia in semana:
    print("{} Taxis: {}".format(dia, semana[dia]))

# Punto 3
# Lisa donde se añaden la cantidad de km recorridos por cada taxi
acumulados = []
cant_taxis_350 = 0
# Ciclo para acumular los kilometros de cada taxi en la semana
for taxi in range(10):
    # reicinia el acumulador por cada taxi
    ac = 0
    # recorre el diccionario con los 7 dias de la semana
    for dia in semana:
        ac = ac + semana[dia][taxi]
    # Añade el acumulado para semanal de cada taxi
    acumulados.append(ac)

print("\n ### Acumulado por taxi: {}  ### \n".format(acumulados))
movil = 0
# El movil del taxi que menos km recorre diariamente
movil_diario = 0
# Función para sacar el mayor de una lista (viene incluida en python)
mayor = max(acumulados)
print("\n ### Punto 3 ###")
for i in range(10):
    prom_taxi = acumulados[i] / 7
    # División entera
    cambio_aceite_dias = 5000 // prom_taxi
    print("El Taxi{} debe cambiar su aceite a los {} días".format(
        i+1, cambio_aceite_dias))
    if acumulados[i] == mayor:
        # Se le suma 1 porque el indice de las listas comienza en 0
        movil = i+1

# El menor inicialmente es el primero en la lista de acumulados
menor_diario = acumulados[0] / 7
for i in range(10):
    prom_diario = acumulados[i]/7
    if(prom_diario < menor_diario):
        menor_diario = prom_diario
        movil_diario = i+1


# Punto 4
print("\n ### Punto 4 ### ")
for dia in semana:
    # Reinicia la cantidad de taxis por cada día de la semana
    cant_taxis_350 = 0
    for i in range(10):
        if semana[dia][i] > 350:
            cant_taxis_350 = cant_taxis_350 + 1
    porcentaje = (cant_taxis_350 / 10) * 100
    print("El porcentaje de taxis que recorrieron más de 350km en el {} es: {}%".format(
        dia, int(porcentaje)))

print("\n ### Punto 1 ### ")
print("El movil del Taxi que ha realizado el mayor recorrido durante la semana es: {} ".format(movil))
print("\n ### Punto 2 ###")
print("El movil del taxi que ha realizado el menor recorrido diariamente es el: {} ".format(movil_diario))
