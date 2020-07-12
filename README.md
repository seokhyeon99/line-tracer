# line-tracer
   * The project is designed to move along the black line and avoid obstacles that appear in the middle of the running.
   * The line tracer car has two types of sensor; one is located at the bottom of the front to recognize light reflected to the floor and the other is front sensor that measure the distance to obstacle. 
        * Since the amount of light reflected to black floor is less than white floor, the sensor recognizes it and sets car to move toward black floor. However, there was a problem that speed of moving forward is slow with setting too many codes that changed the direction of the car. Therefore, I minimized codes switching direction to the extent that car is not out of line.
        * If the obstacle is 15cm ahead, the car is made to change direction, avoid the obstacle, and then return to the line.  

![line tracer](/line_tracer.gif) 
