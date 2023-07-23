# driver_Drowsy_detection
Drowsiness detection is a safety technology that can prevent accidents that are caused by drivers who fell asleep while driving. To validate the proposed approach tests were conducted by using a variety of different images, such as the driver's face covered with a mask or glasses.

The proposed approach uses: Eye aspect ratio (EAR) to detect driver drowsiness in real-time. This is useful in situations when the drivers are used to the strenuous workload and drive continuously for long distances.

Methodology: The face is detected from a video stream using facial landmark detection and extract the eye regions. These facial landmarks are then used to compute the EAR and are returned back to the driver. In our context, the EAR value received at the application’s end would be compared with the threshold value taken as 0.25 If the EAR value is less than the threshold value, then this would indicate a state of fatigue. In case of Drowsiness, the driver and the passengers would be alerted by an alarm.

in this figure we will show the workflow of model: ![image](https://github.com/fatma-elshall/AutonomousSmartVehicle/assets/90958050/f1f6be24-bd06-4454-87d5-99e956969b11)

landmark-68 detection model: works by extracting the key of facial features and deals with eye closure detection, yawn detection. This model uses computer vision to observe the face, either using a built-in camera.

![image](https://github.com/fatma-elshall/AutonomousSmartVehicle/assets/90958050/818b2528-8ebc-4dd3-bb5e-a3dc732737f2)

The below figure shows the ratio in which we detect if the eyes are closed or opened.
![image](https://github.com/fatma-elshall/AutonomousSmartVehicle/assets/90958050/9a8abc5e-597f-422b-b1ec-635fd672ba39)

In terms of blink detection, we are only interested in two sets of facial structures in the eyes. Each eye is represented by 6 (x, y)-coordinates, starting at the left-corner of the eye (as if you were looking at the person), and then working clockwise around the remainder of the region.

Based on the last image Figure ,There is a relation between the width and the height of these coordinates represented in eye aspect ratio equation(EAR)
![image](https://github.com/fatma-elshall/AutonomousSmartVehicle/assets/90958050/b37b16ba-6cb8-492d-8125-97a0aa066255)

The numerator of this equation computes the distance between the vertical eye landmarks while the denominator computes the distance between horizontal eye landmark.

 this equation is so important as we’ll find out, the eye aspect ratio is approximately constant while the eye is open, but will rapidly fall to zero when a blink is taking place. Using this simple equation, we can avoid image processing techniques and simply rely on the ratio of eye landmark distances to determine if a person is blinking.

as shown in fig:![image](https://github.com/fatma-elshall/AutonomousSmartVehicle/assets/90958050/ea5347cb-6c20-47c0-ae99-5f727dcc2ca5)

On the top-left we have an eye that is fully open — the eye aspect ratio here would be large(r) and relatively constant over time. However, once the person blinks (top-right) the eye aspect ratio decreases dramatically, approaching zero.




