# Switch bounce
## About the project:
- To investigate switch bouncing and to cope with it in mbed - FRDM-KL25Z.
- While a switch from the outside world bounces many times when clicked/pushed, our ucontroller will only react to it when it settles on a steady-state.
- I used flags to define if the switch is still bouncing or not over time intervals of 2ms.
- Tflag: Time flag, will be set when the time interval of 2ms has expired.
- SWflag: Switch flag, will be set when Tflag is set up and switch is not bouncing anymore.

## Flags rising flowchart:
![image](https://user-images.githubusercontent.com/92950538/156506280-b688e624-a69c-4c12-8558-9f880b48abe9.png)


## What did I learn from it:
- Using Timers in mbed.h.
- Finding out the count of a changing event over time periods in C++.
- Printing messages from ucontroller to "Terraterm" on PC. 

## Final result:
- Blue trace: From the switch directly.
- Yellow trace: Our ucontroller reaction to the switch. 


![20220303_155946](https://user-images.githubusercontent.com/92950538/156876546-fa9cd7dc-55ac-4254-9985-6d0ffbb3d245.jpg)


https://user-images.githubusercontent.com/92950538/156876800-f69072cc-2fb4-49d2-9bad-b08f7a4bb5a6.mp4

