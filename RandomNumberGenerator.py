#!/usr/bin/env python
# coding: utf-8

# In[42]:


import win32api
import time
import pyautogui


# In[47]:


#test amaçlı
#mouse ın tıklandığı an ve tıklandığı pozisyonu basan program
x=1
f = open("C:/Users/aleyn/Desktop/mouse1.txt", "a")
while x<10:
    check= win32api.GetKeyState(0x01)
    if check < 0:
        print("left button is clicked")
        mtime= round(time.time()) #tam bir sayıya yuvarlıyor ki noktalı olmasın sayı
        f.write(str(mtime)) #mouse basılan saati milisaniye cinsinden dosyaya yazıyor
        f.write(" ")
        f.write(str(pyautogui.position())) #mouse ın pozisyonunu basıyor
        f.write("\n")
        x+=1
        time.sleep(0.1) #basılı tutarken sürekli basmaması için burayı arttır 5 falan yeterli fazla bile
f.close()


# In[48]:


#test amaçlı
# mouse ın tıklandığı an ve tıklandığı pozisyonun x değerini basıyor

a=1
f = open("C:/Users/aleyn/Desktop/mouse1Updated.txt", "a")
while a<10:
    check= win32api.GetKeyState(0x01)
    if check < 0:
        print("left button is clicked")
        mtime= round(time.time()) #tam bir sayıya yuvarlıyor ki noktalı olmasın sayı
        x, y = pyautogui.position() #mouse ın pozisyonu     
        f.write(str(mtime)) #mouse basılan saati milisaniye cinsinden dosyaya yazıyor
        f.write(" ")
        f.write(str(x).rjust(4)) #mouse ın pozisyonunun x eksenindeki değerini basıyor
        f.write("\n")
        a+=1
        time.sleep(0.1) #basılı tutarken sürekli basmaması için burayı arttır 5 falan yeterli fazla bile
f.close()


# In[49]:


#son kod
# mouse ın tıklandığı an ve tıklandığı pozisyonun x değerini çarpıp elde ettiği sayıyı basıyor

a=1
f = open("C:/Users/aleyn/Desktop/randomNumbers.txt", "a")
while a<100:
    check= win32api.GetKeyState(0x01) #mouse sol click virtual key kodu
    if check < 0:
        print("left button is clicked")
        mtime= round(time.time()) #tam bir sayıya yuvarlıyor ki noktalı olmasın sayı
        x, y = pyautogui.position() #mouse ın pozisyonu     
        final=mtime*int(str(x).rjust(4)) #pozisyonu ve saati çarpıyor
        f.write(str(final)) #çarpptığı sayıyı dosyaya basıyor
        f.write("\n") #her bastığı sayı sonrası satır boşluğu bırakıyor bu daha sonra cpp kodunda kolaylık olması için
        a+=1 #countı arttırıyor
        time.sleep(20) #basılı tutarken sürekli basmaması için burayı arttır 20 yeterli şimdilik 7 sayı alacağım için
                      #random olmasını istiyorum
f.close()


# In[ ]:




