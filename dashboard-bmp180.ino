import matplotlib.pyplot as plt
import requests

# função para obtenção de leituras do sensor
def get_sensor_data():
    # requisição para obtenção de dados
    response = requests.get("http://<ip_do_esp32>/sensor_data")
    # parse do conteúdo obtido
    data = response.json()
    # retorna os valores de pressão e temperatura
    return data['pressure'], data['temperature']

# função para plotar o gráfico
def plot_sensor_data(pressure, temperature):
    # inicialização do gráfico
    plt.ion()
    # plotagem dos dados
    plt.plot(pressure, temperature, '-o')
    # exibição do gráfico
    plt.show()

if __name__ == '__main__':
    # listas para armazenamento dos dados
    pressure_data = []
    temperature_data = []
    # laço de execução
    while True:
        # obtenção dos dados
        pressure, temperature = get_sensor_data()
        # adição dos dados nas listas
        pressure_data.append(pressure)
        temperature_data.append(temperature)
        # plotagem do gráfico
        plot_sensor_data(pressure_data, temperature_data)
