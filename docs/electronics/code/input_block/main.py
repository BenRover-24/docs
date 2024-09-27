#pip3 install firebase-admin


import sys
import time

#les fichiers mpu_6050.py et ems_i2c_value.py du dossier includes sont des librairies que mains.py appel pour recuperer les valeurs
import includes.mpu_6050 as mpu_6050

import includes.ems_i2c_value as ems_i2c_value


import firebase_admin
from firebase_admin import credentials, db

# Chemin vers le fichier JSON téléchargé depuis Firebase
cred = credentials.Certificate('fir-e3207-firebase-adminsdk-jagwc-5d47461c40.json')#/home/pi/fir-e3207-firebase-adminsdk-jagwc-fa580f69b3.json
# Initialiser l'application Firebase
firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://fir-e3207-default-rtdb.firebaseio.com'
})

# Référence à la base de données
ref = db.reference('/')  # Remplace par le chemin approprié dans ta base de données


while True :
    ems_value_list = ems_i2c_value.ems_sensor_value(sys.argv) #appel de la fonction ems_sensor_value du fichier ems_i2c_value
    mpu_value_list = mpu_6050.mpu_value(sys.argv) #appel de la fonction mpu_value du fichier mpu_6050

    #recuperation de latemperatue et du niveau de charge du bloc d'alimentation
    ems_temperature = ems_value_list[0] 
    ems_battery_level = ems_value_list[1]


    #recuperation des valeurs envoyées par le MPU
    mpu_temperature = mpu_value_list[0]
    
    accel_x = mpu_value_list[1][0]
    accel_y = mpu_value_list[1][1]
    accel_z = mpu_value_list[1][2]

    gyro_x = mpu_value_list[2][0]
    gyro_y = mpu_value_list[2][1]
    gyro_z = mpu_value_list[2][2]

    #print(f"ems_temperature = {ems_temperature}")
    #print(f"mpu_temperature = {mpu_temperature}")

    #print(f"accel_x = {accel_x}")

    #print(f"gyro_x = {gyro_x}")


    # Envoi de données à Firebase
    data = {
        "battery": {
            "temperature": ems_temperature,
            "level": ems_battery_level
        },
        "sensors": {
            "temperature": mpu_temperature,
            "accelerometer": {
            "x": accel_x,
            "y": accel_y,
            "z": accel_z
            },
            "gyroscope": {
            "x": gyro_x,
            "y": gyro_y,
            "z": gyro_z
            }
        }
    }
    

    ref.set({
        'name': 'Raspberry Pi',
        'status': 'connected',
        'data' : data,


    })
    #time.sleep(5)

    print("Les données ont été envoyées à Firebase.")
    






