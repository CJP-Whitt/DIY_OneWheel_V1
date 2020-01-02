# OneWheel
Custom DIY OneWheel Electric Board. I decided to try to make an easy to follow guide on my one wheel process in hopes that everyone else doesn't have to go through the same pain as me in order to do their own DIY OneWheel. Very fun project with great opportunities for learning to engineer.

# Disclaimer!
Do your research! I do not take responsibility for any issues you may encounter during your build if you attempt to make a onewheel. It is difficult and there are many roadblocks you must engineer your way through. Learning comes through failure and troubleshooting so get used to it now if you plan on doing more projects in the future.

# Components
**Fundamental Components**
1. Flip32 Flight Controller: https://www.readytoflyquads.com/the-flip32
2. TORQUE ESC BLDC ELECTRONIC SPEED CONTROLLER (VESC-Motor Controller): https://diyelectricskateboard.com/products/torque-esc-bldc-electronic-speed-controller
3. 10inch 10 inch 10x6.00-5.5 wide tubeless tyre brushless gearless dc wheel hub motor (600W, 48V): https://www.aliexpress.com/item/32823573279.html?spm=a2g0o.productlist.0.0.72e6465ebj6ewY&algo_pvid=851b054b-e5d0-4ce6-a4b5-11497fe5d88c&algo_expid=851b054b-e5d0-4ce6-a4b5-11497fe5d88c-8&btsid=ef94e4fb-6a05-4494-a79c-043c26847dfc&ws_ab_test=searchweb0_0,searchweb201602_10,searchweb201603_55
4. Grip Tape (Get this anywhere that fits and has good reviews)
5. 13 18650 3.7 single cell batteries: (Get this anywhere that fits and has good reviews)
6. 48V 13s Battery Management System (BMS): https://vruzend.com/product/48v-13s-battery-management-system-bms/
7. VRUZEND battery kit V2.1 (Battery Clips): https://vruzend.com/product/vruzend-battery-kit-v2-0/
8. Adafruit Grand Central M4 Express featuring SAMD51: https://www.adafruit.com/product/4084
9. Solid state relay: https://www.amazon.com/TinaWood-SSR-25DD-Solid-State-5-200V/dp/B07F3WGRP4/ref=lp_6374820011_1_1_sspa?s=industrial&ie=UTF8&qid=1577918541&sr=1-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExVEZXTjRGWDJTTUdLJmVuY3J5cHRlZElkPUEwNzE0MTc2MzREV0NXVVVCWFVGOSZlbmNyeXB0ZWRBZElkPUEwNjc3Nzg1M0pLMFNLWVJLN0ZUVSZ3aWRnZXROYW1lPXNwX2F0Zl9icm93c2UmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl
10. 60v to 3v-32v step-down converter, preferably one with a flyback diode, you can get them everywhere and I got one on ebay
11. MPU6050 gyro, you can get these anywhere.

**Other Components*
1. HiLetgo HC-05 Wireless Bluetooth RF Transceiver: https://www.amazon.com/gp/product/B071YJG8DR/ref=ox_sc_act_title_1?smid=A30QSGOJR8LMXA&psc=1
2. Pressure-Sensitive Conductive Sheet: https://www.adafruit.com/product/1361
3. Aluminum Rectangular Hollow Tube 2" x 1" https://store.buymetal.com/aluminum/rectangular-tube/6061-t6-t6511/aluminum-rectangular-tube-6061-t6511-2-1-0.125.html
4. Switch, I used an aircraft style switch because they look cool...but any will work as long as it works with the output voltage of your voltage step-down converter. In my case it was 12v
5. If you are doing the arduino method you need another voltage step-down from 48ish volts to 5v to power your arduino board
6. I suggest using JST Connectors!!! It's super cheap to get on Amazon and will help you undo your mistakes much easier

# Build Info
- 48v 13s 2p Battery Pack
- (Easy) Vesc open source balancing tool
- (Hard) Arduino self made balancing

### Step One: The frame
I have created a CAD file (Uses Fusion 360 which is FREE!) for the frame if you want to follow my process, but generally you need two rails that will hold the wires going from the battery compartment to your other component and mounts for connecting the motor axle to to your rails. If you are machinist this will be fairly easy, but if not I suggest you have someone else do this part. My CAD files provides the general outline but you need to deicide how you want to do your own motor mounts.
![alt test](OneWheel%20Photos/Rail_IsoView.jpg)
![alt test](OneWheel%20Photos/Rail_TestFit.jpg)
- Two rails
- Motor mounts (I attached straight to rails with slot lock washer that comes with the wheel. Still working!)
- Holes on top of rails to attach component trays and foot pads
- I would suggest getting the rails extra long just in case you need larger component trays than you first thought, you can cut them later

Here is the rail after I finshed and put my switch and stuff in. The yellow male connector is wired for charging to the bms and pack.
![alt test](OneWheel%20Photos/Rail_Finished.jpg)

### Step Two: Battery Pack
I would suggest that if you are unfamiliar with batteries you do some research prior to building your packs. Essentially I built two 13 cell packs and ran them parralel, but it's not appearent from my final photo because I did some wiring magic to make more space in my battery tray.
![alt test](OneWheel%20Photos/Batt_OldSeriesPack.jpg)
![alt test](OneWheel%20Photos/Batt_Finished.jpg)
- 26 18650 3.7 cells total
- 13 cells in series (x2)
- Put both those packs in parralel
- (You could do this with 13 cells and just make one pack if you really want, it will have the same voltage, but I wanted more amp-hours)
- Look at the wiring guide for your battery management system (BMS) and wire accordingly. In my case I soldered 1 balancing wire to each two cell grou wired in series for a total of 13 wires. Then I connected the + and - wires to their respective locaitons.

### Step Three: Component Wiring
At this point in the project I 3D printed two trays to hold my batteries and components. I also printed a plate to hold all of my non battery components, all these components are in the OneWheel frame CAD file.
![alt test](OneWheel%20Photos/Wiring_Plate.jpg)

Here is a general wiring diagram for the OneWheel. Sorry for how unprofesional it is. Keep in mind if you are using something besides the VESC balancing app you need to wire the board in between the vesc and relay.
![alt test](OneWheel%20Photos/Wiring_Drawing.jpg)


Here is a photo of the hall sensor connection to the VESC, from left to right in the pic it goes 5v,Temp,H3,H2,H1,GND
Im pretty sure the order of hall sensors doesnt matter, if it doesnt work in vesc than just switch two and it should.
Same goes for the phase wires (The 3 bullet connectors coming from the motor).
The motor listed in the parts section does not have a temp wire so leave that pin empty.
![alt test](OneWheel%20Photos/Wiring_Hall.jpg)

This is the wiring for the MPU6050...
![alt test](OneWheel%20Photos/Wiring_MPU.jpg)

And its connection to the VESC, its the connector on the right side of the picture.
The spots left empty in the JST connector are for wiring the footpads, I will go over that later.
![alt test](OneWheel%20Photos/Wiring_VescMPU.jpg)

