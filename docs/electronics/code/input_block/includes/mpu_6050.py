#installer la bibliotheque dans la conole : pip install mpu6050-raspberrypi

from mpu6050 import mpu6050
import sys
import time
#initialisation du MPU avec la librairie mpu6050
mpu = mpu6050(0x68)

#fonction permettant de recuperer les valeurs de temperature, accelerimetre, gyroscope, 
#cette fonction retourne une liste de ces valeurs
def mpu_value(args):
    
   try: 
      temp = mpu.get_temp()

      accel_data = mpu.get_accel_data()
      accel_x = accel_data['x']
      accel_y = accel_data['y']
      accel_z = accel_data['z']

      gyro_data = mpu.get_gyro_data()
      gyro_x = gyro_data['x']
      gyro_y = gyro_data['y']
      gyro_z = gyro_data['z']

      value = [temp, [accel_x, accel_y, accel_z,], [gyro_x, gyro_y, gyro_z, ]]
      print(value)
      #time.sleep(0.5)
      
      return value
   
   except KeyboardInterrupt:
      print("Programme arrêté manuellement")

    
#test automatique de la fonction mpu_value()
if __name__ == '__main__':
     try:
        mpu_value(sys.argv)
     except KeyboardInterrupt:
        print("program was stopped manually")
     input()