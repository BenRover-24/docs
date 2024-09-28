#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import smbus2 as smbus
import time
import struct

# Adresse de l'esclave (Arduino nano)
I2C_SLAVE_ADDRESS = 14

# Fonction pour convertir un tableau d'octets en float
def ConvertBytesToFloat(data):
    return struct.unpack('f', bytearray(data))[0]

# Fonction pour recevoir les données des capteurs de l'Arduino nano
def receive_sensor_data(I2Cbus, address, num_sensors):
    
    float_size = 4 #chaque valeur est coder sur 4 octets et l'arduino nano envoie deux valeurs(temperature et niveau de charge)
    data_size = float_size  * num_sensors # 4 * 2 = 8 octets
    data = I2Cbus.read_i2c_block_data(address, 0x00, data_size) #reception des donnees
    
    # Chaque float est de 4 octets
    
    received_data = []
    print(data)
    
    #parcourir chaque 4 octets et les convertir en decimal pour recuperer les valeurs des capteurs
    for i in range(num_sensors):
        start_index = i * float_size
        end_index = start_index + float_size
        
        sensor_value = ConvertBytesToFloat(data[start_index:end_index])
        received_data.append(sensor_value)

    #retourne une liste des valeurs 
    return received_data
     

def ems_sensor_value(args):
    #initialisation du busi2c pour le communication par i2c
    I2Cbus = smbus.SMBus(1)

    try:

        # Demande de données des capteurs de l'Arduino
        num_sensors_to_receive = 2  # Nombre de capteurs attendus de l'Arduino nano
        print(f"Demande des données des capteurs Arduino ({num_sensors_to_receive})...")

        sensor_values_from_arduino = receive_sensor_data(I2Cbus, I2C_SLAVE_ADDRESS, num_sensors_to_receive) #affectation des données dans sensor_values_from_arduino
        print("Données reçues de l'Arduino :", sensor_values_from_arduino)
        #separation desdonnées
        temperature = sensor_values_from_arduino[0]
        batterie = sensor_values_from_arduino[1]

        value = [temperature, batterie]
        #time.sleep(0.5)

        return value

    except KeyboardInterrupt:
        print("Programme arrêté manuellement")


#test automatique de la fonction ems_sensor_value()
if __name__ == '__main__':
     try:
        ems_sensor_value(sys.argv)
     except KeyboardInterrupt:
        print("program was stopped manually")
     input()
