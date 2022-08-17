# TurtleBot3
Este es un repositorio para la asignatura "Funamentos de Robótica Móvil" para la instalación y simulación empleando el robot [TurtleBot3](https://emanual.robotis.com/docs/en/platform/turtlebot3/overview/)

## Requisitos de software
* Ubuntu [16.04](https://releases.ubuntu.com/16.04/) o [18.04](https://releases.ubuntu.com/18.04/)
* ROS [Kinetic](http://wiki.ros.org/kinetic) o [Melodic](http://wiki.ros.org/melodic)

## Instalación
### Instalación de paquetes:
```bat
sudo apt-get update
sudo apt-get install ros-melodic-turtlebot3
sudo apt-get install ros-melodic-turtlebot3-applications
sudo apt-get install ros-melodic-turtlebot3-simulations
sudo apt-get install ros-melodic-turtlebot3-gazebo
sudo apt-get install ros-melodic-turtlebot3-teleop
sudo apt-get install ros-melodic-turtlebot3-example
```

### Crear la carpeta catkin_ws
Si aun se configura el espacio de trabajo catkin puede hacerse de la siguiente manera:
```
cd
mkdir catkin_ws
cd ~/catkin_ws/
mkdir src
cd ..
catkin_make
```
### Incluir repositorios
En la carpeta ~/catkin_ws/src
```
git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
git clone https://github.com/ROBOTIS-GIT/turtlebot3.git
cd ~/catkin_ws && catkin_make
```
### Configurar archivo .bashrc
```
cd
gedit .bashrc
```
En el archivo .bashrc incluir las siguientes líneas:
* export TURTLEBOT3_MODEL=burger
* source /home/"TU_USUARIO"/catkin_ws/devel/setup.bash

## Comprobando la instalación del TurtleBot3
* En una de las pestañas de la consola lanzar el ros master con la instrucción roscore
* En otra pestaña lanzar el robot con un mundo gazebo con alguna de las siguientes opciones:
    * roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch
    * roslaunch turtlebot3_gazebo turtlebot3_world.launch
* En otra pestaña lanzar el nodo que conecta con rviz: roslaunch turtlebot3_fake turtlebot3_fake.launch
* En otra pestaña lanzar el teleop para mover el robot en el entorno de simulación:
roslaunch turtlebot3_teleop turtlebot3_teleop_key.launch
