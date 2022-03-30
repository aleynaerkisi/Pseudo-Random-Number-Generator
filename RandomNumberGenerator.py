#!/usr/bin/env python
# coding: utf-8

# In[42]:


import win32api
import time
import pyautogui








# mouse ın tıklandığı an ve tıklandığı pozisyonun x değerini çarpıp elde ettiği sayıyı file a basıyor

a=1
f = open("Seeds.txt", "a")
while a<7:
    check= win32api.GetKeyState(0x01) #mouse sol click virtual key kodu
    if check < 0:
        print("left button is clicked")
        mtime= round(time.time()) #tam bir sayıya yuvarlama
        x, y = pyautogui.position() #mouse ın pozisyonu     
        final=mtime*int(str(x).rjust(4)) #pozisyonu ve saati çarpıyor
        f.write(str(final)) #çarptığı sayıyı dosyaya basıyor
        f.write("\n") #her bastığı sayı sonrası satır boşluğu bırakıyor bu daha sonra cpp kodunda kolaylık olması için
        a+=1 #countı arttırıyor
        time.sleep(20) 
                      
f.close()






