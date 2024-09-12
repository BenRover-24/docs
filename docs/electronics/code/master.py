#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import smbus2 as smbus
import time
import struct

# Adresse de l'esclave (Arduino)
I2C_SLAVE_ADDRESS = 14
'''
# Fonction pour convertir un float en tableau d'octets
def ConvertFloatToBytes(value):
    return list(struct.pack('f', value))
'''
# Fonction pour convertir un tableau d'octets en float
def ConvertBytesToFloat(data):
    return struct.unpack('f', bytearray(data))[0]
'''
# Fonction pour envoyer les données des capteurs à l'Arduino
def send_sensor_data(I2Cbus, address, sensor_values):
    num_sensors = len(sensor_values)
    I2Cbus.write_byte(address, num_sensors)  # Envoi du nombre de capteurs

    for value in sensor_values:
        sensor_bytes = ConvertFloatToBytes(value)
        I2Cbus.write_i2c_block_data(address, 0x00, sensor_bytes)
        time.sleep(0.1)
'''
# Fonction pour recevoir les données des capteurs de l'Arduino
def receive_sensor_data(I2Cbus, address, num_sensors):
    
    float_size = 4
    data_size = float_size  * num_sensors
    data = I2Cbus.read_i2c_block_data(address, 0x00, data_size)
    
    # Chaque float est de 4 octets
    
    received_data = []
    print(data)
    #for i in range(num_sensors):
    for i in range(num_sensors):
        start_index = i * float_size
        end_index = start_index + float_size
        #sensor_value = struct.unpack('f', data[start_index:end_index])[0]
        sensor_value = ConvertBytesToFloat(data[start_index:end_index])
        received_data.append(sensor_value)

    return received_data
        #data = I2Cbus.read_i2c_block_data(address, 0x00, float_size)
        #print(f'data {data}')
        #sensor_value = ConvertBytesToFloat(data)
        #print(sensor_value)
        #received_data.append(sensor_value)
        

    return received_data

def main(args):
    I2Cbus = smbus.SMBus(1)

    try:
        while True:
            '''# 1. Envoi de données de capteurs à l'Arduino
            sensor_values = [12.34, 25.50, 18.75]  # Exemple de données à envoyer
            print(f"Envoi de {len(sensor_values)} capteurs à l'Arduino...")
            send_sensor_data(I2Cbus, I2C_SLAVE_ADDRESS, sensor_values)
            time.sleep(2)'''

            # 2. Demande de données des capteurs de l'Arduino
            num_sensors_to_receive = 2  # Nombre de capteurs attendus de l'Arduino
            print(f"Demande des données des capteurs Arduino ({num_sensors_to_receive})...")

            sensor_values_from_arduino = receive_sensor_data(I2Cbus, I2C_SLAVE_ADDRESS, num_sensors_to_receive)
            print("Données reçues de l'Arduino :", sensor_values_from_arduino)
            temperature = sensor_values_from_arduino[0]
            batterie = sensor_values_from_arduino[1]

            time.sleep(5)

    except KeyboardInterrupt:
        print("Programme arrêté manuellement")



if __name__ == '__main__':
     try:
        main(sys.argv)
     except KeyboardInterrupt:
        print("program was stopped manually")
     input()
